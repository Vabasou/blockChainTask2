#pragma once
#include "libraries.hpp"
#include "hash.hpp"
#include "sha256.h"
#include "RND.hpp"
#include "transaction.hpp"

class Block {
    private:
        string blockHash;
        string prevBlockHash;
        string timestamp;
        string merkleRoot;
        int nonce = 0;
        vector<Transaction> transactions;

    public:
        Block();
        Block(string prevBlockHash, int difficulty);
        void mineBlock();

        int index;
        string getMerkleRoot();
        void addTransactions(vector<Transaction> &);
        void addTransaction(Transaction &);
        void mine();
        string getBlockHash();
        vector<Transaction> &getTransactions();
        string toSString();
        string getTimestamp();
        int getTransactionNumber();
        int getTransactionVolumr();
        bool tryToMine();

        bool isMined;
        int attempts = 1000;
        int difficulty;
        double version = 1.0;
};