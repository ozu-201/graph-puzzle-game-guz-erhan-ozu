//
// Created by ge028774 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_EDGE_H
#define GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_EDGE_H


class Edge {
private:
    int from;
    int to;
    int weight;
    Edge* next;
public:
    Edge();
    Edge(int from, int to, int weight);
    void setNext(Edge* _next);
    Edge* getNext() const;
    int getFrom() const;
    int getTo() const;
    int getWeight() const;
};


#endif