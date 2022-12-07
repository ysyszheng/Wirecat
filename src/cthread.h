#ifndef CTHREAD_H
#define CTHREAD_H

#include "sniffer.h"
#include "utils/utils.h"

class CThread : public QThread {
  Q_OBJECT
public:
  CThread(Sniffer* snifferObj);
  ~CThread();
  void run();
  void stop();
  void wait();

private:
  Sniffer *sniffer;
};

#endif // CTHREAD_H