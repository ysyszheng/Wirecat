#ifndef FILTER_H
#define FILTER_H

#include "utils/utils.h"
#include "sniffer.h"
#include <QTableView>
#include <regex>
#include <map>
#define P 0         /* protocal */
#define S 1         /* source IP */
#define D 2         /* dest IP */
#define SPORT 3     /* source port */
#define DPORT 4     /* dest port */
#define C 5         /* packet content */

class Filter{
public:
    Filter();
    ~Filter();
    bool checkCommand(QString command);
    bool loadCommand(QString command);
    void launchFilter(View * view);
    void printQuery();
    bool launchOneFilter(packet_struct * packet);
private:
    std::map<int, std::string> query;
    std::string findWord(std::string command, size_t pos);
};

#endif
