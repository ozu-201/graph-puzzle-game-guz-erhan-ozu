//
// Created by ge028774 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_PATH_H
#define GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_PATH_H



class Path {
private:
    int distance;
    int previous;
public:
    Path(int distance, int previous);
    Path() = default;
    int getDistance() const;
    void setDistance(int _distance);
    void setPrevious(int _previous);
};



#endif //GRAPH_PUZZLE_GAME_GUZ_ERHAN_OZU_MAIN_PATH_H
