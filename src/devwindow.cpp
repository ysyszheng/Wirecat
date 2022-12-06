#include "devwindow.h"

DevWindow::DevWindow(Sniffer *snifferObj, QWidget *parent)
    : QDialog(parent), ui(new Ui::DevWindow) {
  ui->setupUi(this);
  sniffer = snifferObj;
  addDev();
}

DevWindow::~DevWindow() { delete ui; }

void DevWindow::addDev() {
  ui->devchoice->setEditable(true);
  for (auto &i : sniffer->allDev_vec) {
    ui->devchoice->insertItem(-1, i->name);
  }
}

void DevWindow::on_pushButton_clicked() {
  sniffer->dev = ui->devchoice->currentText().toLocal8Bit().constData();
  // std::cout << sniffer->dev << std::endl;
}