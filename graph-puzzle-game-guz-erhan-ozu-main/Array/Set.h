//
// Created by ge028774 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_SET_H
#define GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_SET_H




class Set {
private:
    int data;
    int parent;
    int depth;
public:
    Set(int data, int index);
    Set();
    int getParent() const;
    int getDepth() const;
    void setParent(int parent);
    void incrementDepth();
};


#endif //GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_SET_H
