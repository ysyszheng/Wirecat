/*
 * listview.h
 * Deal with QTableView on mainwindow
 * collect data_packet then add items to TableView
 */

#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QTableView>
#include <QtGui>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QString>
#include <QStandardItem>
#include <QByteArray>
#include "hdr.h"
#include <vector>
#include <map>


/* data structure of the captured data */
typedef struct {
    QString				strNum;			/* The serial number */
    QString 			strTime;		/* Time */
    QString 			strSIP;			/* Source IP address, format: IP:port */
    QString 			strDIP;			/* dsest IP address, format: IP:port */
    QString 			strProto;		/* Protocal */
    QString             strProtoForShow;
    QString		        strLength;		/* length of data */
    QString             strInfo;        /* packet info */
    QByteArray  		strData;		/* origianl data */
    AnalyseProtoType	protoInfo;		/* struct for showing tree-info */
} SnifferData;

/* The tree structure displays data */
typedef struct{
    uint ipFlag;
    uint tcpFlag;
    uint appFlag;
    void* peth;
    void* pip;
    void* ptcp;
    QString ipProto;
    QByteArray strSendInfo;
} AnalyseProtoType;


class ListView{

public:
    QTableView *view;
    ListView(QTableView *view);
    ~ListView();

    void reBuildInfo();
    bool isChanged();
    int getPacketsNum();
    void addPacketItem(SnifferData &data, bool fnew=true, bool display=true);
    void loadByIndex(std::vector<int> &indexs);
    void getOrderNumber(QModelIndex &index, QString &strNumber);

    void clearData();
    void addFilePacket(QString id, unsigned int seq, int index);
protected:
    friend class Filter;
    friend class FileDialog;
    QStandardItemModel *mainModel;
    int index;
    std::vector<SnifferData> packets;
    std::vector< QString > status;
    std::vector< std::map<unsigned int, int> > fileFlow;
};

#endif  // LISTVIEW_H
