#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <bitset>

using namespace std;

void aInstruction(string& input);
void cInstruction(string& input);

int main(int argc, char** argv) {
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
            cInstruction(*i);
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

void cInstruction(string& input){
    string output = "111";
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
    cout <<"";
}
