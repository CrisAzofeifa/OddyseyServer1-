//
// Created by karina on 25/05/18.
//

#include <iostream>
#include "Query.h"

void Query::readFile(std::string path) {
    std::cout << "1" << std::endl;
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    std::cout << "2" << std::endl;
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    std::cout << "3" << std::endl;
    Document d;
    d.ParseStream(is);
    std::cout << "4" << std::endl;
    fclose(fp);
    std::cout << "just read" << std::endl;

    FILE* fp2 = fopen("../DataBase/output.json", "w"); // non-Windows use "w"
    char writeBuffer[65536];
    FileWriteStream os(fp2, writeBuffer, sizeof(writeBuffer));
    Writer<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp2);
    std::cout << "just wrote" << std::endl;
}

void Query::findValue(std::string) {
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    std::string dd = d["tracks"][0]["name"].GetString();
}

bool Query::Buscar(std::string) {
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    if(d["tracks"][0]["name"].GetString() != NULL){
        return false;
    }else{
        return true;
    }
}



bool Query::checkCredentials(std::string user, std::string password) {
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);

    for(int i = 0; i < d["users"].Size(); i++){
        if(d["users"][i]["username"].GetString() == user &&
           d["users"][i]["password"].GetString() == password){
            return true;
        }
    }
    return false;
}

SimpleLinkedList<Metadata> Query::getAllTracks(){
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    int numberOfTracks = d["tracks"].Size();

    SimpleLinkedList<Metadata> tracksList;

    for (int h = 0; h < numberOfTracks; h++) {

        Metadata trackData;
        if(d["tracks"][h].HasMember("name")){
            trackData.setSongName(d["tracks"][h]["name"].GetString());
        }
        if(d["tracks"][h].HasMember("artist")){
            trackData.setArtist(d["tracks"][h]["artist"].GetString());
        }
        if(d["tracks"][h].HasMember("album")){
            trackData.setAlbum(d["tracks"][h]["album"].GetString());
        }
        if(d["tracks"][h].HasMember("duration")){
            trackData.setDuration(d["tracks"][h]["duration"].GetString());
        }
        if(d["tracks"][h].HasMember("genre")){
            trackData.setGenre(d["tracks"][h]["genre"].GetString());
        }
        if(d["tracks"][h].HasMember("year")){
            trackData.setYear(d["tracks"][h]["year"].GetString());
        }

        tracksList.insertRear(trackData);
    }

    return tracksList;
}

SimpleLinkedList<Metadata> Query::getTrackByArtist(std::string artist){
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    int numberOfTracks = d["tracks"].Size();

    SimpleLinkedList<Metadata> tracksList;

    for (int h = 0; h < numberOfTracks; h++) {

        Metadata trackData;
        if (d["tracks"][h]["artist"].GetString() == artist) {
            if (d["tracks"][h].HasMember("name")) {
                trackData.setSongName(d["tracks"][h]["name"].GetString());
            }
            if (d["tracks"][h].HasMember("artist")) {
                trackData.setArtist(d["tracks"][h]["artist"].GetString());
            }
            if (d["tracks"][h].HasMember("album")) {
                trackData.setAlbum(d["tracks"][h]["album"].GetString());
            }
            if (d["tracks"][h].HasMember("duration")) {
                trackData.setDuration(d["tracks"][h]["duration"].GetString());
            }
            if (d["tracks"][h].HasMember("genre")) {
                trackData.setGenre(d["tracks"][h]["genre"].GetString());
            }
            if (d["tracks"][h].HasMember("year")) {
                trackData.setYear(d["tracks"][h]["year"].GetString());
            }

            tracksList.insertRear(trackData);
        }
    }

    return tracksList;
}
SimpleLinkedList<Metadata> Query::getTrackByName(std::string name){
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    int numberOfTracks = d["tracks"].Size();

    SimpleLinkedList<Metadata> tracksList;

    for (int h = 0; h < numberOfTracks; h++) {

        Metadata trackData;
        if (d["tracks"][h]["name"].GetString() == name) {
            if (d["tracks"][h].HasMember("name")) {
                trackData.setSongName(d["tracks"][h]["name"].GetString());
            }
            if (d["tracks"][h].HasMember("artist")) {
                trackData.setArtist(d["tracks"][h]["artist"].GetString());
            }
            if (d["tracks"][h].HasMember("album")) {
                trackData.setAlbum(d["tracks"][h]["album"].GetString());
            }
            if (d["tracks"][h].HasMember("duration")) {
                trackData.setDuration(d["tracks"][h]["duration"].GetString());
            }
            if (d["tracks"][h].HasMember("genre")) {
                trackData.setGenre(d["tracks"][h]["genre"].GetString());
            }
            if (d["tracks"][h].HasMember("year")) {
                trackData.setYear(d["tracks"][h]["year"].GetString());
            }

            tracksList.insertRear(trackData);
        }
    }

    return tracksList;
}

SimpleLinkedList<Userdata> Query::getUsers(){
    FILE* fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    int totalUsers = d["users"].Size();

    SimpleLinkedList<Userdata> users;

    for (int h = 0; h < totalUsers; h++) {

        Userdata userdata;

            if (d["users"][h].HasMember("username")) {
                userdata.setUsername(d["users"][h]["username"].GetString());
            }
            if (d["users"][h].HasMember("password")) {
                userdata.setPassword(d["users"][h]["password"].GetString());
            }
            if (d["users"][h].HasMember("friends")) {
                SimpleLinkedList<std::string> friends;
                for(int y = 0; y < d["users"][h]["friends"].Size(); y++){
                    friends.insertRear(d["users"][h]["friends"][y].GetString());
                }
                userdata.setFriends(friends);
            }
            if (d["users"][h].HasMember("preferences")) {
                SimpleLinkedList<std::string> preferences;
                for(int y = 0; y < d["users"][h]["preferences"].Size(); y++){
                    preferences.insertRear(d["users"][h]["preferences"][y].GetString());
                }
                userdata.setPreferences(preferences);
            }

            users.insertRear(userdata);

    }

    return users;
}
SimpleLinkedList<std::string> Query::getUserFriends(std::string username) {
    FILE *fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);

    int totalUsers = d["users"].Size();
    SimpleLinkedList<std::string> friends;
    for (int h = 0; h < totalUsers; h++) {

        if (d["users"][h].HasMember("friends") && d["users"][h]["username"].GetString() == username) {

            for (int y = 0; y < d["users"][h]["friends"].Size(); y++) {
                friends.insertRear(d["users"][h]["friends"][y].GetString());
            }
            return friends;
        } else {
            return friends;
        }
    }
}
SimpleLinkedList<std::string> Query::getUserPreferences(std::string username){
    FILE *fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    SimpleLinkedList<std::string> preferences;
    int totalUsers = d["users"].Size();

    for (int h = 0; h < totalUsers; h++) {

        if (d["users"][h].HasMember("preferences") && d["users"][h]["username"].GetString() == username) {

            for (int y = 0; y < d["users"][h]["preferences"].Size(); y++) {
                preferences.insertRear(d["users"][h]["preferences"][y].GetString());
            }
            return preferences;
        } else {
            return preferences;
        }
    }

}

void Query::addNewTrack(Metadata metadata) {
    FILE *fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);

    Document::AllocatorType& allocator = d.GetAllocator();
    rapidjson::Value object(rapidjson::kObjectType);
    if(!metadata.getSongName().empty()) {
        Value textPart;
        textPart.SetString(metadata.getSongName().c_str(), allocator);
        object.AddMember("name",textPart , allocator);
    }
    if(!metadata.getArtist().empty()){
        Value textPart;
        textPart.SetString(metadata.getArtist().c_str(), allocator);
        object.AddMember("artist", textPart, allocator);
        }
    if(!metadata.getAlbum().empty()){
        Value textPart;
        textPart.SetString(metadata.getAlbum().c_str(), allocator);
        object.AddMember("album", textPart, allocator);
        }
    if(!metadata.getDuration().empty()){
        Value textPart;
        textPart.SetString(metadata.getDuration().c_str(), allocator);
        object.AddMember("duration", textPart, allocator);
        }
    if(!metadata.getGenre().empty()){
        Value textPart;
        textPart.SetString(metadata.getGenre().c_str(), allocator);
        object.AddMember("genre", textPart, allocator);
        }
    if(!metadata.getYear().empty()){
        Value textPart;
        textPart.SetString(metadata.getYear().c_str(), allocator);
        object.AddMember("year", textPart, allocator);
        }
    d["tracks"].PushBack(object, allocator);


    FILE* fp2 = fopen("../DataBase/database.json", "w"); // non-Windows use "w"
    char writeBuffer[65536];
    FileWriteStream os(fp2, writeBuffer, sizeof(writeBuffer));
    Writer<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp2);
}

void Query::addNewUser(Userdata userdata) {
    FILE *fp = fopen("../DataBase/database.json", "r"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);

    Document::AllocatorType& allocator = d.GetAllocator();
    rapidjson::Value object(rapidjson::kObjectType);
    if(!userdata.getUsername().empty()) {
        Value textPart;
        textPart.SetString(userdata.getUsername().c_str(), allocator);
        object.AddMember("username",textPart , allocator);
    }
    if(!userdata.getPassword().empty()){
        Value textPart;
        textPart.SetString(userdata.getPassword().c_str(), allocator);
        object.AddMember("password", textPart, allocator);
    }

    if(userdata.getFriends().getSize() > 0){
        rapidjson::Value array(rapidjson::kArrayType);
        auto *node = userdata.getFriends().getHead();
        for(int i = 0; i < userdata.getFriends().getSize(); i++){
            Value textPart;
            std::string string = node->getData();
            textPart.SetString(string.c_str(), allocator);
            array.PushBack(textPart, allocator);
            node = node->getNext();
        }
        object.AddMember("friends", array, allocator);
    }else {
        std::cout << "no friends..." << std::endl;
    }
    if(userdata.getPreferences().getSize() > 0){
        rapidjson::Value array(rapidjson::kArrayType);
        Node<std::string> *node = userdata.getPreferences().getHead();
        for(int i = 0; i < userdata.getPreferences().getSize(); i++){
            Value textPart;
            std::string string = node->getData();
            textPart.SetString(string.c_str(), allocator);
            array.PushBack(textPart, allocator);
            node = node->getNext();
        }
        object.AddMember("preferences", array, allocator);
    }else {
        std::cout << "no preferences..." << std::endl;
    }
    if(object.MemberCount() != 0)
        d["users"].PushBack(object, allocator);


    FILE* fp2 = fopen("../DataBase/database.json", "w"); // non-Windows use "w"
    char writeBuffer[65536];
    FileWriteStream os(fp2, writeBuffer, sizeof(writeBuffer));
    Writer<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp2);
}
