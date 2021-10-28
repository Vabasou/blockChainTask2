#include "includes/libraries.hpp"
#include "includes/user.hpp"
#include "includes/users.hpp"
#include "includes/transaction.hpp"
#include "includes/block.hpp"
#include "includes/blockchain.hpp"
#include "includes/record.hpp"
#include "includes/transactionPool.hpp"

int main() {

    int userNumber = 1000;
    int transactionNumber = 10000;
    int blockTransactions = 100;
    int difficulty = 2;
    int index = 1;
    int numOfCandidates = 5;

    Blockchain blockchain;
    TransactionPool pool;

    cout << "Generating (" << userNumber << ") users..." << endl;
    Users users(userNumber);
    saveToFile(users.toSString(), "results/usersBeginning.txt");
    cout << "Completed!" << endl;
    cout << endl;

    cout << "Generating (" << transactionNumber << ") transactions..." << endl;
    pool.generateTransactionPool(users, transactionNumber);
    saveToFile(pool.to_SString(), "results/poolBeggining.txt");
    cout << "Completed!" << endl;

    string genesisBlockHash = myHash("Pirmas blokas");
    string prevBlockHash;

    stringstream stream;
    
    while(pool.getTransactionNumber() > 0) {
        prevBlockHash = blockchain.isEmpty() ? genesisBlockHash : blockchain.getLastBlockHash();
    
        vector<Block> blocks;
        for (int i = 0; i < numOfCandidates; i++) {
            vector<Transaction> transactions;
            transactions = pool.getTransactions(blockTransactions);

            Block candidate(prevBlockHash, difficulty);
            candidate.index = i;
            candidate.addTransactions(transactions);
            blocks.push_back(candidate);
        }

        Block iskastasBlokas;
        while(!iskastasBlokas.isMined) {
            for (int i = 0; i < numOfCandidates; i++) {
                blocks[i].mineBlock();
                if (blocks[i].isMined) {
                    iskastasBlokas = blocks[i];
                    break;
                }
            }
        }        

        cout << "Candidate index: " << iskastasBlokas.index << endl;

        pool.removeTransactions(iskastasBlokas.getTransactions());
        pool.checkIdAndExecute();

        blockchain.addBlock(iskastasBlokas);

        stream << "Block index: " << index << endl;
        stream << iskastasBlokas.toSString();
        stream << string(50, '*') << endl;

        index++;
    }

    saveToFile(stream.str(), "results/blocks.txt");
    saveToFile(pool.to_SString(), "results/poolEnding.txt");
    saveToFile(users.toSString(), "results/usersEnding.txt");
}