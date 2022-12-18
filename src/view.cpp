#include "view.h"
#include "utils/hdr.h"

View::View(QTableView *table, QTextBrowser *text, QTreeView *tree)
    : table(table), tree(tree), text(text), index(0) {
  TableModel = new QStandardItemModel();
  TableModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("NO.")));
  TableModel->setHorizontalHeaderItem(1,
                                      new QStandardItem(QObject::tr("Time")));
  TableModel->setHorizontalHeaderItem(2,
                                      new QStandardItem(QObject::tr("Source")));
  TableModel->setHorizontalHeaderItem(
      3, new QStandardItem(QObject::tr("Destination")));
  TableModel->setHorizontalHeaderItem(
      4, new QStandardItem(QObject::tr("Protocol")));
  TableModel->setHorizontalHeaderItem(5,
                                      new QStandardItem(QObject::tr("Length")));
  TableModel->setHorizontalHeaderItem(6,
                                      new QStandardItem(QObject::tr("Info")));

  table->setModel(TableModel);
  table->setColumnWidth(0, 100);
  table->setColumnWidth(1, 150);
  table->setColumnWidth(2, 250);
  table->setColumnWidth(3, 250);
  table->setColumnWidth(4, 70);
  table->setColumnWidth(5, 60);
  table->setColumnWidth(6, 311);

  table->verticalHeader()->setVisible(false);
  table->setSelectionBehavior(QTableView::SelectRows);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);

  qRegisterMetaType<QList<QPersistentModelIndex>>(
      "QList<QPersistentModelIndex>");
  qRegisterMetaType<QAbstractItemModel::LayoutChangeHint>(
      "QAbstractItemModel::LayoutChangeHint");
  connect(table, SIGNAL(clicked(const QModelIndex &)), this,
          SLOT(onTableClicked(const QModelIndex &)));

  text->setFont({"Courier"});
  text->setFontPointSize(14);
}

View::~View() {}

void View::add_pkt(packet_struct *packet) {
  pkt.push_back(packet);
  QString prot, src, dst, info;

  switch (packet->net_type) {
  case ARP:
    prot = "ARP";
    info = (packet->net_hdr.arp_hdr->opcode == 1) ? "ARP Request" : "ARP Reply";
    src = QString::number(packet->net_hdr.arp_hdr->src_ip[0]) + ":" +
          QString::number(packet->net_hdr.arp_hdr->src_ip[1]) + ":" +
          QString::number(packet->net_hdr.arp_hdr->src_ip[2]) + ":" +
          QString::number(packet->net_hdr.arp_hdr->src_ip[3]);
    dst = QString::number(packet->net_hdr.arp_hdr->dest_ip[0]) + ":" +
          QString::number(packet->net_hdr.arp_hdr->dest_ip[1]) + ":" +
          QString::number(packet->net_hdr.arp_hdr->dest_ip[2]) + ":" +
          QString::number(packet->net_hdr.arp_hdr->dest_ip[3]);
    break;
  case IPv4:
    src = QString::fromStdString(inet_ntoa(packet->net_hdr.ipv4_hdr->ip_src));
    dst = QString::fromStdString(inet_ntoa(packet->net_hdr.ipv4_hdr->ip_dst));
    break;
  case IPv6:
    src = QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[0])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[1])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[2])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[3])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[4])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[5])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[6])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->src_addr[7]));
    dst = QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[0])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[1])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[2])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[3])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[4])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[5])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[6])) + ":" +
          QString::number(ntohs(packet->net_hdr.ipv6_hdr->dest_addr[7]));
    break;
  }

  // protocol
  if (packet->trs_type != Utrs) {
    switch (packet->trs_type) {
    case ICMP:
      prot = "ICMP";
      break;
    case IGMP:
      prot = "IGMP";
      break;
    case TCP:
      prot = "TCP";
      info = "Src port: " +
             QString::number(ntohs(packet->trs_hdr.tcp_hdr->th_sport)) +
             " to Dst port: " +
             QString::number(ntohs(packet->trs_hdr.tcp_hdr->th_dport));
      break;
    case UDP:
      prot = "UDP";
      info = "Src port: " +
             QString::number(ntohs(packet->trs_hdr.udp_hdr->src_port)) +
             " to Dst port: " +
             QString::number(ntohs(packet->trs_hdr.udp_hdr->dst_port));
      break;
    }
  } else if (packet->net_type != Unet) {
    switch (packet->net_type) {
    case ARP:
      prot = "ARP";
      break;
    case IPv4:
      prot = "IPv4";
      break;
    case IPv6:
      prot = "IPv6";
      break;
    }
  } else {
    return;
  }

  // display in TableView
  QStandardItem *item;
  item = new QStandardItem(QString::number(packet->no));
  TableModel->setItem(index, 0, item);
  item = new QStandardItem(QString::fromStdString(packet->time));
  TableModel->setItem(index, 1, item);
  item = new QStandardItem(src);
  TableModel->setItem(index, 2, item);
  item = new QStandardItem(dst);
  TableModel->setItem(index, 3, item);
  item = new QStandardItem(prot);
  TableModel->setItem(index, 4, item);
  item = new QStandardItem(QString::number(packet->len));
  TableModel->setItem(index, 5, item);
  item = new QStandardItem(info);
  TableModel->setItem(index, 6, item);

  index++;
}

void View::onTableClicked(const QModelIndex &item) {
  auto idx = item.row();
  if (item.isValid()) {
    text->clear();
    text->insertPlainText(QString::fromStdString(
        store_payload((u_char *)pkt[idx]->eth_hdr, pkt[idx]->len)));
  }
  // qDebug() << "row: " << idx;
  // qDebug() << "*******************************";
}
