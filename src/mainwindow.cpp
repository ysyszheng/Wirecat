#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowTitle(tr("Sniffer X"));

  // 添加菜单栏
  QMenuBar *mBar =
      menuBar(); //返回主窗口的菜单栏。如果菜单栏不存在，此函数将创建并返回一个空菜单栏。

  // 菜单栏上添加一个 "文件" 的菜单
  QMenu *pFile = mBar->addMenu("Files");

  //添加 "打开" 菜单项
  QAction *pOpen = pFile->addAction("Open");
  connect(pOpen, &QAction::triggered, [=]() { qDebug() << "打开按下"; });

  pFile->addSeparator(); //添加分割线

  QAction *pSave = pFile->addAction("Save"); //添加 "保存" 菜单项动作

  // 新建菜单选项的触发动作信号和槽 使用Lambda表达式的匿名槽函数
  connect(pSave, &QAction::triggered, // "保存" 按下后的动作打印信息
          [=]() { qDebug() << "保存按下"; });

  pFile->addSeparator(); //添加分割线

  QAction *pNewSave = pFile->addAction("Save as"); //添加 "另存为" 菜单项动作

  // 新建菜单选项的触发动作信号和槽 使用Lambda表达式的匿名槽函数
  connect(pNewSave, &QAction::triggered, // "另存为" 按下后的动作打印信息
          [=]() { qDebug() << "另存为按下"; });
}

MainWindow::~MainWindow() { delete ui; }
