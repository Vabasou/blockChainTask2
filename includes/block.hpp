#pragma once
#include "libraries.hpp"
#include "hash.hpp"

class TransactionData {
    public:
        double amount;
        string senderKey;
        string receiverKey;
        time_t timestamp;
};

class Block {
    private:
        int index;
        string blockHash;
        string previousHash;
        string generateHash();

    public:
        Block(int index, TransactionData data, string previousHash);
        string getHash();
        string getPreviousHash();

        TransactionData data;

        bool isHashValid();
};

Block::Block(int index, TransactionData data, string previousHash) {
    this->index = index;
    this->data = data;
    this->previousHash = previousHash;
    this->blockHash = generateHash();
}

string Block::generateHash() {
    string hash1;
    string hash2;
    string finalHash;
    string toHash = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);

    return myHash(myHash(toHash) + myHash(previousHash));
}

string Block::getHash() {
    return blockHash;
}

string Block::getPreviousHash() {
    return previousHash;
}

bool Block::isHashValid() {
    return generateHash() == blockHash;
}


class Blockchain {
    private:
        Block createGenesisBlock();
    
    public:
        vector<Block> chain;

        Blockchain();
        void addBlock(TransactionData data);
        bool isChainValid();

        //For testing purposes only
        Block *getLatestBlock();
};

Blockchain::Blockchain() {
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock() {
    time_t current;
    TransactionData data;
    data.amount = 0;
    data.receiverKey = "None";
    data.senderKey = "None";
    data.timestamp = time(&current);

    string hash1 = "0";
    Block genesis(0, data, myHash(hash1));
    return genesis;
}

//For testing only
Block *Blockchain::getLatestBlock() {
    return &chain.back();
}

void Blockchain::addBlock(TransactionData data) {
    int index = (int)chain.size() - 1;
    Block newBlock(index, data, getLatestBlock()->getHash());
}

bool Blockchain::isChainValid() {
    vector<Block>::iterator it;
    int chainLength = (int)chain.size();

    for(it = chain.begin(); it != chain.end(); ++it) {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid()) {
            return false;
        }

        if(chainLength > 1) {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash()) {
                return false;
            }
        }
    }
}