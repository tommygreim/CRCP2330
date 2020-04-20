#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

using namespace std;

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

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
