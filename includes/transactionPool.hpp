#pragma once
#include "libraries.hpp"
#include "transaction.hpp"
#include "user.hpp"
#include "users.hpp"

class TransactionPool {
    private:
        vector<Transaction> transactionPool;
    
    public:
        void generateTransactionPool(Users &, int);
        Transaction getTransaction(int);
        vector<Transaction> getTransactions(int);
        int getTransactionNumber();
        void removeTransaction(Transaction &);
        void removeTransactions(vector<Transaction>&);
        string to_SString();
        void checkIdAndExecute();
        int candidates;
};