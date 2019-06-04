//
// Created by viviana on 03/06/19.
//

#ifndef NETPACKAGE_H
#define NETPACKAGE_H


#include <string>
#include <document.h>

class NetPackage {
private:
    std::string from = "unassigned";
    std::string command = "NONE";
    std::string data =  "NONE";
public:
    NetPackage();
    std::string getJSONPackage();
    std::string getFrom();
    std::string getData();
    std::string getcommand();
    void setFrom(std::string);
    void setData(std::string);
    void setCommand(std::string);
    static rapidjson::Document convertToRJ_Document(std::string);
};



#endif //NETPACKAGE_H
