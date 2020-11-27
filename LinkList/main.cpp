//
// Created by saikirun on 20/08/20.
//
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};
class Linklist{
public:
    Node *root;
    Linklist(){root=nullptr;}
    void Append(int key){
        if(root== nullptr){
            Node* t= new Node;
            t->data=key;
            t->next= nullptr;
            root=t;
        }
        else{
            Node* p= root;
            Node* t= new Node;
            t->data=key;
            t->next= nullptr;
            while(p->next){
                p=p->next;
            }
            p->next=t;

        }
    }
    void Display() const;
    int midpoint();
    int Delete(int key);
    int isSorted();
    void duplicates();
    void reverse();
    int CheckLoop();
    //void createloop();
    Node* Merge(Node *p,Node *q);
};

void Linklist::Display() const {
    if (root== nullptr)
        cout<<"Link list is empty\n";
    else{
        Node* p=root;
        while(p->next){
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<p->data;
        cout<<endl;
    }

}

int Linklist::midpoint() {
    Node*p=root;
    Node*q=root;
    while(p){
        p=p->next;
        if(p)p=p->next;
        if(p)q=q->next;
    }

    return q->data;
}

int Linklist::Delete(int key) {
    Node* p=root; Node*q= nullptr;
    while(p!= nullptr && p->data!=key){
        q=p;
        p=p->next;
    }
    if(p==root){
        root=p->next;
        int x = p->data;
        delete p;
        return x;
    }
    else if (p== nullptr){
        return -1;
    }
    else{
        q->next=p->next;
        int y = p->data;
        delete p;
        return y;
    }


}

int Linklist::isSorted() {
    int x=INT32_MIN;
    Node* p=root;
    while(p!= nullptr){
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void Linklist::duplicates() {
    Node*p; Node *temp;
    Node*q=root;
    while(q!=NULL){
        p=q;
        q=q->next;
        if(p->data==q->data){
            p->next=q->next;
            temp=q;
            q=p->next;
            delete temp;
        }

    }
}

void Linklist::reverse() {
    Node *r=root;
    Node *p;
    Node *q= nullptr;
    while(r!= nullptr){
        p=q;
        q=r;
        r=r->next;
        q->next=p;
    }
    root=q;
    cout<<"The list is reversed\n";
}

int Linklist::CheckLoop() {
    Node*p=root;
    Node*q=root;
    do{
        q=q->next;
        if (q) q=q->next;
        if(q) p=p->next;

    }
    while(q!= nullptr && q!=p);
    if(q== nullptr)
        return 1;
    if(q==p)
        return 2;
}

//void Linklist::createloop() {
//    Node* p=root;
//    p=p->next;
//    Node*q =root;
//    while(q->next!= nullptr)
//        q=q->next;
//    q->next=p;
//}

int main(){
    Linklist l;
    l.Display();
    l.Append(10);
    l.Append(20);
    l.Append(30);
    l.Append(40);
    l.Append(50);
    l.Append(60);
    l.Append(70);
    //l.Append(80);
    l.Display();
    cout<<l.midpoint()<<"Is the MID\n";
    cout<<l.Delete(70)<<"Is deleted"<<endl;
    cout<<l.Delete(50)<<"Is deleted"<<endl;
    l.Display();
    l.Append(25);
    l.Append(25);
    l.Display();
    l.duplicates();
    l.Display();
    if(l.isSorted()==1) cout<<"The linklist is sorted \n";
    if(l.isSorted()==0) cout<<"The linklist isn't sorted \n";
    //cout<<l.midpoint()<<"Is the MID\n";
    l.reverse();
    l.Display();
    //l.createloop();
    cout<<l.CheckLoop()<<endl;
    return 0;
}


