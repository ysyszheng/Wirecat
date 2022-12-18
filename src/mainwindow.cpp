#include "mainwindow.h"
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  // Ui config
  ui->setupUi(this);
  QMenuBar *mBar = menuBar();
  setMenuBar(mBar);
  setWindowTitle(tr("Wirecat"));

  QTableView *table = ui->tableView;
  QTextBrowser *text = ui->textBrowser;
  QTreeView *tree = ui->treeView;
  view = new View(table, text, tree);

  filter = new Filter();

  // variables
  sniffer = new Sniffer();
  sniffer->getView(view);

  // Device choice
  DevWindow *devwindow = new DevWindow(sniffer, this);
  devwindow->show();
  connect(devwindow, SIGNAL(subWndClosed()), this, SLOT(showMainWnd()));

  cthread = new QThread;
  sniffer->moveToThread(cthread);
  cthread->start();
  connect(this, SIGNAL(sig()), sniffer, SLOT(sniff()));
}

MainWindow::~MainWindow() { delete ui; delete filter; }

// SLOT function
void MainWindow::showMainWnd() {
  LOG(sniffer->dev);
  char errbuf[PCAP_ERRBUF_SIZE];
  sniffer->handle = pcap_open_live(sniffer->dev, BUFSIZ, -1, 1000, errbuf);
  if (sniffer->handle == NULL) {
    ERROR_INFO(errbuf);
    exit(1);
  }

  emit sig();
  this->show();
}

void MainWindow::start_catch() {
  LOG("Start");
  sniffer->status = Start;
}

void MainWindow::stop_catch() {
  LOG("Stop");
  sniffer->status = Stop;
}

void MainWindow::restart_catch() {
  LOG("Restart");
  sniffer->status = Restart;
}

// void MainWindow::on_tableView_clicked(const QModelIndex &index)
// {
//     view->packetInfoByIndex(index);
// }

// Menu
void MainWindow::setMenuBar(QMenuBar *mBar) {
  QMenu *pFile = mBar->addMenu("Files");
  QAction *pOpen = pFile->addAction("Open");
  connect(pOpen, &QAction::triggered, [=]() { qDebug() << "Open"; });
  pFile->addSeparator();
  QAction *pSave = pFile->addAction("Save");
  connect(pSave, &QAction::triggered, [=]() { qDebug() << "Save"; });
  pFile->addSeparator();
  QAction *pNewSave = pFile->addAction("Save as");
  connect(pNewSave, &QAction::triggered, [=]() { qDebug() << "Save as"; });

  // QMenu *pRun = mBar->addMenu("Run");
  QAction *pStart = mBar->addAction("Start");
  connect(pStart, &QAction::triggered, this, &MainWindow::start_catch);
  QAction *pStop = mBar->addAction("Stop");
  connect(pStop, &QAction::triggered, this, &MainWindow::stop_catch);
  QAction *pRestart = mBar->addAction("Restart");
  connect(pRestart, &QAction::triggered, this, &MainWindow::restart_catch);

  QMenu *pRe = mBar->addMenu("Reassemble");
  QAction *pIPre = pRe->addAction("IP Reassemble");
  connect(pIPre, &QAction::triggered, [=]() { qDebug() << "IP Reassemble"; });
  pRe->addSeparator();
  QAction *pFre = pRe->addAction("File Reassemble");
  connect(pFre, &QAction::triggered, [=]() { qDebug() << "File Reassemble"; });
}


/* 
 * filter control functions 
 * when text changes, check the syntax.
 * when Filter button is pressed.
 */

/*
void MainWindow::on_filter_textChanged(const QString &command)
{
    QPalette palette;
    if (filter->checkCommand(command)) {
        palette.setColor(QPalette::Base, Qt::green);
    }
    else {
        palette.setColor(QPalette::Base, Qt::red);
    }
    ui->filter->setPalette(palette);
}
*/
/*
void MainWindow::on_Filter_Pressed()
{
    if (ui->filter->text() == tr("-h")) {
        QMessageBox::about(this, tr("The Usage of filter"), tr("[-options] [data to query]\n"
                                                                     "-h help\n-p protocol\n-s sourceIP\n-d destinationIP /"
                                                                 " -sport sourcePort\n-dport destinationPort\n-c packetContent"));
        return;
    }
    filter->loadCommand(ui->filter->text());
    filter->printQuery();
    filter->launchFilter(view);
}
*/