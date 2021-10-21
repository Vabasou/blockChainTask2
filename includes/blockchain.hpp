#pragma once
#include "libraries.hpp"
#include "block.hpp"

class Blockchain {
    public:
        vector<Block> blocks;

        void addBlock(Block &);
        int countTransactions();
        bool isEmpty();
        string getLastBlockHash();
        int getChainSize();
        string toSString();
};