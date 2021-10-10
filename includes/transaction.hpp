#pragma once
#include "libraries.hpp"
#include "hash.hpp"

class Transaction {
    public:
        string *sender;
        string *reciever;
        string id;
        int amount;
        int time;
        string ownHash = calculateHash();

        void execute();
        string calculateHash();
        string makeString() const;
};