#include <iostream>
#include<stack>
#include <queue>
using namespace std;
class Node{
public:
    Node* left;
    int data;
    Node* right;
};
class BST{
public:
    Node *root;
    BST(){
        root= nullptr;
    }
    Node* newnode(int key){
        Node* t=new Node;
        t->data=key;
        t->left= nullptr;
        t->right= nullptr;
        return t;
    }
    void insert(int key);
    void preorder(Node *p);
    void preorder(){preorder(root);}
    void inorder(Node *p);
    void inorder(){inorder(root);}
    Node* Inpre(Node *p);
    Node* Insuc(Node *p);
    int Height(Node *p);
    Node* Delete(Node *p,int key);
    void BSTfrompre(int *pre);
    void createFromPreorder(int *pre, int n);
};

void BST::insert(int key) {
    Node *p=root,*q;
    if(p== nullptr){
        root=newnode(key);
        return;
    }
    while(p!= nullptr){
        q=p;
        if(key<=p->data)
            p=p->left;
        else
            p=p->right;
    }
    p=newnode(key);
    key>q->data?q->right=p:q->left=p;
}

void BST::preorder(Node *p) {
    if(p){
        cout<<p->data<<"|";
        preorder(p->left);
        preorder(p->right);
    }

}
void BST::inorder(Node *p) {
    if(p){
        inorder(p->left);
        cout<<p->data<<"|";
        inorder(p->right);
    }

}

Node* BST::Inpre(Node *p) {
    while(p && p->right!= nullptr)
        p=p->right;
    return p;
}
Node* BST::Insuc(Node *p) {
    while(p && p->left!= nullptr)
        p=p->left;
    return p;
}

Node* BST::Delete(Node *p, int key) {
    Node *q;
    if(p== nullptr)
        return nullptr;
    if(p->left== nullptr && p->right== nullptr){
        if(p==root)
            root=nullptr;
        delete p;
        return nullptr;
    }
    if(key<p->data)
        p->left=Delete(p->left,key);
    else if(key>p->data)
        p->right=Delete(p->right,key);
    else{
        if (Height(p->right)<Height(p->left)){
            q=Inpre(p->left);
            p->data=q->data;
            p->left=Delete(p->left,q->data);
        }
        else{
            q=Insuc(p->right);
            p->data=q->data;
            p->right=Delete(p->left,q->data);
        }
    }
    return p;

}

int BST::Height(Node *p) {
    int x,y;
    if(p){
        x=Height(p->right);
        y=Height(p->left);
        return x>y?x+1:y+1;
    }
    return 0;
}
void showstack(stack<Node*> stk){
    cout<<"The stack is: ";
    while(!stk.empty()){
        cout<<stk.top()->data<<"|";
        stk.pop();
    }
    cout<<endl;
}

void BST::BSTfrompre(int *pre) {
    int n=8;
    int i=0;
    stack<Node *> stk;
    root=newnode(pre[i++]);
    Node *p=root;
    while(i<n){
        if(pre[i]<p->data){
            p->left=newnode(pre[i++]);
            stk.emplace(p);
            showstack(stk);
            p=p->left;
            if(p)cout<<p->data<<" left"<<endl;
        }
        else if(pre[i]>p->data && stk.empty()){
            p->right=newnode(pre[i++]);
            p=p->right;
            if(p)cout<<p->data<<" right if stack empty"<<endl;
        }
        else if(pre[i]>p->data && pre[i]<stk.top()->data){
            cout<<stk.top()->data<<" stack top"<<endl;
            p->right=newnode(pre[i++]);
            p=p->right;
            if(p)cout<<p->data<<" right if"<<endl;
        }
        else if(pre[i]>p->data && pre[i]>stk.top()->data) {
            p = stk.top();
            if (p)cout << p->data << " right else" << endl;
            stk.pop();
        }
    }
}

int main() {
    BST bst;
//    bst.insert(20);
//    bst.insert(25);
//    bst.insert(15);
//    bst.insert(10);
//    bst.insert(16);
//    bst.insert(17);
//    bst.preorder();cout<<endl;
//    bst.inorder();cout<<endl;
//    bst.Delete(bst.root,20);
//    bst.preorder();
//    bst.inorder();
int A[]={30,20,10,15,25,40,50,45};
int n=sizeof(A)/sizeof(A[0]);
      bst.BSTfrompre(A);
      bst.inorder();
      cout<<bst.Height(bst.root);
}
