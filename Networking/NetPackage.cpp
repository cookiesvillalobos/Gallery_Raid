//
// Created by viviana on 03/06/19.
//

#define RAPIDJSON_HAS_STDSTRING 1

#include "NetPackage.h"

#include "NetPackage.h"
#include "/home/viviana/CLionProjects/server/rapidjson/document.h"
#include "/home/viviana/CLionProjects/server/rapidjson/writer.h"
#include "/home/viviana/CLionProjects/server/rapidjson/stringbuffer.h"

NetPackage::NetPackage() {
}


/**
 * This function is in charge of constructing the json string
 * @return Json String of this NetPackage object
 */
std::string NetPackage::getJSONPackage(){
    rapidjson::Document docu;

    docu.SetObject();

    rapidjson::Document::AllocatorType& allocator = docu.GetAllocator();

    rapidjson::Value object(rapidjson::kObjectType);
    object.AddMember("from", this->from, allocator);
    object.AddMember("data", this->data, allocator);
    object.AddMember("command", this->command, allocator);
    docu.AddMember("NetPackage", object, allocator);

    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    docu.Accept(writer);

    return strbuf.GetString();
}


/**
 * Gets the author of the package
 * @return The author of this package
 */
std::string NetPackage::getFrom() {
    return this->from;
}


/**
 * Gets the data of the Package
 * @return Data of the package
 */
std::string NetPackage::getData() {
    return this->data;
}


/**
 * Gets the command associated with the package
 * @return Command of this package
 */
std::string NetPackage::getcommand() {
    return this->command;
}

/**
 * Sets the author of the package
 * @param author
 */
void NetPackage::setFrom(std::string form) {
    this->from = form;
}

/**
 * Sets the data for the package
 * @param data ( as a string )
 */
void NetPackage::setData(std::string data) {
    this->data = data;
}

/**
 * Sets the command for the package
 * @param command
 */
void NetPackage::setCommand(std::string command) {
    this->command = command;
}

rapidjson::Document NetPackage::convertToRJ_Document(std::string json){
    rapidjson::Document doc;
    doc.Parse(json);
    return doc;
}


