/*+++ Task +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
* |  |
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* +++ Libs +++ */
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


/* +++ Puzzle input +++ */
std::string input = "abc\\n\\na\\nb\\nc\\n\\nab\\nac\\n\\na\\na\\na\\na\\n\\nb\\n\\n";

/* Gets the list Input from .txt file. */
std::string getInput() {
    std::ifstream file("./Input.txt");
    std::string str; 

    /* Looks where the input is located. */
    getline(file, str);
    int line = str.find("day06:", 0);
    if(line == std::string::npos && str.substr(line+6, 2).find_first_not_of("0123456789") != std::string::npos)
        return str;
    line = std::stoi(str.substr(line+6, 2), nullptr, 0);
    
    /* Jumps to the requested line: */
    for(int i=1; i<line; i++) {
        getline(file, str);
    }

    return str;
};

/* +++ Part-1 +++ */
int part1() {
    int questions = 0;
    int lastP = 0;
    std::string group;

    /* Goes throug the list. */
    for(int i=0; i<input.length(); i++) {
        /* Checks for new line. */
        if(input.substr(i, 2)=="\\n") {
            group += input.substr(lastP, i-lastP); /* Saves the current line. */
            lastP = i+2;

            /* New Group. */
            if(input.substr(i+2, 2)=="\\n") {
                std::map<std::string, bool> buffer;

                for(int j=0; j<group.length(); j++)
                    buffer[group.substr(j, 1)] = true;

                questions += buffer.size();
                std::cout << buffer.size() << std::endl;
                group = "";
            }
        }
    }

    return questions;
}

int main(void) {
    input = getInput();

    /* Prints the results here: */
    std::cout << "Part1: " << part1() << std::endl;

    return 0;
}