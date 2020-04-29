#include "AVL.h"

int AVL::getheight(Node *x) {
    if (x == NULL)
        return 0;
    return x->height;}

Node* AVL::newNode(int val) {
    Node* x = new Node();
    x->val = val;
    x->l = NULL;
    x->r = NULL;
    x->height = 1;
    return(x);}

Node* AVL::rotateright(Node *x) {
    Node *y = x->l;
    Node *aux = y->r;
    y->r = x;
    x->l = aux;
    x->height = max(getheight(x->l), getheight(x->r)) + 1;
    y->height = max(getheight(y->l), getheight(y->r)) + 1;
    return y;}

Node* AVL::rotateleft(Node *x) {
    Node *y = x->r;
    Node *aux = y->l;
    y->l = x;
    x->r = aux;
    x->height = max(getheight(x->l), getheight(x->r)) + 1;
    y->height = max(getheight(y->l), getheight(y->r)) + 1;
    return y;}

int AVL::getBalance(Node *x) {
    if (x == NULL)
        return 0;
    return getheight(x->l) - getheight(x->r);}

void AVL::insert(int val) {
    if(root==NULL)
        root=newNode(val);
    else
        root=insertp(val, root);}

Node* AVL::insertp(int val, Node* node) {
    if (node == NULL)
        return(newNode(val));
    if (val < node->val)
        node->l = insertp(val, node->l);
    else
        if (val > node->val)
            node->r = insertp(val, node->r);
        else {
            cerr<<"Warning: Already in AVL\n";
            return node;}
    node->height = 1 + max(getheight(node->l), getheight(node->r));
    int balance = getBalance(node);
    if (balance > 1 && val < node->l->val)
        return rotateright(node);
    if (balance < -1 && val > node->r->val)
        return rotateleft(node);
    if (balance > 1 && val > node->l->val){
        node->l = rotateleft(node->l);
        return rotateright(node);}
    if (balance < -1 && val < node->r->val){
        node->r = rotateright(node->r);
        return rotateleft(node);}
    return node;}

void AVL::print() {
    printp(root);
    cout<<'\n';}

void AVL::printp(Node *x) {
    if(x != NULL){
        cout << x->val << " ";
        printp(x->l);
        printp(x->r);}}

Node* AVL::minn(Node* x){
    Node* y = x;
    while (y->l != NULL)
        y = y->l;
    return y;}

void AVL::dlt(int val) {
    root=deletenode(root, val);}

Node* AVL::deletenode(Node* x, int val) {
    if (x == NULL)
        return x;
    if ( val < x->val )
        x->l = deletenode(x->l, val);
    else if( val > x->val )
        x->r = deletenode(x->r, val);
    else {
        if(x->l == NULL || x->r == NULL) {
            Node* aux;
            if(x->l)
                aux=x->l;
            else
                aux=x->r;
            if (aux == NULL) {
                aux = x;
                x = NULL;}
            else
            *x = *aux;
            free(aux);}
        else {
            Node* aux = minn(x->r);
            x->val = aux->val;
            x->r = deletenode(x->r, aux->val);}}
    if (x == NULL)
    return x;
    x->height = 1 + max(getheight(x->l), getheight(x->r));
    int balance = getBalance(x);
    if (balance > 1 &&
        getBalance(x->l) >= 0)
        return rotateright(x);
    if (balance > 1 &&
        getBalance(x->l) < 0) {
        x->l = rotateleft(x->l);
        return rotateright(x);}
    if (balance < -1 && getBalance(x->r) <= 0)
        return rotateleft(x);
    if (balance < -1 && getBalance(x->r) > 0) {
        x->r = rotateright(x->r);
        return rotateleft(x);}
    return x;}
