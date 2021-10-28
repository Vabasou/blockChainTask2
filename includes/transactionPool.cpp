#include "transactionPool.hpp"

void TransactionPool::generateTransactionPool(Users& users, int number) {
    for (int i = 0; i < number; i++) {
        User* sender = users.getRandomUser();
        User* receiver = users.getRandomUser();
        while(receiver->getPublicKey() == sender->getPublicKey()) {
            sender = users.getRandomUser();
        }

        int amount = RND::getIntegerInRange(0, sender->getBalance());
        Transaction transaction(sender, receiver, amount);

        this->transactionPool.push_back(transaction);
    }
}

Transaction TransactionPool::getTransaction(int index) {
    return transactionPool[index];
}

vector<Transaction> TransactionPool::getTransactions(int number) {
    vector<Transaction> transactions;
    int times = std::min(number, getTransactionNumber());

    for (int i = 0; i < times; i++) {
        transactions.push_back(getTransaction(RND::getIntegerInRange(0, getTransactionNumber())));
    }
    return transactions;
}

int TransactionPool::getTransactionNumber() {
    return transactionPool.size();
}

void TransactionPool::removeTransaction(Transaction &transaction) {
    vector<Transaction>::iterator it;
    it = std::find_if(transactionPool.begin(), transactionPool.end(), [&transaction](Transaction& t) {
        return t.getId() == transaction.getId();
    });

    if (it != transactionPool.end()) {
        transactionPool.erase(it);
    }
}

void TransactionPool::removeTransactions(vector<Transaction> &transaction) {
    for (Transaction &temp : transaction) {
        removeTransaction(temp);
    }
}

void TransactionPool::checkIdAndExecute() {
    vector<Transaction>::iterator it;
    it = this->transactionPool.begin();
    
    while (it != this->transactionPool.end()) {
        if (it->isHashValid()) {
            it->execute();
            ++it;
        }
    }
}

string TransactionPool::to_SString() {
    stringstream stream;
    for (Transaction &transaction : transactionPool) {
        stream << string(50, '-') << endl;
        stream << "Transaction ID:        " << transaction.getId() << endl;
        stream << "Sender's public key:   " << transaction.getSendersHash() << endl;
        stream << "Receiver's public key: " << transaction.getReceiversHash() << endl;
        stream << "Amount :               " << transaction.getAmount() << endl;
    }
    return stream.str();
}