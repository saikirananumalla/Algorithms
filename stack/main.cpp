#include <iostream>
#include<stack>;
#include <cstring>;
#include<ctype.h>
using namespace std;
template <class T>
class stak{
public:
    int *A;
    int top;
    int size;
    stak(int size);
    ~stak();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stakTop();

};
template <class T>
stak<T>::stak(int size) {
    this->size=size;
    top=-1;
    A=new int(size);
}
template <class T>
stak<T>::~stak() {
    delete [] A;
}
template <class T>
void stak<T>::push(int x) {
    if(isFull())
        cout<<"stak Overflow\n";
    else{
        A[++top]=x;
    }
}
template <class T>
int stak<T>::pop() {
    if(isEmpty()){
        cout<<"stak Underflow\n";
        return -1;
    }
    else{
        cout<<A[top]<<" is popped";
        int a = A[top];
        top--;
        return a;
    }
}
template <class T>
int stak<T>::peek(int index) {
    int x=-1;
    if(top-index+1<0 || top-index+1>=size)
        cout<<"Invalid Index";
    else
        x=A[top+1-index];
    return x;

}
template <class T>
int stak<T>::isFull() {
    if(top==size-1)
        return 1;
    return 0;
}
template <class T>
int stak<T>::isEmpty() {
    if(top==-1)
        return 1;
    return 0;
}
template <class T>
void stak<T>::display() {
    for (int i=top; i>=0; i--){
        cout << A[i] << " | " << flush;
    }
    cout << endl;
}
template <class T>
int stak<T>::stakTop() {
    if(isEmpty())
        return -1;
    return A[top];

}

//void showstack(stack <int> s)
//{
//    while (!s.empty())
//    {
//        cout << '\t' << s.top();
//        s.pop();
//    }
//    cout << '\n';
//
//}
class Node{
public:
        int data;
        Node* next;
    };
class stkll{
private:
        Node* top;
        Node* newnode(int key){
            Node *t=new Node;
            t->data=key;
            t->next= nullptr;
            return t;
        }

public:
    stkll(){
        top= nullptr;
    }
        void push(int key){
            if(top== nullptr){
                Node *t=newnode(key);
                top=t;
            }
            else {
                Node *t = newnode(key);
                t->next=top;
                top=t;
            }
        }
        int pop(){
            if(top== nullptr){
                cout<<"Stack underflow\n";
                return -1;
            }
            Node* p=top;
            if(top->next)top=top->next;
            int x=p->data;
            delete p;
            return x;
        }
        int stacktop(){
            if(top== nullptr)
                return -1;
            return top->data;
        }
        int peek(int index){
            if(index<0 || top== nullptr)
                return -1;
            Node *p=top;
            for(int i=0;i<index-1;i++)
                if(p)p=p->next;
            return p != nullptr ? p->data : -1;
        }
        void display(){
            Node*p=top;
            while(p){
                cout<<p->data<<" | ";
                p=p->next;
            }
            cout<<endl;
        }
};
bool bal(char *s){
    stak<char> stk((int)strlen(s));
    for(int i=0;i<(int)strlen(s);i++){
        if(s[i]=='(')
            stk.push((int)s[i]);
        else if(s[i]==')'){
            if(stk.isEmpty())
                return false;
            else{
                stk.pop();
            }
        }
    }

}
int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}
char * convert(char *infix){
    char *postfix= new char(strlen(infix)+1);
    stack<char> stk;
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isalnum(infix[i]))
            postfix[j++]=infix[i++];
        else {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top()))
                stk.push(infix[i++]);
            else if (outPrecedence(infix[i]) == inPrecedence(stk.top()))
                stk.pop();
            else{
                postfix[j++]=stk.top();
                stk.pop();
            }
        }

    }
    while (! stk.empty() && stk.top() != ')'){
        postfix[j++] = stk.top();
        stk.pop();
    }
    postfix[j] = '\0';
    return postfix;
    }
int main() {
//    int A[]={2,6,3,5,1};
//    stak<int> stk(20);
//    stack<int> s;
//    s.emplace(0);
//    s.emplace(1);
//    s.emplace(2);
//    s.emplace(10);
//    s.push(3);
//    cout<<"The stack is : ";
//    showstack(s);
//    cout<<s.top();
//    cout<<s.size();
//
//    stk.display();
//   for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
//        stk.push(A[i]);
//   stk.display();
//    stk.push(10);
//    stk.display();
//    stk.pop();
//    cout<<stk.stakTop()<<" is top\n";
//    cout<<stk.peek(3)<<" is at index 3 peek\n";
//    stk.display();
//    stkll l;
//    cout<<l.pop()<<" pop result\n";
//    l.push(10);
//    l.push(20);
//    l.push(30);
//    l.push(40);
//    l.push(50);
//    cout<<l.stacktop()<<" is stack top\n";
//    cout<<l.peek(3)<<" is at index 3\n";
//    l.display();
//    cout<<l.pop()<<" pop result\n";
//    l.display();
//    l.push(60);
//    l.display();
    char infix[] = "((a+b)*c)-d^e^f";
    cout << convert(infix) << endl;
    return 0;
}
