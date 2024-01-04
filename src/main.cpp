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

    Graph graph3(3);
    graph3.addWord("cat");
    graph3.addWord("cot");
    graph3.addWord("dog");
    graph3.addEdge("cat", "cot");
    graph3.addEdge("cot", "dog");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (3 letter words)\n";
    std::cout << "Shortest Path from 'cat' to 'dog' (BFS):\n";
    graph3.BFS("cat", "dog");
    std::cout << "Shortest Path from 'cat' to 'dog' (Dijkstra):\n";
    graph3.Dijkstra("cat", "dog");
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (4 letter words)
    Graph graph4(3);
    graph4.addWord("dark");
    graph4.addWord("bark");
    graph4.addWord("barn");
    graph4.addEdge("dark", "bark");
    graph4.addEdge("bark", "barn");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (4 letter words)\n";
    std::cout << "Shortest Path from 'dark' to 'barn' (BFS):\n";
    graph4.BFS("dark", "barn");
    std::cout << "Shortest Path from 'dark' to 'barn' (Dijkstra):\n";
    graph4.Dijkstra("dark", "barn");
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (5 letter words)
    Graph graph5(3);
    graph5.addWord("stone");
    graph5.addWord("store");
    graph5.addWord("score");
    graph5.addEdge("stone", "store");
    graph5.addEdge("store", "score");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (5 letter words)\n";
    std::cout << "Shortest Path from 'stone' to 'score' (BFS):\n";
    graph5.BFS("stone", "score");
    std::cout << "Shortest Path from 'stone' to 'score' (Dijkstra):\n";
    graph5.Dijkstra("stone", "score");
    std::cout << "------------------------------------------\n";

    return 0;

}