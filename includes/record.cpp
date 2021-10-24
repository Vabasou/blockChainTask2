#include "record.hpp"

void saveToFile(string stringName, string fileName) {
    ofstream fr (fileName);
    fr << stringName;
    fr.close();
}

void saveBlockToFile(string stringName, string fileName, int blockNr) {
    ofstream fr (fileName);
    if (blockNr != 0) {
        fr << "Block: " << blockNr << endl;
        fr << stringName << endl;
        fr << string(50, '*') << endl;
    }
    fr.close();
}