#include "Astar.h"

Status::Status(/* args */)
{
    map.reserve(N*N+1);
    map.resize(N*N);
    for (int i = 0; i < N*N-1 ; i++)
    {
        map[i]=i+1;
    }
    map[N*N]=0;
    layer = 0;
    id = 0;
    parentId = -1;
    score = -1;
}

Status::~Status()
{
}

void Status::swap(int a, int b){
    int tmp=map[a];
    map[a]=map[b];
    map[b]=tmp;
}

int Status::findPos(){
    for (int i = 0; i < N*N; i++)
    {
        if (map[i]==0)
        {
            return i;
        }
        
    }
    return -1;
}


int Status::moveUp(){
    int pos=findPos();
    if (pos<N)
    {
        return 0;
    }
    else
    {
        swap(pos,pos-N);
    }
    return 1;
}


int Status::moveDown(){
    int pos=findPos();
    if (pos<N*(N-1))
    {
        swap(pos,pos+N);
        return 1;
    }
    return 0;
}

int Status::moveLeft(){
    int pos=findPos();
    if (pos%N==0)
    {
        return 0;
    }
    swap(pos,pos-1);
    return 1;
}

int Status::moveRight(){
    int pos=findPos();
    if (pos%N==N-1)
    {
        return 0;
    }
    swap(pos,pos+1);
    return 1;
}

int Status::randomMove(){
    return move(rand()%4);
}

int Status::move(int pos){
    switch (pos)
    {
        case 0:
             return moveUp();
            break;
        case 1:
            return moveDown();
            break;
        case 2:
            return moveLeft();
            break;
        case 3:
            return moveRight();
            break;
        
        default:
            break;
    }
    return -1;

}

void Status::randomWalk(int times){
    int sum=0;
    while (sum<times)
    {
        sum += randomMove();
    }
    return;
}



void Status::printOut(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<map[i*N+j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}

int Status::countScore(){
    int fx = 0;
    int gx = layer;

    for (int i = 0; i < N*N; i++)
    {
        if (map[i]==0)
        {
            continue;
        }
        int t=map[i];
        int dis = abs(t-i-1);
        fx = fx + (dis/N) +(dis%N);
    }
    
    score = gx + fx;
    return score;
}

void Status::init(){
    setId(0);
    setPId(-1);
    setLayer(0);
}


void uniTestStatus(shared_ptr<Status> S){
    S->printOut();
    
    // S->move(2);
    // S->printOut();
    // S->move(3);
    // S->printOut();
    // S->move(3);
    // S->printOut();

    S->randomWalk(11);
    
    S->printOut();
    cout<<"score:"<<S->countScore()<<endl;
    return;
}

void uniTestAstar(Astar& A){
    shared_ptr<Status> p(new Status);
    p->randomWalk(20);
    p->countScore();

    shared_ptr<Status> q(new Status);
    q->randomWalk(10);
    q->countScore();

    A.openSet.push(p);
    A.openSet.push(q);

    while (!A.openSet.empty())
    {
        A.openSet.top()->printOut();
        cout<<A.openSet.top()->getScore()<<endl;
        if(A.closeSet.find( A.openSet.top()->getMap())==A.closeSet.end())A.closeSet.insert(A.openSet.top()->getMap());
        A.openSet.pop();

    }

    for (set<vector<int> >::iterator it = A.closeSet.begin(); it!= A.closeSet.end(); it++)
    {
        for (int i = 0; i < it->size(); i++)
        {
            cout<<(*it)[i]<<' ';
        }
        cout<<endl;
        
    }
    
    


    return;
}

void Astar::sovleOut(shared_ptr<Status> initial){



}



int main(){

    int randomTime=0;

    // cout<<"N=";
    // cin>>N;

    N=3;

    shared_ptr<Status> initial(new Status);

    // cout<<"random time=";
    // cin>>randomTime;

    randomTime = 20;

    initial->randomWalk(randomTime);

    Astar A;

    A.sovleOut(initial);



    system("pause");




    return 0;

}