#include <iostream>
#include <fstream>
#include "Lexer.h"
#include <sstream>
#include <vector>
#include "Automaton.h"
using namespace std;
int main(int argc, char* argv[]) {


    if(argc < 2) {
        cerr << "Please provide the name of the input file";
        return 1;
    }
   // cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);

    if(!in) {
        cout << "Not able to open " << argv[1] << " for input " << endl;
        return 2;
    }

    Lexer inputLexer = Lexer();
    string line = "";
    while(in.peek() != EOF) {
        line.push_back(in.get());
    }

    inputLexer.Run(line);

    if(in.peek() == EOF) {
        inputLexer.FileEnd();
    }

    inputLexer.ToString();





    return 0;
}
