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
  std::vector<packet_struct *> pkt;
  // std::vector<packet_struct *> copy_pkt;

  View(QTableView *table, QTextBrowser *text, QTreeView *tree);
  ~View();
  void add_pkt(packet_struct *packete);
  void rebuildTableView();
  void clearView();

private slots:
  void onTableClicked(const QModelIndex &);

protected:
  friend class MainWindow;
  int index;
  QStandardItemModel *TableModel;
  QStandardItemModel *TreeModel;
};

#endif // VIEW_H