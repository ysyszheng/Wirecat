#ifndef DEVWINDOW_H
#define DEVWINDOW_H

#include "sniffer.h"
#include "./utils/utils.h"
#include "ui_devwindow.h"
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <cstdlib>

class QDialog;

namespace Ui {
class DevWindow;
}

class DevWindow : public QDialog {
  Q_OBJECT
public:
  explicit DevWindow(Sniffer *snifferObj, QWidget *parent = nullptr);
  ~DevWindow();

private slots:
  // void on_choiceBox_activated(const QString &arg1);
  void on_pushButton_clicked();

private:
  Ui::DevWindow *ui;
  Sniffer *sniffer;

  void addDev();
  // void showDevInfo();
};

#endif // DEVWINDOW_H