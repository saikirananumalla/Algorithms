#include <iostream>
using namespace std;
class Node{
public:
    Node* prev;
    int data;
    Node* next;
};
class dll{
private:
    Node* head;
public:
    dll();
    dll(int A[], int n);
    ~dll();
    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
    void Reverse();
};

dll::dll() {

}

dll::dll(int *A, int n) {

}

dll::~dll() {

}

void dll::Display() {

}

int dll::Length() {
    return 0;
}

void dll::Insert(int index, int x) {

}

int dll::Delete(int index) {
    return 0;
}

void dll::Reverse() {

}

int main() {
    dll d;
    cout << "Place Holder for Double Link List!" << endl;
    return 0;
}
