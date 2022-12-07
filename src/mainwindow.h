#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "devwindow.h"
#include "sniffer.h"
#include <QMainWindow>

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

private:
  Ui::MainWindow *ui;
  Sniffer *sniffer;
  DevWindow *devwindow;
};

#endif // MAINWINDOW_H
