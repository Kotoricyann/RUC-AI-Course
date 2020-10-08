#include "Astar.h"

Status::Status(/* args */)
{
    map.resize(N*N+1);
    for (int i = 0; i < N*N-1 ; i++)
    {
        map[i]=i+1;
    }
    map[N*N]=0;
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
    int countScore();


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
    return;
}





int main(){

    N=3;
    shared_ptr<Status> S(new Status);
    uniTestStatus(S);
    S.reset();
    system("pause");
    return 0;

}