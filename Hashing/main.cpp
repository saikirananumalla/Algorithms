#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
class chaining{
public:
    Node* *HT;
    chaining();
    Node * newnode(int key);
    int hash(int key);
    void Insert(int key);
    int search(int key);

};
class linearprobe{
public:
    int *HT;
    int size;
    linearprobe(){
        HT=new int(10);
        size=10;
        HT[10]={};
    }
    linearprobe(int sz){
        this->size=sz;
        HT=new int(size);
    }
    int hash(int key){return key%10;}
    int linear(int index){
        while(HT[index%10]!=0)
            index++;
        return index%10;
    }
    void insert(int key){
        int index=hash(key);
        int idx=linear(index);
        HT[idx]=key;
    }
    int search(int key){
        int index=hash(key);
        while(HT[index%10]!=key){
            index++;
            if(HT[index%10]==0)
                return -1;
        }
        return index%10;
    }

};

chaining::chaining() {
    HT=new Node*[10];
    for(int i=0;i<10;i++)
        HT[i]= nullptr;
}

int chaining::hash(int key) {
    return key%10;
}

void chaining::Insert(int key) {
    int hashindex=hash(key);
    if(HT[hashindex]==nullptr)
        HT[hashindex]=newnode(key);
    else{
        Node *p=HT[hashindex];
        Node *q=HT[hashindex];
        while(q!= nullptr && q->data<key){
            p=q;
            q=q->next;
        }
        Node*t=newnode(key);
        if(p==HT[hashindex]) {
            t->next = p;
            HT[hashindex] = t;
        }
        else{
            t->next=q->next;
            q->next=p;
        }

    }
}

Node *chaining::newnode(int key) {
    Node *t=new Node;
    t->data=key;
    t->next= nullptr;
    return t;
}

int chaining::search(int key) {
    int hashindex=hash(key);
    Node*p=HT[hashindex];
    while(p){
        if(p->data==key)
            return 1;
        p=p->next;
    }
    return 0;
}

int main() {
//    chaining ht;
//    int A[]={10,22,32,12,65,55,88};
//    ht.Insert(10);
//    ht.Insert(22);
//    ht.Insert(32);
//    ht.Insert(12);
//    ht.Insert(65);
//    ht.Insert(55);
//    ht.Insert(88);
//    while(1){
//        cout<<"Enter 1 to search and anything else to quit \n";
//        int key;
//        cin>>key;
//        switch (key) {
//            case 1:{
//                cout<<"enter element: ";
//                int x;
//                cin>>x;
//                ht.search(x)==1?cout<<"Positive\n":cout<<"Negative\n";
//                break;
//            }
//            default:
//                cout<<"Ok BYE!";
//                exit(0);
//        }
//    }
linearprobe lp;
lp.insert(10);
lp.insert(12);
lp.insert(22);
lp.insert(32);
lp.insert(42);
lp.insert(52);
lp.insert(62);
lp.insert(11);
cout<<lp.search(11);
return 0;

}
