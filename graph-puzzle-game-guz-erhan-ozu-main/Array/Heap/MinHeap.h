//
// Created by ge028774 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_MINHEAP_H
#define GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_MINHEAP_H



#include "Heap.h"

class MinHeap : public Heap{
protected:
    void percolateDown(int no) override;
    void percolateUp(int no) override;
public:
    explicit MinHeap(int N);
    void update(int k, int newValue) override;
};


#endif //GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_MINHEAP_H
