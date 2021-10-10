#include "includes/libraries.hpp"
//#include "includes/hash.hpp"
#include "includes/block.hpp"

int main() {
    Blockchain letsTry;

    TransactionData data1;
    time_t data1Time;
    data1.amount = 100;
    data1.receiverKey = "Joe";
    data1.senderKey = "Sally";
    data1.timestamp = time(&data1Time);

    letsTry.addBlock(data1);

    cout << "Is chain valid? " << letsTry.isChainValid() << endl;
}