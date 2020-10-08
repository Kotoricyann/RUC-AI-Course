/*************************************/
//AI-Course Code No.1
//Astar algorithm
//Written by FR Lv(Kotoricyann)
/*************************************/


#include<iostream>
#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#include<memory>
#include <cstdlib>
#include <cmath>


using namespace std;

int N;//N宫格

class Status
{
private:
    int layer;
    int id;
    int parentId;
    int score;
    vector<int> map;

    //基本操作
    void swap(int a, int b);
    int findPos();
    int moveUp();
    int moveDown();
    int moveLeft();
    int moveRight();
    int randomMove();

    //others
    bool operator<(const Status& a) const{ return score > a.score;};
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

    int getScore(){return score;};
    int countScore();

    vector<int> getMap(){return map;};

    //其他方法
    int move(int pos);
    void randomWalk(int times);
    void init();//初始状态
    void printOut();
};

struct cmp{
    bool operator()(shared_ptr<Status> a,shared_ptr<Status> b){
        return a->getScore() > b->getScore();
    }
};

class Astar
{
private:
    /* data */
    
    //closeset
public:
    Astar(/* args */);
    ~Astar();

    priority_queue<shared_ptr<Status>, vector<shared_ptr<Status>>, cmp> openSet;
    set<vector<int> > closeSet;

    void sovleOut(shared_ptr<Status> initial);


};

Astar::Astar(/* args */)
{
}

Astar::~Astar()
{
}

