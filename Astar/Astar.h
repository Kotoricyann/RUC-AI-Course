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
#include <iomanip>


using namespace std;

int N;//N����
#define pathPair make_pair<int, shared_ptr<Status> >

class Status
{
private:
    int layer;
    int id;
    int parentId;
    int score;
    static int num;//״̬�ܱ��
    vector<int> map;

    //��������
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
    //Status(const Status &obj);
    ~Status();
    

    //��������
    int getLayer(){return layer;};
    void setLayer(int tmp){ layer=tmp; };

    int getId(){return id;};
    void setId(int tmp){ id=tmp; };

    int getPId(){return parentId;};
    void setPId(int tmp){ parentId=tmp; };

    int getScore(){return score;};
    int countScore();
    void setScore(int tmp){score=tmp;};

    vector<int> getMap(){return map;};
    void setMap(vector<int> tmp){
        for (int i = 0; i < tmp.size(); i++)
        {
            map[i]=tmp[i];
        }
        
    };

    //��������
    int move(int pos);
    void randomWalk(int times);
    void init();//��ʼ״̬
    void printOut();
    void printPara(){ cout<<"id:"<<id<<" pid:"<<parentId<<" Layer:"<<layer<<" score:"<<score<<endl;};
    void derive(shared_ptr<Status> obj);
    int isKey();
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
    vector<Status> pathSet;

    void sovleOut(shared_ptr<Status> initial);
    void findPath(shared_ptr<Status> final);
    void prinOutPathSet();

    shared_ptr<Status> findById(int id);


};

Astar::Astar(/* args */)
{
}

Astar::~Astar()
{
}

