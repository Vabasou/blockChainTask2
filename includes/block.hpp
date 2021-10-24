#pragma once
#include "libraries.hpp"
#include "hash.hpp"
#include "RND.hpp"
#include "transaction.hpp"

class Block {
    private:
        string blockHash;
        string prevBlockHash;
        int timestamp;
        string merkleRoot;
        int nonce = 0;
        vector<Transaction> transactions;
        bool isMined;

    public:
        Block(string prevBlockHash, int difficulty, double version);

        string getMerkleRoot();
        void addTransactions(vector<Transaction> &);
        void addTransaction(Transaction &);
        void mine();
        string getBlockHash();
        vector<Transaction> getTransactions();
        string toSString();
        string getTimestamp();
        int getTransactionNumber();
        int getTransactionVolumr();

        int difficulty = 4;
        double version = 1.0;
};