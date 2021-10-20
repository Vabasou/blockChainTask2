#include "includes/libraries.hpp"
//#include "includes/hash.hpp"
#include "includes/block.hpp"

int main() {
    Blockchain letsTry;  

    time_t current;
    TransactionData data;
    data.amount = 1000;
    data.receiverKey = "Noneasdf";
    data.senderKey = "Noneasdf";
    data.timestamp = time(&current);

    string hash1 = "None";
    Block niceBlock(0, data, myHash(hash1));  

    niceBlock.mineBlock();

    // TransactionData data1;
    // time_t data1Time;
    // data1.amount = 100;
    // data1.receiverKey = "Joe";
    // data1.senderKey = "Sally";
    // data1.timestamp = time(&data1Time);

    // letsTry.addBlock(data1);

    // cout << "Is chain valid? " << letsTry.isChainValid() << endl;

    // TransactionData data2;
    // time_t data2Time;
    // data2.amount = 10000;
    // data2.receiverKey = "Johaness";
    // data2.senderKey = "Sallyalksjdghf";
    // data2.timestamp = time(&data2Time);

    // letsTry.addBlock(data2);

    // cout << "Is chain still valid? " << letsTry.isChainValid() << endl;

    // Block *hackBlock = letsTry.getLatestBlock();
    // hackBlock->data.amount = 3000000;
    // hackBlock->data.receiverKey = "Jon";

    // cout << "Now is the cahin still valid?: "<< letsTry.isChainValid() << endl;
}