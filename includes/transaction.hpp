#pragma once
#include "libraries.hpp"
#include "user.hpp"
#include "hash.hpp"

class Transaction {
    private:
        User* sender;
        User* receiver;
        string transactionId;
        int amount;

    public:
        Transaction(User*, User*, int);
        void execute();
        
        string getId();
        User* getSender();
        User* getReceiver();
        string getSendersHash();
        string getReceiversHash();
        int getAmount();
        string toSString();
};