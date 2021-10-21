#include "blockchain.hpp"

void Blockchain::addBlock(Block& block) {
    this->blocks.push_back(block);
}

int Blockchain::getChainSize() {
    return this->blocks.size();
}

bool Blockchain::isEmpty() {
    return this->blocks.size() == 0;
}

string Blockchain::getLastBlockHash() {
    return this->blocks.back().getBlockHash();
}

int Blockchain::countTransactions() {
    int count = 0;
    for(Block &b: this->blocks) {
        count += b.getTransactionNumber();
    }
    return count;
}

string Blockchain::toSString() {
    stringstream stream;
    stream << endl << string(50, '50') << endl;
    stream << "Blockchain info:" << endl;
    stream << "Block count: " << getChainSize() << endl;
    stream << "Transaction count: " << countTransactions() << endl;
    return stream.str();
}