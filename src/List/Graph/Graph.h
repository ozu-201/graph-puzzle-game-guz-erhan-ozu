//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include <fstream>
#include "EdgeList.h"
#include "../../General/AbstractGraph.h"
#include <unordered_map>
#include <vector>

namespace list {

    class Graph : public AbstractGraph{
    private:
        EdgeList *edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void connectedComponentsDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source);
        void prim();
        bool diffByOne(std::string word1, std::string word2);
        void createGraphWithLength(Graph& graph, const std::vector<std::string>& words);
        void createGraphByWordGroup(std::ifstream& turkishFile,std::ifstream& englishFile, int wordLength);
        std::vector<std::string> words;
        std::unordered_map<std::string, int> wordToIndex;


        Path *dijkstra(const std::string &startWord, const std::string &endWord);

        void BFS(const std::string &startWord, const std::string &endWord);

        void addEdge(const std::string &word1, const std::string &word2);

        void addWord(const std::string &word1);

    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
        Edge* edgeList(int& edgeCount) override;


        void addNode(const std::string &word);


        int nextNodeIndex;

    };

}
#endif //DATASTRUCTURES_CPP_GRAPH_H
