#include "includes/libraries.hpp"
#include "includes/user.hpp"
#include "includes/users.hpp"
#include "includes/transaction.hpp"
#include "includes/block.hpp"
#include "includes/blockchain.hpp"
#include "includes/record.hpp"
#include "includes/transactionPool.hpp"

void mineBlocks(Block &block, int numOfCandidates, vector<Transaction> &transactions) {
    vector <Block> blocks;
    blocks.reserve(numOfCandidates);
    for (int i = 0; i < numOfCandidates; i++) {
        blocks.emplace_back(block);
    }

    for (Block &block : blocks) {

    }
}

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
        if (!blockchain.isEmpty()) {
            prevBlockHash = blockchain.getLastBlockHash();
        }
        else {
            prevBlockHash = genesisBlockHash;
        }

        Block block(prevBlockHash, difficulty, 1.0);

        vector<Transaction> transactions;
        transactions = pool.getTransactions(blockTransactions);

        block.addTransactions(transactions);

        cout << "Mining block: " << index << endl;
        auto start = std::chrono::high_resolution_clock::now();
        block.mine();
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        cout << "Mining completed" << endl;
        cout << elapsed.count() << endl;

        pool.removeTransactions(transactions);
        pool.checkIdAndExecute();

        blockchain.addBlock(block);

        stream << "Block index: " << index << endl;
        stream << block.toSString();
        stream << string(50, '-') << endl;

        index++;
    }

    saveToFile(stream.str(), "results/blocks.txt");
    saveToFile(pool.to_SString(), "results/poolEnding.txt");
    saveToFile(users.toSString(), "results/usersEnding.txt");
}