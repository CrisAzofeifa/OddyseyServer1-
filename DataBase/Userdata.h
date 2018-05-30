//
// Created by karina on 27/05/18.
//

#ifndef SERVERDATABASE_USERDATA_H
#define SERVERDATABASE_USERDATA_H


#include <string>
#include "../DataStructures/SimpleLinkedList.h"

class Userdata {

public:
     SimpleLinkedList<std::string> getFriends() ;

     SimpleLinkedList<std::string> getPreferences() ;

    Userdata();

    Userdata(std::string username, std::string password, SimpleLinkedList<std::string> friends, SimpleLinkedList<std::string>preferences);

    std::string getUsername();

    void setUsername(std::string username);

    std::string getPassword();

    void setPassword(std::string password);


    void setFriends(SimpleLinkedList<std::string> friends);


    void setPreferences(SimpleLinkedList<std::string> preferences);

private:
    std::string username;
    std::string password;
    SimpleLinkedList<std::string> preferences;
    SimpleLinkedList<std::string> friends;

};


#endif //SERVERDATABASE_USERDATA_H
