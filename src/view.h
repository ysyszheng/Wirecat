#ifndef VIEW_H
#define VIEW_H

#include "qobjectdefs.h"
#include "utils/utils.h"

class View : public QObject {
  Q_OBJECT

private:
  QTableView *table;
  QTreeView *tree;
  QTextBrowser *text;

public:
  View(QTableView *table, QTextBrowser *text, QTreeView *tree);
  ~View();
  void add_pkt(packet_struct *packete);

private slots:
  // void onTableClicked(int idx);
  void onTableClicked(const QModelIndex &);

protected:
  friend class MainWindow;
  int index;
  QStandardItemModel *TableModel;
  QStandardItemModel *TreeModel;
  std::vector<packet_struct *> pkt;
};

#endif // VIEW_H