#include "block.hpp"

Block::Block(string prevBlockHash, int difficulty, double version) {
    using namespace std::chrono;
    this->prevBlockHash = prevBlockHash;
    this->difficulty = difficulty;
    this->version = version;
    timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
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
    stringstream stream;
    for (Transaction &t : transactions) {
        stream << t.getId();
    }
    return myHash(stream.str());
}

void Block::mine() {
    this->merkleRoot = this->getMerkleRoot();
    string startString(this->difficulty, '0');

    do {
        nonce++;
        blockHash = getBlockHash();
    } while (blockHash.substr(0, difficulty) != startString);

    cout << "Block mined:" << blockHash << endl;
}
void Block::addTransactions(vector<Transaction> &t) {
    for (Transaction &temp : t) {
        transactions.push_back(temp);
    }
}

vector<Transaction> Block::getTransactions() {
    return this->transactions;
}

string Block::getTimestamp() {
    return this->timestamp;
}

string Block::getBlockHash() {
    stringstream stream;
    stream << this->prevBlockHash << this->getTimestamp() << this->difficulty << this->version << this->nonce << this->getMerkleRoot();
    return myHash(stream.str());
}

int Block::getTransactionNumber() {
    return this->transactions.size();
}

string Block::toSString() {
    stringstream stream;

    stream << "Hash:          " << this->getBlockHash() << endl;
    stream << "Previous hash: " << this->prevBlockHash << endl;
    stream << "Timestamp:     " << this->getTimestamp() << endl;
    stream << "Difficulty:    " << this->difficulty << endl;
    stream << "Merkle root:   " << this->getMerkleRoot() << endl;
    stream << "Version:       " << this->version << endl;
    stream << "Nonce:         " << this->nonce << endl;
    stream << "Transactions (" << this->transactions.size() << "): " << endl;

    int index = 0;
    for (auto &transaction : this->transactions) {
        stream << "__________" << endl;
        stream << "index:    " << index << endl;
        stream << transaction.toSString();

        index++;
    }

    return stream.str();
}
