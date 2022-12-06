#ifndef DEVWINDOW_H
#define DEVWINDOW_H

#include "./utils/utils.h"
#include "sniffer.h"
#include "ui_devwindow.h"
#include <QDebug>
#include <QDialog>
#include <QGroupBox>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
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
  void pushButtonClicked();
  void onToggled(bool checked);

private:
  Ui::DevWindow *ui;
  Sniffer *sniffer;
  QGroupBox *devChoice;
  QRadioButton *selected;
  QGroupBox *creatDevChoice();
};

#endif // DEVWINDOW_H