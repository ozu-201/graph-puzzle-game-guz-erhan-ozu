//
// Created by ge028774 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_EDGELIST_H
#define GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_EDGELIST_H


#include "Edge.h"

class EdgeList {
private:
    Edge* head;
    Edge* tail;
public:
    EdgeList();
    ~EdgeList();
    bool isEmpty() const;
    Edge* search(int to) const;
    void insert(Edge* newEdge);
    Edge* getHead();
};


#endif
