//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include <vector>
#include "Graph.h"
#include "../../Array/DisjointSet.h"
#include "../Queue.h"
#include "../../Array/Heap/MinHeap.h"

namespace list {


    bool Graph::diffByOne(std::string word1, std::string word2){
        int difference=0;

        if(word1.length()!=word2.length()){
            return false;
        } else {
            for(int i=0; i<word1.length(); i++){
                if(word1[i]!=word2[i]){
                    difference++;
                }
                if(difference>1){
                    return false;
                }
            }
        }
        return difference==1;
    }

    void Graph::createGraphWithLength(Graph& graph, const std::vector<std::string>& words){
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words.size(); j++){
                if(i!=j && graph.diffByOne(words[i], words[j])){
                    graph.addEdge(i,j,1);
                }
            }
        }
    }

    void Graph::createGraphByWordGroup(std::ifstream& turkishFile,std::ifstream& englishFile, int wordLength){
        std::vector<std::string> words;
        std::string word;

        while(turkishFile >> word){
            if(word.length() == wordLength){
                words.push_back(word);
            }
        }
        while(englishFile >> word){
            if(word.length() == wordLength){
                words.push_back(word);
            }
        }
        for(const auto& word1:words){
            addNode(word1);
            for(const auto& word2:words){
                if(word1!=word2 && diffByOne(word1,word2)){
                    int node1= wordToIndex[word1];
                    int node2 = wordToIndex[word2];
                    addEdge(node1,node2,1);
                }
            }
        }

    }

    void Graph::BFS(const std::string& startWord, const std::string& endWord){
        if(wordToIndex.find(startWord) == wordToIndex.end() || wordToIndex.find(endWord) == wordToIndex.end()){
            return;
        }
        int startNode = wordToIndex[startWord];
        int endNode = wordToIndex[endWord];
        std::vector<bool> visited(vertexCount,false);
        list::Queue queue;

        visited[startNode] = true;
        queue.enqueue(new Node(startNode));

        while(!queue.isEmpty()){
            Node* frontNode = queue.dequeue();
            int fromNode = frontNode->getData();
            delete frontNode;

            if(fromNode==endNode){
                return;
            }
            Edge* edge = edges[fromNode].getHead();
            while(edge!= nullptr){
                int toNode = edge->getTo();
                if(!visited[toNode]){
                    visited[toNode]=true;
                    queue.enqueue(new Node(toNode));
                }
                edge = edge->getNext();
            }
        }

    }
    Path* Graph::dijkstra(const std::string& startWord, const std::string& endWord){
        if(wordToIndex.find(startWord)==wordToIndex.end() || wordToIndex.find(endWord)==wordToIndex.end()){
            return nullptr;
        }
        int source =wordToIndex[startWord];
        int target = wordToIndex[endWord];
        Edge* edge;
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);

        for(int i=0; i<vertexCount; i++){
            heap.insert(HeapNode(shortestPaths[i].getDistance(),i));
        }
        while(!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            if(fromNode==target){
                break;
            }
            edge = edges[fromNode].getHead();
            while(edge!= nullptr){
                int toNode = edge->getTo();
                int newDistance = shortestPaths[fromNode].getDistance()+edge->getWeight();
                if(newDistance<shortestPaths[toNode].getDistance()){
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                    heap.update(heap.search(toNode),newDistance);
                }
                edge = edge->getNext();
            }
        }
        return &shortestPaths[target];
    }
    void Graph::addNode(const std::string& word){
        if(wordToIndex.find(word)==wordToIndex.end()){
            wordToIndex[word] = nextNodeIndex++;
        }
    }


    Graph::Graph(int _vertexCount) : AbstractGraph(_vertexCount){
        edges = new EdgeList[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = EdgeList();
        }
    }

    void Graph::addEdge(int from, int to) {
        Edge* edge = new Edge(from, to, 1);
        edges[from].insert(edge);
    }

    void Graph::addEdge(int from, int to, int weight) {
        Edge* edge = new Edge(from, to, weight);
        edges[from].insert(edge);
    }

    void Graph::addEdge(const std::string& word1, const std::string& word2){
        auto it1 = wordToIndex.find(word1);
        auto it2 = wordToIndex.find(word2);

        int from = it1->second;
        int to = it2->second;
        Edge* edge = new Edge(from,to,1);
        edges[from].insert(edge);
    }

    Graph::~Graph() {
        delete[] edges;
    }

    void Graph::connectedComponentsDisjointSet() {
        Edge* edge;
        int toNode;
        DisjointSet sets = DisjointSet(vertexCount);
        for (int fromNode = 0; fromNode < vertexCount; fromNode++){
            edge = edges[fromNode].getHead();
            while (edge != nullptr){
                toNode = edge->getTo();
                if (sets.findSetRecursive(fromNode) != sets.findSetRecursive(toNode)){
                    sets.unionOfSets(fromNode, toNode);
                }
                edge = edge->getNext();
            }
        }
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        Edge* edge;
        int toNode;
        edge = edges[fromNode].getHead();
        while (edge != nullptr){
            toNode = edge->getTo();
            if (!visited[toNode]){
                visited[toNode] = true;
                depthFirstSearch(visited, toNode);
            }
            edge = edge->getNext();
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        Edge* edge;
        int fromNode, toNode;
        Queue queue = Queue();
        queue.enqueue(new Node(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue()->getData();
            edge = edges[fromNode].getHead();
            while (edge != nullptr) {
                toNode = edge->getTo();
                if (!visited[toNode]){
                    visited[toNode] = true;
                    queue.enqueue(new Node(toNode));
                }
                edge = edge->getNext();
            }
        }
    }

    Path *Graph::bellmanFord(int source) {
        Edge* edge;
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                edge = edges[fromNode].getHead();
                while (edge != nullptr){
                    int toNode = edge->getTo();
                    int newDistance = shortestPaths[fromNode].getDistance() + edge->getWeight();
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                    edge = edge->getNext();
                }
            }
        }
        return shortestPaths;
    }

    Path *Graph::dijkstra(int source) {
        Edge* edge;
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            edge = edges[fromNode].getHead();
            while (edge != nullptr){
                int toNode = edge->getTo();
                int newDistance = shortestPaths[fromNode].getDistance() + edge->getWeight();
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
                edge = edge->getNext();
            }
        }
        return shortestPaths;
    }

    Edge *Graph::edgeList(int& edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                edgeCount++;
                edge = edge->getNext();
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                list[index] = Edge(edge->getFrom(), edge->getTo(), edge->getWeight());
                index++;
                edge = edge->getNext();
            }
        }
        return list;
    }

    void Graph::prim() {
        Path* paths = initializePaths(0);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(paths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            Edge* edge = edges[fromNode].getHead();
            while (edge != nullptr){
                int toNode = edge->getTo();
                if (paths[toNode].getDistance() > edge->getWeight()){
                    int position = heap.search(toNode);
                    heap.update(position, edge->getWeight());
                    paths[toNode].setDistance(edge->getWeight());
                    paths[toNode].setPrevious(fromNode);
                }
                edge = edge->getNext();
            }
        }
    }

}