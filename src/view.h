#ifndef VIEW_H
#define VIEW_H

#include "utils/utils.h"

class View {

private:

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