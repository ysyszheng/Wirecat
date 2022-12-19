#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "devwindow.h"
#include "sniffer.h"
#include "ui_mainwindow.h"
#include "utils/utils.h"
#include "view.h"
#include "filter.h"

namespace Ui {
class MainWindow;
}
class Filter;

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

  void on_filter_textChanged(const QString &arg1);
  void on_Filter_Pressed();

signals:
  void sig();

private:
  Ui::MainWindow *ui;
  // sniffer
  Sniffer *sniffer;
  // catch thread
  QThread *cthread;
  // dev choice window
  DevWindow *devwindow;
  // views
  View *view;
  // menuBar
  void setMenuBar(QMenuBar *mBar);
  // filter
  Filter *filter;
};

#endif // MAINWINDOW_H
