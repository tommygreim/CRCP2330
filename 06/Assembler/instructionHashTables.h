//
// Created by Tommy on 4/24/2020.
//

#ifndef ASSEMBLER_INSTRUCTIONHASHTABLES_H
#define ASSEMBLER_INSTRUCTIONHASHTABLES_H

#include <unordered_set>

using namespace std;

class instructionHashTables {
public:
    unordered_set<string,string> compToBits;
    static unordered_map<string,string> destToBits;
    static unordered_map<string,string> jumpToBits;
};
#endif //ASSEMBLER_INSTRUCTIONHASHTABLES_H
