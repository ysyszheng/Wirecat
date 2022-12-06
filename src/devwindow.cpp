#include "devwindow.h"

DevWindow::DevWindow(Sniffer *snifferObj, QWidget *parent)
    : QDialog(parent), ui(new Ui::DevWindow) {
  sniffer = snifferObj;
  QGridLayout *grid = new QGridLayout;
  QPushButton *PB = new QPushButton("Enjoy Sniff!");
  connect(PB, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
  QGroupBox *devChoice = creatDevChoice();
  grid->addWidget(devChoice, 0, 0);
  grid->addWidget(PB, 1, 0);
  setLayout(grid);

  setWindowTitle(tr("Select Network Device"));
  resize(480, 320);
}

DevWindow::~DevWindow() { delete ui; }

QGroupBox *DevWindow::creatDevChoice() {
  QGroupBox *groupBox = new QGroupBox();
  QRadioButton *radioButton;
  std::vector<QRadioButton *> radio;
  for (auto &i : sniffer->allDev_vec) {
    radioButton = new QRadioButton(tr(i->name));
    radio.push_back(radioButton);
    connect(radioButton, &QRadioButton::toggled, this, &DevWindow::onToggled);
  }
  radio[0]->setChecked(true);

  QVBoxLayout *vbox = new QVBoxLayout;
  for (auto &i : radio) {
    vbox->addWidget(i);
  }
  vbox->addStretch(1);
  groupBox->setLayout(vbox);

  return groupBox;
}

void DevWindow::onToggled(bool checked) {
  if (checked) {
    selected = static_cast<QRadioButton *>(sender());
  }
}

void DevWindow::pushButtonClicked() {
  sniffer->dev = selected->text().toLocal8Bit().constData();
  std::cout << "@: " << sniffer->dev << std::endl;
  this->close();
}