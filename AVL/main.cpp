#include "AVL.h"

using namespace std;

int main() {
    AVL avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    avl.print();
    avl.dlt(50);
    avl.dlt(40);
    avl.print();
    return 0;
}
