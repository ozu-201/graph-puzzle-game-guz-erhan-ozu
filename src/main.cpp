//
// Created by ge028774 on 12/21/2023.
//

#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream myFile;
    myFile.open("turkish-dictionary.txt");
    std::string myLine;
    if ( myFile.is_open() ) {
        while ( myFile ) {
            std::getline (myFile, myLine);
            std::cout << myLine << '\n';
        }
    }
    else {
        std::cout << "Couldn't open file\n";
    }

    std::ifstream newFile;
    newFile.open("english-dictionary.txt");
    std::string newLine;
    if ( newFile.is_open() ) {
        while ( newFile ) {
            std::getline (newFile, newLine);
            std::cout << newLine << '\n';
        }
    }
    else {
        std::cout << "Couldn't open file\n";
    }

    return 0;

}