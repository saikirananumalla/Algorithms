#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
class Tree{
public:
    Node* root;
    Node * newnode(int key){
        Node *t=new Node;
        t->data=key;
        t->lchild=t->rchild= nullptr;
        return t;
    }
    Tree(){
        root= nullptr;
    }
    void createtree();
    void preorder(Node *p);
    void preorder(){preorder(root);};
    void inorder(Node *p);
    void inorder(){inorder(root);}
    void postorder(Node *p);
    void postorder(){postorder(root);}
    void levelorder();
    void ipreorder();
    void iinorder();
    void ipostorder();
    int height(Node *p);
    int countnodes(Node *p);
    int countleaf(Node *p);
    int countdeg1(Node *p);
    int countdeg2(Node *p);
    int sum(Node *p);
    int iheight(Node *p);
    int parminusson(Node *p);
    void spiralorder();
};

void Tree::createtree() {
    int x;
    queue<Node*> q;
    int r;
    cout<<"Enter the root value of tree: ";
    cin>>r;
    root=newnode(r);
    q.emplace(root);
    Node *a,*b;
    while(!q.empty()){
        a=q.front();
        q.pop();
        cout<<"Enter the left child of "<<a->data<<" : "<<flush;
        cin>>x;
        if(x!=-1){
            a->lchild=newnode(x);
            q.emplace(a->lchild);
        }
        cout<<"Enter the right child of "<<a->data<<" :"<<flush;
        cin>>x;
        if(x!=-1){
            a->rchild=newnode(x);
            q.emplace(a->rchild);
        }


    }
    cout<<endl;
}

void Tree::preorder(Node *p) {
    if(p) {
        cout << p->data << ", " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void Tree::inorder(Node *p) {
    if(p) {
        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}
void Tree::postorder(Node *p) {
    if(p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::levelorder() {
    int x;
    Node* p;
    queue<Node*> q;
    q.emplace(root);
    cout<<root->data<<"|";
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild){
            q.emplace(p->lchild);
            cout<<p->lchild->data<<"|";
        }
        if(p->rchild){
            q.emplace(p->rchild);
            cout<<p->rchild->data<<"|";
        }

    }
    cout<<endl;

}

void Tree::ipreorder() {
    stack<Node*> stk;
    Node *p=root;
    int x;
    while(p!= nullptr || !stk.empty()){
        if(p){
            cout<<p->data<<"|";
            stk.push(p);
            p=p->lchild;
        }
        else{
            p=stk.top();
            stk.pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}
void Tree::iinorder() {
    stack<Node*> stk;
    Node *p=root;
    int x;
    while(p!= nullptr || !stk.empty()){
        if(p){
            stk.push(p);
            p=p->lchild;
        }
        else{
            p=stk.top();
            cout<<p->data<<"|";
            stk.pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}

void Tree::ipostorder() {
    stack<long int> stk;
    long int x;
    Node *p=root;
    while(!stk.empty() || p){
        if(p){
            stk.emplace((long int)p);
            p=p->lchild;
        }
        else{
            if(stk.top()<0){
                x=stk.top();
                stk.pop();
                x=x*(-1);
                cout<<((Node *)x)->data<<"|";
                p= nullptr;
            }
            else{
                x=stk.top();
                p=(Node *)stk.top();
                x=x*(-1);
                stk.pop();
                stk.push(x);
                p=p->rchild;
            }
        }
    }
    cout<<endl;

}

int Tree::countnodes(Node *p) {
    int x,y;
    if(p) {
        x = countnodes(p->lchild);
        y = countnodes(p->rchild);
        return x+y+1;
    }
    return 0;
}
int Tree::height(Node* p){
    int x,y;
    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int Tree::countleaf(Node *p) {
    int x,y;
    if(p){
        x=countleaf(p->lchild);
        y=countleaf(p->rchild);
        if(p->lchild== nullptr && p->rchild == nullptr)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int Tree::countdeg2(Node *p) {
    int x,y;
    if(p){
        x=countdeg2(p->lchild);
        y=countdeg2(p->rchild);
        if(p->lchild!= nullptr && p->rchild != nullptr)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int Tree::countdeg1(Node *p) {
    int x,y;
    if(p){
        x=countdeg1(p->lchild);
        y=countdeg1(p->rchild);
        if(p->lchild!= nullptr ^ p->rchild != nullptr)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int Tree::sum(Node *p) {
    int x,y;
    if(p) {
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int Tree::iheight(Node *p) {
    stack<long int> stk;
    p=root;
    long int x,H=1;
    while(p!= nullptr || !stk.empty()){
        if (p){
            stk.emplace((long int)p);
            p=p->lchild;
        }
        else{
            if(stk.size()>H)
                H=stk.size();
            x=stk.top();
            stk.pop();
            if(x>0){
                p=((Node *)x)->rchild;
                stk.emplace(-x);
            }
            else p=nullptr;


        }
    }
    return H;
}

int Tree::parminusson(Node *p) {
    if(p){
        int x=p->data;
        int y=parminusson(p->lchild);
        int z=parminusson(p->rchild);
        return max(abs(x-y),abs(x-z));
    }
    return 0;
}

void Tree::spiralorder() {
    stack<Node *> s1,s2;
    s1.push(root);
    while(!s1.empty()|| !s2.empty()){
        while(!s1.empty()){
            Node *p=s1.top();
            s1.pop();
            cout<<p->data<<" ";
            if(p->rchild)
                s2.push(p->rchild);
            if(p->lchild)
                s2.push(p->lchild);
        }
        while(!s2.empty()){
            Node *p=s2.top();
            s2.pop();
            cout<<p->data<<" ";
            if(p->lchild)
                s1.push(p->lchild);
            if(p->rchild)
                s1.push(p->rchild);
        }
    }
    cout<<endl;
}

int main() {
    Tree t;
    t.createtree();
//    t.preorder();
//    cout<<endl;
//    t.ipreorder();
//    t.levelorder();
//    t.inorder();
//    t.iinorder();
//    t.postorder();
//    t.ipostorder();
//   cout<< t.countnodes(t.root)<<" is the count of nodes";
   cout<<t.height(t.root)<<" is the height of tree\n";
   cout<<t.parminusson(t.root)<<endl;
   t.spiralorder();
//   cout<<t.countleaf(t.root)<<" are the number of leaf nodes";
//   cout<<t.sum(t.root)<<" is the sum";
//   cout<<t.countdeg1(t.root)<<" are degree 1 nodes ";
//    cout<<t.countdeg2(t.root)<<" are degree 2 nodes ";
    cout<<t.iheight(t.root)<<" is the iterative height\n";
    return 0;
}
