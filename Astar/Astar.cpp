#include "Astar.h"

int Status::num = 0;

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

// Status::Status(const Status &obj)
// {
//     cout<<"�������캯��"<<endl;
//     id=obj.id;
//     parentId=obj.id;
//     layer=obj.layer+1;
//     for (int i = 0; i < obj.map.size(); i++)
//     {
//         map[i]=obj.map[i];
//     }
// }

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
            cout<<setw(3)<<map[i*N+j]<<' ';
        }
        cout<<endl;
    }
    //cout<<getId()<<' '<<getPId()<<' '<<getLayer()<<' '<<getScore()<<endl;
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

void Status::derive(shared_ptr<Status> obj){
    //cout<<"copy"<<endl;
    id=++num;
    parentId=obj->getId();
    layer=obj->getLayer()+1;
    score=obj->getScore();
    for (int i = 0; i < obj->getMap().size(); i++)
    {
        map[i]=obj->getMap()[i];
    }
}
int Status::isKey(){
    for (int i = 0; i < map.size()-1; i++)
    {
        if (map[i]!=i+1)
        {
            return 0;
        }
        
    }
    return 1;
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

void printOutCloseSet(set<vector<int> > cs){

    for (set<vector<int> >::iterator it = cs.begin(); it!= cs.end(); it++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout<<(*it)[i*N+j]<<' ';
            }
            cout<<endl;
            
        }
        cout<<endl;
        
    }
}

void Astar::prinOutPathSet(){
    for (vector<Status>::iterator it = pathSet.begin(); it != pathSet.end(); it++)
    {
        it->printOut();
        //it->printPara();
    }
    
}


void Astar::sovleOut(shared_ptr<Status> initial){
    openSet.push(initial);

    while (!openSet.empty())
    {
        shared_ptr<Status> pt = openSet.top();
        closeSet.insert(pt->getMap());
        pathSet.push_back(*pt);
        openSet.pop();
        
        for (int i = 0; i < 4; i++)//���ĸ���������
        {
            shared_ptr<Status> tmp(new Status);
            tmp->derive(pt);
            if (tmp->move(i)==1)
            {
                // tmp->printOut();
                // tmp->printPara();
                if (tmp->isKey()==1)
                {
                    /* return and find answer */
                    cout<<"----------------------------------"<<endl;
                    cout<<"find answers!!"<<endl;
                    cout<<"----------------------------------"<<endl;
                    findPath(tmp);
                    return;
                }
                
                set<vector<int> >::iterator it;
                it=closeSet.find(tmp->getMap());
                if (it==closeSet.end() )
                {
                    tmp->countScore();
                    openSet.push(tmp);
                }
                
            }
            
        }
        
    }
    //printOutCloseSet(closeSet);
    //prinOutPathSet();
}


void Astar::findPath(shared_ptr<Status> final){
    vector<shared_ptr<Status> > stack;

    stack.push_back(final);
    int pid = final->getPId();
    int step=0;

    while (pid!=-1)
    {
        shared_ptr<Status> next = findById(pid);
        stack.push_back(next);
        pid=next->getPId();
    }
    step=stack.size()-1;
    while (!stack.empty())
    {
        shared_ptr<Status> tmp = stack.back();
        tmp->printOut();
        cout<<endl;
        stack.pop_back();
    }
    cout<<"number of steps:"<<step<<endl;

}

shared_ptr<Status> Astar::findById(int id){
    shared_ptr<Status> key(new Status);
    for (vector<Status>::iterator it = pathSet.begin(); it != pathSet.end() ; it++)
    {
        if (it->getId()==id)
        {
            key->setId(it->getId());
            key->setPId(it->getPId());
            key->setLayer(it->getLayer());
            key->setMap(it->getMap());
            key->setScore(it->getScore());
            return key;
        }
        
    }
    return NULL;
    

}

void uniTestStatus(shared_ptr<Status> S){
    S->printOut();
    
    // S->move(2);
    // S->printOut();
    // S->move(3);
    // S->printOut();
    // S->move(3);
    // S->printOut();

    //S->randomWalk(11);

    shared_ptr<Status> Q(new Status);
    Q->derive(S);
    Q->move(3);
    Q->countScore();
    Q->printOut();
    cout<<"score:"<<Q->countScore()<<endl;
    return;
}

int main(){

    int randomTime=0;

    cout<<"���������N=";
    cin>>N;

    //N=3;

    shared_ptr<Status> initial(new Status);
    initial->init();

    cout<<"������Ҵ�����random time=";
    cin>>randomTime;

    //randomTime = 10;

    initial->randomWalk(randomTime);
    initial->countScore();
    initial->printOut();

    //uniTestStatus(initial);
    Astar A;
    A.sovleOut(initial);
    
    system("pause");
    return 0;
}