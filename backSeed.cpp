#include<iostream>
#include<fstream>
#include <bits/stdc++.h>

using namespace std;

uint32_t LCRNGR(uint32_t targetSeed) {
    targetSeed = 0xEEB9EB65 * targetSeed + 0xA3561A1;

    return targetSeed;
}

uint16_t getInitialSeeds(uint32_t targetSeed, int maxResults, ofstream &output) {
    int counter = 0;

    for (unsigned long int j = 1; j <  4294967295 && counter < maxResults; j++) {
        targetSeed = LCRNGR(targetSeed);
        if (targetSeed <= 0xFFFF) {
            counter++;

            cout << dec << counter << " Seed: " << hex << uppercase << setw(4) << setfill('0') << targetSeed << " | Advances: " << dec << j << endl;
            output << std::hex << "0x" << targetSeed;

            if (counter < maxResults) {
                 output << ", ";
            }

            if (counter % 10 == 0 && counter < maxResults) {
                output << endl;
            }
        }
    }
}

int main() {
    ofstream output;
    output.open("seeds.txt");
    uint32_t targetSeed;
    int maxResults;

    cout << "Insert the target Seed: ";
    cin >> std::hex >> targetSeed;
    cout << "Max results: ";
    cin >> std::dec >> maxResults;
    cout << endl;

    getInitialSeeds(targetSeed, maxResults, output);
    output.close();

    cout << endl;
    system("pause");
}
