#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <bitset>
#include <unordered_map>

using namespace std;

void aInstruction(string& input);
void cInstruction(string& input, unordered_map<string,string>& compToBits, unordered_map<string,string>& destToBits, unordered_map<string,string>& jumpToBits);
void populateCompToBits(unordered_map<string,string>& compToBits);
void populateDestToBits(unordered_map<string,string>& destToBits);
void populateJumpToBits(unordered_map<string,string>& jumpToBits);

int main(int argc, char** argv) {
    unordered_map<string,string> compToBits;
    populateCompToBits(compToBits);
    unordered_map<string,string> destToBits;
    populateDestToBits(destToBits);
    unordered_map<string,string> jumpToBits;
    populateJumpToBits(jumpToBits);

    if(argc != 3){
        cout << "Invalid number of arguments" << endl;
        cout << "Correct Format: \t\"Assembler [Input file] [Output file]\"" << endl;
        cout << "Example: \t\"Assembler max.asm max.vm\"" << endl;
        exit(EXIT_SUCCESS);
    }

    ifstream asmIn(argv[1]);
    if(!asmIn.is_open()){
        cout << "\"" << argv[1] << "\" is an invalid input file. Please try again." << endl;
        exit(EXIT_SUCCESS);
    }

    list<string> theLines;
    char* buffer = new char[250];
    while(!asmIn.eof()){
        asmIn.getline(buffer, 249);
        string temp = buffer;
        theLines.push_back(temp);
    }

    //Remove blank and commented lines
    auto theEnd = theLines.end();
    for(auto i = theLines.begin(); i != theEnd; i++){
        if(i->empty()){
            theLines.erase(i--);
        }
        else if(*i == "\r"){
            theLines.erase(i--);
        }
        else if(i->substr(0, 2) == "//"){
            theLines.erase(i--);
        }
    }

    for(auto i = theLines.begin(); i != theLines.end(); i++){
        if(i->at(0) == '@'){
            aInstruction(*i);
        }
        else{
            cInstruction(*i, compToBits, destToBits, jumpToBits);
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void aInstruction(string& input){
    string output = "0";
    input.erase(input.begin());
    int deciAdr = atoi(input.c_str());
    bitset<15> binAdr(deciAdr);
    output += binAdr.to_string();
    input = output;
}

void cInstruction(string& input, unordered_map<string,string>& compToBits, unordered_map<string,string>& destToBits, unordered_map<string,string>& jumpToBits){
    char delimiter = '=';
    string dest = input.substr(0, input.find(delimiter));
    if(dest == input){
//        delimiter = ';';
//        dest = input.substr(0, input.find(delimiter));
        dest = "";
    }
    else {
        input.erase(0, input.find(delimiter) + 1);
    }
    delimiter = ';';
    string comp = input.substr(0, input.find(delimiter));
    input.erase(0, input.find(delimiter));
    string jump = input;
    if(jump.find(';') == 0){
        jump.erase(jump.begin());
    }

    string a;
    //Tests if comp contains M, if so set a to 1
    if(comp.find('M') != string::npos){
        a = "1";
    }
    else {
        a = "0";
    }
    comp = compToBits.find(comp)->second;
    dest = destToBits.find(dest)->second;
    jump = jumpToBits.find(jump)->second;

    input = "111" + a + comp + dest + jump;
}

void populateCompToBits(unordered_map<string,string>& compToBits){
    compToBits.insert(pair<string,string>("0", "101010"));
    compToBits.insert(pair<string,string>("", "101010"));
    compToBits.insert(pair<string,string>("1", "111111"));
    compToBits.insert(pair<string,string>("-1", "111010"));
    compToBits.insert(pair<string,string>("D", "001100"));
    compToBits.insert(pair<string,string>("A", "110000"));
    compToBits.insert(pair<string,string>("M", "110000"));
    compToBits.insert(pair<string,string>("!D", "001101"));
    compToBits.insert(pair<string,string>("!A", "110001"));
    compToBits.insert(pair<string,string>("!M", "110001"));
    compToBits.insert(pair<string,string>("-D", "001111"));
    compToBits.insert(pair<string,string>("-A", "110011"));
    compToBits.insert(pair<string,string>("-M", "110011"));
    compToBits.insert(pair<string,string>("D+1", "011111"));
    compToBits.insert(pair<string,string>("A+1", "110111"));
    compToBits.insert(pair<string,string>("M+1", "110111"));
    compToBits.insert(pair<string,string>("D-1", "001110"));
    compToBits.insert(pair<string,string>("A-1", "110010"));
    compToBits.insert(pair<string,string>("M-1", "110010"));
    compToBits.insert(pair<string,string>("D+A", "000010"));
    compToBits.insert(pair<string,string>("D+M", "000010"));
    compToBits.insert(pair<string,string>("D-A", "010011"));
    compToBits.insert(pair<string,string>("D-M", "010011"));
    compToBits.insert(pair<string,string>("A-D", "000111"));
    compToBits.insert(pair<string,string>("M-D", "000111"));
    compToBits.insert(pair<string,string>("D&A", "000000"));
    compToBits.insert(pair<string,string>("D&M", "000000"));
    compToBits.insert(pair<string,string>("D|A", "010101"));
    compToBits.insert(pair<string,string>("D|M", "010101"));
}

void populateDestToBits(unordered_map<string,string>& destToBits){
    destToBits.insert(pair<string,string>("", "000"));
    destToBits.insert(pair<string,string>("M", "001"));
    destToBits.insert(pair<string,string>("D", "010"));
    destToBits.insert(pair<string,string>("MD", "011"));
    destToBits.insert(pair<string,string>("A", "100"));
    destToBits.insert(pair<string,string>("AM", "101"));
    destToBits.insert(pair<string,string>("AD", "110"));
    destToBits.insert(pair<string,string>("AMD", "111"));
}

void populateJumpToBits(unordered_map<string,string>& jumpToBits){
    jumpToBits.insert(pair<string,string>("", "000"));
    jumpToBits.insert(pair<string,string>("JGT", "001"));
    jumpToBits.insert(pair<string,string>("JEQ", "010"));
    jumpToBits.insert(pair<string,string>("JGE", "011"));
    jumpToBits.insert(pair<string,string>("JLT", "100"));
    jumpToBits.insert(pair<string,string>("JNE", "101"));
    jumpToBits.insert(pair<string,string>("JLE", "110"));
    jumpToBits.insert(pair<string,string>("JMP", "111"));
}
