#ifndef AVL_H
#define AVL_H
#include <iostream>

using namespace std;

struct Node {
    int val, height;
    Node *l=NULL, *r=NULL;};

class AVL {
    private:
        Node* root=NULL;
        int getheight(Node *N);
        Node* newNode(int val);
        Node *rotateright(Node *y);
        Node *rotateleft(Node *x);
        int getBalance(Node *N);
        Node* insertp(int val, Node* node);
        void printp(Node *x);
        Node * minn(Node* x);
        Node* deletenode(Node* x, int val);
    public:
        void insert(int val);
        void print();
        void dlt(int val);
};

#endif
