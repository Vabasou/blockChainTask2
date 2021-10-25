#include "transaction.hpp"

Transaction::Transaction(User *sender, User *receiver, int amount) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
    this->transactionId = getHash();
}

void Transaction::execute() {
    if (this->sender->getBalance() >= this->amount) {
        this->sender->withdrawMoney(this->amount);
        this->receiver->addMoney(this->amount);
    }
}

string Transaction::getHash() {
    return myHash(sender->getName() + receiver->getName() + std::to_string(amount));
}

string Transaction::getId() {
    return transactionId;
}

User* Transaction::getReceiver() {
    return receiver;
}

User* Transaction::getSender() {
    return sender;
}

string Transaction::getReceiversHash() {
    return receiver->getPublicKey();
}

string Transaction::getSendersHash() {
    return sender->getPublicKey();
}

int Transaction::getAmount() {
    return amount;
}

bool Transaction::isHashValid() {
    return this->getId() == this->getHash();
}

string Transaction::toSString() {
    stringstream stream;
    stream << "Transaction ID: " << getId() << endl;
    stream << "Sender key:     " << getSendersHash() << endl;
    stream << "Receiver key:   " << getReceiversHash() << endl;
    stream << "Amount:         " << getAmount() << endl;

    return stream.str();
}