#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};

class CLL{
public:
   Node * root;
   Node * newnode(int key);
   void display();
   void Create(int *A,int key);
   void Insert(int index,int x);
   int Delete(int key);
   int Length();
};

Node *CLL::newnode(int key) {
    Node* t=new Node;
    t->data = key;
    t->next= nullptr;
    return t;
}

void CLL::display() {
    Node* p=root;
    do{
        if(root== nullptr){
            cout<<"List is empty\n";
            break;
        }
        cout<<p->data<<"->";
        p=p->next;

    }
    while(p!=root);
    cout<<"\n";

}

void CLL::Create(int A[],int key) {
    Node *t,*last;
    root=newnode(A[0]);
    root->next=root;
    last=root;
    for(int i=1;i<key;i++){
        t=newnode(A[i]);
        t->next=root;
        last->next=t;
        last=t;
    }

}
int CLL::Length()
{
    int len=0;
    Node *p=root;
    do
    {
        len++;
        p=p->next;

    }while(p!=root);
    return len;
}
void CLL::Insert(int index, int x)
{
    Node *t;Node*p=root;
    int i;
    if(index<0 || index > Length())
        return;

    if(index==0)
    {
        t=new Node;
        t->data=x;
        if(root==NULL)
        {
            root=t;
            root->next=root;
        }
        else
        {
            while(p->next!=root)p=p->next;
            p->next=t;
            t->next=root;
            root=t;
        }

    }
    else
    {
        for(i=0;i<index-1;i++)p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}
int CLL::Delete(int index)
{
     Node *p=root;
     Node *q;
    int i,x;

    if(index <0 || index >Length())
        return -1;
    if(index==1)
    {
        while(p->next!=root)p=p->next;
        x=root->data;
        if(root==p)
        {
            delete root;
            root=NULL;
        }
        else
        {
            p->next=root->next;
            delete root;
            root=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

int main() {
    CLL l;
    int arr[]={2,3,4,5,6};
    l.display();
    l.Create(arr,5);
    l.display();
    l.Insert(2,10);
    l.Insert(5,1);
    l.display();
    l.Delete(1);
    l.display();

    return 0;
}
