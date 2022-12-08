#ifndef VIEW_H
#define VIEW_H

#include "utils/utils.h"

class View {
  friend class MainWindow;

private:
  QTableView *pktInfo;
  QTreeView *hdrInfo;
  QTextBrowser *pktContent;
};

#endif // VIEW_H