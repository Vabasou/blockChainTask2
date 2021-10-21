#pragma once
#include "libraries.hpp"
#include "user.hpp"
#include "hash.hpp"
#include "RND.hpp"

#define MINBALANCE 100
#define MAXBALANCE 1000000

class Users {
    private:
        vector<User> users;

    public:
        Users(int count = 1000);
        void generateUsers(int);
        string toSString();
        User* getRandomUser();
        User *getPoorest();
        User *getRichest();
};