#pragma once
#include "libraries.hpp"

class User {
    public:
        int balance;
        string name;
        string publicKey;

        User(string, int);
        int getBalance();
        string getName();
        string getPublicKey();
        string toSString();
        void addMoney(int);
        void withdrawMoney(int);
};