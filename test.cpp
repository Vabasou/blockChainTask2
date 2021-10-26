#include "includes/libraries.hpp"
#include "includes/hash.hpp"

int nonce = 0;
string prevBlockHash = "pirmas";

string getBlockHash() {
    stringstream stream;
    stream << prevBlockHash << getTimestamp() << 3 << 1.0 << nonce << getMerkleRoot();
    return myHash(stream.str());
}

void mine() {
    string startString(3, '0');

    do {
        nonce++;
        string blockHash = getBlockHash();
    } while (blockHash.substr(0, 3) != startString);

    cout << "Block mined:" << blockHash << endl;
}

int main() {

}