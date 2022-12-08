#ifndef VIEW_H
#define VIEW_H

#include "utils/utils.h"

class View {

private:
    QStandardItemModel *treeModel;
    QTreeView *treeView;
    QTextBrowser *textBrowser;

    void reload();
    void setTreeViewByIndex(packet_struct packet);
    void setHexViewByIndex(packet_struct packet);
public:
    QTableView *view;
    View(QTableView *view);
    ~View();

    void rebuildInfo();
    bool isChanged();
    int getPacketsNum();
    void addPacketItem(packet_struct &data, bool fnew=true, bool display=true);
    void loadByIndex(std::vector<int> &indexs);
    void getOrderNumber(QModelIndex &index, QString &strNumber);

    void clearData();

    MultiView(QTreeView *tree, QTextBrowser* hex, QTableView *list):ListView(list),treeView(tree),textBrowser(hex){
        reload();
    }
    ~MultiView();
    void packetInfoByIndex(QModelIndex index);   //call to update treeView $ hexView; responding signal list_item_clicked
    QList<QStandardItem*> returnTreeItems();

protected:
    friend class MainWindow;
    friend class Filter;
    QStandardItemModel *mainModel;
    int index;
    std::vector< packet_struct > packets;
    std::vector< QString > status;
    std::vector< std::map<unsigned int, int> > fileFlow;
};

#endif // VIEW_H