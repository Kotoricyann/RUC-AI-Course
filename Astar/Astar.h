/*************************************/
//AI-Course Code No.1
//Astar algorithm
//Written by FR Lv(Kotoricyann)
/*************************************/


#include<iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include<memory>
#include <cstdlib>


using namespace std;

int N;//N宫格

class Status
{
private:
    int layer;
    int id;
    int parentId;
    vector<int> map;

    //基本操作
    void swap(int a, int b);
    int findPos();
    int moveUp();
    int moveDown();
    int moveLeft();
    int moveRight();
    int randomMove();

public:
    Status(/* args */);
    ~Status();

    //变量操作
    int getLayer(){return layer;};
    void setLayer(int tmp){ layer=tmp; };

    int getId(){return id;};
    void setId(int tmp){ id=tmp; };

    int getPId(){return parentId;};
    void setPId(int tmp){ parentId=tmp; };

    //其他方法
    int move(int pos);
    void randomWalk(int times);
    int countScore();
    void printOut();
};



class Astar
{
private:
    /* data */
    //openset
    //closeset
public:
    Astar(/* args */);
    ~Astar();
};

Astar::Astar(/* args */)
{
}

Astar::~Astar()
{
}

