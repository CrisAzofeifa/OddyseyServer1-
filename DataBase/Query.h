//
// Created by karina on 25/05/18.
//

#ifndef SERVERDATABASE_QUERY_H
#define SERVERDATABASE_QUERY_H
#pragma once
#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"
#include <cstdio>
#include "../rapidjson/filewritestream.h"
#include "../rapidjson/writer.h"
#include "Metadata.h"
#include "Userdata.h"
#include "../List.h"

using namespace rapidjson;

class Query {
public:
    void readFile(std::string path);
    void findValue(std::string);
    bool Buscar(std::string);
    bool checkCredentials(std::string user, std::string password);
    List<Metadata> getAllTracks();
    List<Metadata> getTrackByArtist(std::string artist);
    List<Metadata>  getTrackByName(std::string name);
    List<Userdata> getUsers();
    List<std::string> getUserFriends(std::string username);
    List<std::string> getUserPreferences(std::string username);
    void addNewUser(Userdata userdata);
    void addNewTrack(Metadata metadata);

};


#endif //SERVERDATABASE_QUERY_H
