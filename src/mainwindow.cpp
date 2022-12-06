#include "mainwindow.h"
// #include "listview.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
  setWindowTitle(tr("Wirecat"));

//   view = new ListView();

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
