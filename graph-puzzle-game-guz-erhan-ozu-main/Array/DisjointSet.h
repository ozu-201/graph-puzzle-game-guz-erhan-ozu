//
// Created by ge028774 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_DISJOINTSET_H
#define GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_DISJOINTSET_H




#include "Set.h"

class DisjointSet {
private:
    Set* sets;
    int count;
public:
    DisjointSet(int* elements, int count);
    DisjointSet(int count);
    ~DisjointSet();
    int findSetRecursive(int index);
    int findSetIterative(int index);
    void unionOfSets(int index1, int index2);
};


#endif //GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_DISJOINTSET_H
