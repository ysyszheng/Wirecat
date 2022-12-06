#include "devwindow.h"

DevWindow::DevWindow(Sniffer *snifferObj,QWidget *parent):QDialog(parent), ui(new Ui::DevWindow)
{
  ui->setupUi(this);
  sniffer=snifferObj;
  addDev();
}

DevWindow::~DevWindow(){
  delete ui;
}

void DevWindow::addDev(){
  ui->choiceBox->setEditable(true);
  for(auto &i:sniffer->allDev_vec){
    ui->choiceBox->insertItem(-1, i->name);
  }
}

void DevWindow::on_buttonBox_clicked(){
  sniffer->dev = ui->choiceBox->currentText();
}