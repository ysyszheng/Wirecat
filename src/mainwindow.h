#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cthread.h"
#include "devwindow.h"
#include "sniffer.h"
#include "ui_mainwindow.h"
#include "utils/utils.h"
#include "view.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void showMainWnd();
  void start_catch();
  void stop_catch();
  void restart_catch();

private:
  Ui::MainWindow *ui;
  // sniffer
  Sniffer *sniffer;
  // catch thread
  CThread *cthread;
  // dev choice window
  DevWindow *devwindow;
  // views
  View *view;
  // menuBar
  void setMenuBar(QMenuBar *mBar);
};

#endif // MAINWINDOW_H
