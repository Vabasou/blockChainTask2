#include "users.hpp"

Users::Users(int number) {
    for (int i = 0; i < number; i++) {
        string name = "UserNr-" + std::to_string(i+1);
        int balance = RND::getIntegerInRange(MINBALANCE, MAXBALANCE);
        User user(name, balance);
        this->users.push_back(user);
    }
}

string Users::toSString() {
    stringstream stream;
    for (User user: users) {
        stream << "Name:            " << user.getName() << endl;
        stream << "Publick key:     " << user.getPublicKey() << endl;
        stream << "Current balance: " << user.getBalance() << endl;
        stream << string(50, '*') << endl;
        stream << endl;
    }

    return stream.str();
}

User* Users::getRandomUser() {
    return &users[RND::getIntegerInRange(0, users.size() - 1)];
}