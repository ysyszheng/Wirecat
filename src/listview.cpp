#include "listview.h"
#include <iostream>

ListView::ListView(QTableView *v) {
  view = v;
  mainModel = new QStandardItemModel();
  mainModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("NO.")));
  mainModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Time")));
  mainModel->setHorizontalHeaderItem(2,
                                     new QStandardItem(QObject::tr("Source")));
  mainModel->setHorizontalHeaderItem(
      3, new QStandardItem(QObject::tr("Destination")));
  mainModel->setHorizontalHeaderItem(
      4, new QStandardItem(QObject::tr("Protocol")));
  mainModel->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("Size")));
  mainModel->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("Info")));

  view->setModel(mainModel);
  view->setColumnWidth(0, 90);
  view->setColumnWidth(1, 150);
  view->setColumnWidth(2, 200);
  view->setColumnWidth(3, 200);
  view->setColumnWidth(4, 100);
  view->setColumnWidth(5, 100);
  vien->setColumnWidth(6, 300);

  view->horizontalHeader()->resizeSections(QHeaderView::ResizeMode::Fixed);
  view->verticalHeader()->hide();
  view->setSelectionBehavior(QAbstractItemView::SelectRows);
  view->setSelectionMode(QAbstractItemView::SingleSelection);
  view->setTextElideMode(Qt::ElideMiddle);
  view->setEditTriggers(QAbstractItemView::NoEditTriggers);

  index = 0;
}

ListView::~ListView() { clearData(); }

/* Clear all data */
void ListView::clearData() {
  if (status.size() > 0)
    status.clear();
  if (fileFlow.size() > 0)
    fileFlow.clear();
  if (packets.size() > 0)
    packets.clear();

  index = 0;
  reBuildInfo();
}

/*
 * reBuildInfo()
 * delete all items in tableView
 */
void ListView::reBuildInfo() {
  mainModel->clear();
  // set tableview
  mainModel = new QStandardItemModel();
  mainModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("NO.")));
  mainModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Time")));
  mainModel->setHorizontalHeaderItem(2,
                                     new QStandardItem(QObject::tr("Source")));
  mainModel->setHorizontalHeaderItem(
      3, new QStandardItem(QObject::tr("Destination")));
  mainModel->setHorizontalHeaderItem(
      4, new QStandardItem(QObject::tr("Protocol")));
  mainModel->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("Size")));
  mainModel->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("Info")));

  view->setModel(mainModel);
  view->setColumnWidth(0, 90);
  view->setColumnWidth(1, 150);
  view->setColumnWidth(2, 200);
  view->setColumnWidth(3, 200);
  view->setColumnWidth(4, 100);
  view->setColumnWidth(5, 100);
  vien->setColumnWidth(6, 300);

  view->horizontalHeader()->resizeSections(QHeaderView::ResizeMode::Fixed);
  view->verticalHeader()->hide();
  view->setSelectionBehavior(QAbstractItemView::SelectRows);
  view->setSelectionMode(QAbstractItemView::SingleSelection);
  view->setTextElideMode(Qt::ElideMiddle);
  view->setEditTriggers(QAbstractItemView::NoEditTriggers);

  index = 0;
}

/* add a new packet */
void ListView::addPacketItem(SnifferData &tmpSnifferData, bool fnew,
                             bool display) {
  if (display) {
    QStandardItem *item;

    item = new QStandardItem(QString(tmpSnifferData.strNum));
    mainModel->setItem(index, 0, item);
    item = new QStandardItem(QString(tmpSnifferData.strTime));
    mainModel->setItem(index, 1, item);
    item = new QStandardItem(QString(tmpSnifferData.strSIP));
    mainModel->setItem(index, 2, item);
    item = new QStandardItem(QString(tmpSnifferData.strDIP));
    mainModel->setItem(index, 3, item);
    item = new QStandardItem(QString(tmpSnifferData.strProto));
    mainModel->setItem(index, 4, item);
    item = new QStandardItem(QString(tmpSnifferData.strLength));
    mainModel->setItem(index, 5, item);
    item = new QStandardItem(QString(tmpSnifferData.strInfo));
    mainModel->setItem(index, 6, item);

    // set color according to protocols
    QVariant qcolor;
    QColor *color;
    switch (tmpSnifferData.strProto) {
    case ETHERTYPE_IP:
      color = new QColor(100, 255, 100);
      break;
    case ETHERTYPE_ARP:
      color = new QColor(100, 100, 255);
      break;
    case ETHERTYPE_IPV6:
      color = new QColor(255, 100, 100);
      break;
    default:
      color = new QColor(200, 200, 200);
      break;
    }
    qcolor = *color;
    for (int i = 0; i < 7; i++) {
      // how to make it easier :(
      mainModel->setData(mainModel->index(index, i), qcolor,
                         Qt::BackgroundRole);
    }
    delete color;
    index++;
  }

  if (fnew)
    packets.push_back(tmpSnifferData);
}
