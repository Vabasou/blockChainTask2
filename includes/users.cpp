#include "users.hpp"

void Users::generate_users(int number) {
    for (int i = 0; i < number; i++) {
        User user("UserNr-" + std::to_string(i+1), RND::getIntegerInRange(MINBALANCE, MAXBALANCE));

        vector<User>::iterator it = std::find_if(users.begin(), users.end(), [&user](User &u) {
            return u.getPublicKey() == user.getPublicKey();
        });

        while (it != users.end()) {
            User user("UserNr-" + std::to_string(i), RND::getIntegerInRange(MINBALANCE, MAXBALANCE));

            it = std::find_if(users.begin(), users.end(), [&user](User &u) {
                return u.getPublicKey() == user.getPublicKey();
            });
        }

        users.push_back(user);
    }
}

string Users::toSString() {
    stringstream stream;
    for (User user: users) {
        stream << "Name:            " << user.getName() << endl;
        stream << "Publick key:     " << user.getPublicKey() << endl;
        stream << "Current balance: " << user.getBalance() << endl;
    }

    return stream.str();
}

User* Users::getRandomUser() {
    return &users[RND::getIntegerInRange(0, users.size() - 1)];
}