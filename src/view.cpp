#include "view.h"

View::View(QTableView *v){
    view = v;
    mainModel = new QStandardItemModel();
    mainModel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("NO.")));
    mainModel->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Time")));
    mainModel->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Source")));
    mainModel->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Destination")));
    mainModel->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("Protocol")));
    mainModel->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("Length")));
    mainModel->setHorizontalHeaderItem(6,new QStandardItem(QObject::tr("Info")));

    
    view->setModel(mainModel);
    view->setColumnWidth(0,60);
    view->setColumnWidth(1,200);
    view->setColumnWidth(2,200);
    view->setColumnWidth(3,200);
    view->setColumnWidth(4,150);
    view->setColumnWidth(5,60);
    view->setColumnWidth(5,300);

    view->horizontalHeader()->resizeSections(QHeaderView::ResizeMode::Fixed);
    view->verticalHeader()->hide();
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setTextElideMode(Qt::ElideMiddle);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    index = 0;
}

View::~View(){
    clearData();
}

/* Clear all Data to initial status */
void View::clearData()
{
    if(status.size()>0) status.clear();
    if(fileFlow.size()>0) fileFlow.clear();
    if(packets.size()>0) packets.clear();

    index = 0;
    rebuildInfo();
}


/*
 * Delete all items in TableView
 * vertor<packet> packets not changed
 * can be called when restart
 */
void View::rebuildInfo(){
    mainModel->clear();
    
    //reset TableView
    mainModel = new QStandardItemModel();
    mainModel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("NO.")));
    mainModel->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Time")));
    mainModel->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Source")));
    mainModel->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Destination")));
    mainModel->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("Protocol")));
    mainModel->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("Length")));
    mainModel->setHorizontalHeaderItem(6,new QStandardItem(QObject::tr("Info")));

    view->setModel(mainModel);
    view->setColumnWidth(0,60);
    view->setColumnWidth(1,200);
    view->setColumnWidth(2,200);
    view->setColumnWidth(3,200);
    view->setColumnWidth(4,150);
    view->setColumnWidth(5,60);
    view->setColumnWidth(5,300);

    view->horizontalHeader()->resizeSections(QHeaderView::ResizeMode::Fixed);
    view->verticalHeader()->hide();
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setTextElideMode(Qt::ElideMiddle);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    index = 0;
}

/*
 * called by cthread::run
 * add a new packet
 */


void View::addPacketItem(packet_struct &tmpPacket, bool fnew, bool display){
    if (display) {
        QStandardItem *item;

        QString src_IP = "";
        QString dest_IP = "";
        switch(tmpPacket.net_type){
            case ARP:
              int i;
              for(i=0;i<4;i++){
                QString temp = QString::number(tmpPacket.net_hdr.arp_hdr->src_ip[i],10);
                src_IP.append(temp);
                if(i<3)  src_IP.append('.');
              }
              for(i=0;i<4;i++){
                QString temp = QString::number(tmpPacket.net_hdr.arp_hdr->dest_ip[i],10);
                dest_IP.append(temp);
                if(i<3)  dest_IP.append('.');
              }
              break;
            
            case IPv4:
              src_IP = inet_ntoa(tmpPacket.net_hdr.ipv4_hdr->ip_src);
              dest_IP = inet_ntoa(tmpPacket.net_hdr.ipv4_hdr->ip_dst);
              break;

            case IPv6:
              int i;
              for(i=0;i<8;i++){
                QString temp = QString::number(tmpPacket.net_hdr.ipv6_hdr->src_addr[i],16)
                src_IP.append(temp);
                if(i<7)  src_IP.append(':');
              }
              for(i=0;i<8;i++){
                QString temp = QString::number(tmpPacket.net_hdr.ipv6_hdr->dest_addr[i],16)
                dest_IP.append(temp);
                if(i<7)  dest_IP.append(':');
              } 
              break;
        }

        QString Protocal;
        switch(tmpPacket.trs_type){
            case UDP: 
              Protocal = "UDP";
              break;

            case TCP:
              Protocal = "TCP";
              break;

            case ICMP:
              Protocal = "ICMP";
              break;

            case IGMP:
              Protocal = "IGMP";
              break;
        }

        QString NO = QString::number(tmpPacket.no, 10);

        QString Length = QString::number(tmpPacket.len, 10);

        QString Info = tmpPacket.payload;  //TODO 

        item = new QStandardItem(QString(NO));
        mainModel->setItem(index, 0, item);
        item = new QStandardItem(QString(tmpPacket.time));
        mainModel->setItem(index, 1, item);
        item = new QStandardItem(QString(src_IP));
        mainModel->setItem(index, 2, item);
        item = new QStandardItem(QString(dest_IP));
        mainModel->setItem(index, 3, item);
        item = new QStandardItem(QString(Protocal));
        mainModel->setItem(index, 4, item);
        item = new QStandardItem(QString(Length));
        mainModel->setItem(index, 5, item);
        item = new QStandardItem(QString(Info));
        mainModel->setItem(index, 6, item);

        //set color according to protocols
        QVariant qcolor;
        QColor* color;
        switch (tmpPacket.trs_type) {
        case(TCP): color = new QColor(100,255,100);break;
        case(UDP): color = new QColor(100,100,255);break;
        case(ICMP): color = new QColor(255,100,100);break;
        case(IGMP): color = new QColor(255,255,100);break;
        default: color = new QColor(200,200,200);
        }
        qcolor = *color;
        for (int i=0; i<6; i++) {
            //how to make it easier :(
            mainModel->setData(mainModel->index(index, i), qcolor, Qt::BackgroundRole);
        }
        delete color;
        index++;
    }

    if(fnew) packets.push_back(tmpPacket);
}


void ListView::loadByIndex(std::vector<int> &indexs)
{
    rebuildInfo();
    for(std::vector<int>::iterator it = indexs.begin(); it != indexs.end(); it++) {
        addPacketItem(packets.at(*it), false, true);
    }
}


