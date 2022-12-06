#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  setWindowTitle(tr("Wirecat"));

  ui->setupUi(this);
  sniffer = new Sniffer();
  devwindow = new DevWindow(sniffer, this);


  QMenuBar *mBar = menuBar();

  QMenu *pFile = mBar->addMenu("Files");

  QAction *pOpen = pFile->addAction("Open");
  connect(pOpen, &QAction::triggered, [=]() { qDebug() << "Open"; });

  pFile->addSeparator();

  QAction *pSave = pFile->addAction("Save");

  connect(pSave, &QAction::triggered, [=]() { qDebug() << "Save"; });

  pFile->addSeparator();

  QAction *pNewSave = pFile->addAction("Save as");

  connect(pNewSave, &QAction::triggered, [=]() { qDebug() << "Save as"; });
}

MainWindow::~MainWindow() { delete ui; }
