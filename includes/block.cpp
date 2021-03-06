#include "block.hpp"

using namespace std::chrono;

Block::Block() {
}

Block::Block(string prevBlockHash, int difficulty) {
    using namespace std::chrono;
    this->isMined = false;
    this->prevBlockHash = prevBlockHash;
    this->difficulty = difficulty;
    this->version = version;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    timestamp = std::ctime(&end_time);
}

void Block::addTransaction(Transaction &transaction) {
    vector<Transaction>::iterator it;
    it = find_if(this->transactions.begin(), this->transactions.end(), [&transaction](Transaction &t) { 
            return t.getId() == transaction.getId(); 
        });

    if (it == transactions.end()) {
        transactions.push_back(transaction);
    }
}

string Block::getMerkleRoot() {
    vector<string> currentLayer;
    vector<string> nextLayer;

    for (Transaction &t : transactions) {
        currentLayer.push_back(t.getId());
    }

    int numOfLevels = ceil(log2(currentLayer.size()));

    for (int i = 0; i < numOfLevels; i++) {
        if (currentLayer.size() % 2 != 0) {
        currentLayer.push_back(currentLayer.back());
        }

        for (int j = 0; j < currentLayer.size(); j += 2) {
        nextLayer.push_back(myHash(myHash(currentLayer[j]) + myHash(currentLayer[j + 1])));
        }

        currentLayer.clear();
        currentLayer = nextLayer;
        nextLayer.clear();
    }

    return currentLayer[0];
}

void Block::mineBlock() {
    this->merkleRoot = this->getMerkleRoot();
    string startString(this->difficulty, '0');

    for (int i = 0; i < attempts; i++) {
        nonce++;
        blockHash = getBlockHash();

        if (blockHash.substr(0, difficulty) == startString) {
        cout << "Bloko hash: " << blockHash << endl;
        isMined = true;
        return;
        }
    }
}

void Block::addTransactions(vector<Transaction> &t) {
    for (Transaction &temp : t) {
        transactions.push_back(temp);
    }
}

vector<Transaction> &Block::getTransactions() {
    return this->transactions;
}

string Block::getTimestamp() {
    return this->timestamp;
}

string Block::getBlockHash() {
    stringstream stream;
    stream << this->prevBlockHash << this->timestamp << this->difficulty << this->version << this->nonce << this->getMerkleRoot();
    return sha256(stream.str());
}

int Block::getTransactionNumber() {
    return this->transactions.size();
}

string Block::toSString() {
    stringstream stream;

    stream << "Hash:          " << this->getBlockHash() << endl;
    stream << "Previous hash: " << this->prevBlockHash << endl;
    stream << "Timestamp:     " << this->getTimestamp();
    stream << "Difficulty:    " << this->difficulty << endl;
    stream << "Merkle root:   " << this->getMerkleRoot() << endl;
    stream << "Version:       " << this->version << endl;
    stream << "Nonce:         " << this->nonce << endl;
    stream << "Transactions  (" << this->transactions.size() << ")" << endl;

    int index = 0;
    for (Transaction &transaction : this->transactions) {
        stream << "---------" << endl;
        stream << "index:   " << index << endl;
        stream << transaction.toSString();

        index++;
    }

  return stream.str();
}
