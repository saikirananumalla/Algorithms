#include <iostream>
#include<cstring>
#include <queue>
using namespace std;
class Qu{
public:
    int front;
    int rear;
    int size;
    int *A;
    int *C;
    Qu(){
        A=new int(5);
        front=rear=-1;
        size=5;
    }
    Qu(char c){
        C=new int(5);
        front=rear=0;
        size=5;
    }
    bool isFull();
    bool isEmpty();
    void enQ(int key);
    void deQ();
    void display();
    bool cisFull();
    //bool cisEmpty();
    void cenQ(int key);
    void cdeQ();
    void cdisplay();
};

bool Qu::isFull() {
    if(rear==size-1)
        return true;
    return false;
}
bool Qu::cisFull() {
    if((rear+1)%size==size)
        return true;
    return false;
}

bool Qu::isEmpty() {
    if(front==rear)
        return true;
    return false;
}

void Qu::enQ(int key) {
    if(isFull())
        return;
    A[++rear]=key;
}
void Qu::cenQ(int key) {
    if(cisFull())
        return;
    rear=(rear+1)%size;
    C[rear]=key;
}

void Qu::deQ() {
    if(isEmpty())
        return;
    front++;
}
void Qu::cdeQ() {
    if(isEmpty())
        return;
    front=(front+1)%size;
}
void Qu::display() {
    cout<<"display: ";
    for(int i=front+1;i<=rear;i++){
        cout<<A[i]<<flush;
        if(i<rear)
            cout<<"<-"<<flush;
    }
    cout<<endl;
}
void Qu::cdisplay() {
    cout << "display: ";
    int i = (front + 1) % size;
    while (i != (rear + 1) % size) {
        cout << C[i] << "<-";
    }
    cout << endl;
}
void showqueue(queue<int> q){
    if(q.empty())
        cout<<"Queue is empty\n";
    else{
        while(!q.empty()){
            cout<<q.front()<<"<-";
            q.pop();
        }
        cout<<endl;
    }
}
void showpq(priority_queue<int,vector<int>,greater<int>> q){
    if(q.empty())
        cout<<"Priority Queue is empty\n";
    else{
        while(!q.empty()){
            cout<<q.top()<<"<-";
            q.pop();
        }
        cout<<endl;
    }
}

int main() {
//    Qu q;
//    q.display();
//    q.enQ(10);
//    q.enQ(20);
//    q.enQ(15);
//    q.enQ(14);
//    q.display();
//    q.deQ();
//    q.display();
//    q.deQ();
//    q.deQ();
//    q.deQ();
//    q.deQ();
//    q.display();
//    Qu q('c');
//    q.cenQ(10);
//    q.cenQ(20);
//    q.cenQ(30);
//    q.cenQ(40);
//    q.cenQ(50);
//    q.cenQ(60);
//    q.cdisplay();
//    q.cdeQ();
//    q.cdeQ();
//    q.cdisplay();
//    q.cdeQ();
//    q.cdeQ();
//    q.cdisplay();
//    q.cenQ(1);
//    q.cenQ(2);
//    q.cenQ(3);
//    q.cdisplay();
//    queue<int> Q;
//    showqueue(Q);
//    Q.emplace(10);
//    Q.emplace(20);
//    Q.emplace(30);
//    Q.emplace(40);
//    Q.emplace(50);
//    showqueue(Q);
//    Q.pop();
//    cout<<Q.front()<<" is the front!\n";
//    cout<<Q.back()<<" is the back\n";
//    Q.push(45);
//    showqueue(Q);
//    cout<<Q.size()<<" is the size\n";
    priority_queue<int,vector<int>,greater<int>> pq;
    cout<<"MIN HEAP\n";
    showpq(pq);
    pq.emplace(15);
    pq.emplace(25);
    pq.emplace(20);
    pq.emplace(333);
    pq.emplace(2);
    showpq(pq);
    pq.pop();
    showpq(pq);
    cout<<pq.top()<<" is the top!\n";
    pq.push(45);
    showpq(pq);
    cout<<pq.size()<<" is the size of pq\n";

}
