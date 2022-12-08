#include "mainwindow.h"
#include "qaction.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  // Ui config
  ui->setupUi(this);
  QMenuBar *mBar = menuBar();
  setMenuBar(mBar);
  setWindowTitle(tr("Wirecat"));

  // variables
  sniffer = new Sniffer();
  // cthread = new CThread(sniffer);

  // Device choice
  DevWindow *devwindow = new DevWindow(sniffer, this);
  devwindow->show();
  connect(devwindow, SIGNAL(subWndClosed()), this, SLOT(showMainWnd()));

  // main window layout
  // view->pktInfo = ui->tableView;
  // view->hdrInfo = ui->treeView;
  // view->pktContent = ui->textBrowser;
}

MainWindow::~MainWindow() { delete ui; }

// SLOT function
void MainWindow::showMainWnd() {
  this->show();
  // cthread->start();
}

void MainWindow::start_catch() {
  LOG("Start");
  // cthread->flag = Start;
}

void MainWindow::stop_catch() {
  LOG("Stop");
  // cthread->flag = Stop;
}

void MainWindow::restart_catch() {
  LOG("Restart");
  // cthread->flag = Restart;
}

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