#include "user.hpp"
#include "hash.hpp"
#include "RND.hpp"

User::User(string name, int balance) {
    this->name = name;
    this->balance = balance;

    int randomInt = RND::getIntegerInRange(0, 1000000);
    string publicKeyAsString = std::to_string(time(nullptr)) + std::to_string(randomInt);

    this->publicKey = myHash(publicKeyAsString);
}

void User::addMoney(int amount) {
    this->balance += amount;
}

void User::withdrawMoney(int amount) {
    this->balance -= amount;
}

int User::getBalance() {
    return this->balance;
}

string User::getName() {
    return this->name;
}

string User::getPublicKey() {
    return this->publicKey;
}

string User::toSString() {
    stringstream stream;

    stream << "name: " << this->name << endl;
    stream << "balance: " << this->balance << endl;
    stream << "public key: " << this->publicKey << endl;

    return stream.str();
}
