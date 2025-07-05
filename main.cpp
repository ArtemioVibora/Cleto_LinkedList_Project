#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

int main() {
    //In every linked list must have a start
    Node n1, n2, n3, n4, *start, *ptr;
    int ctr;

    n1.value = 12;
    n2.value = 22;
    n3.value = 32;
    n4.value = 42;

    start = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;

    ptr = &n1;
    ctr = 1;

    while (ptr != NULL) {
        cout << "The value of NODE " << ctr << " is " << ptr->value << endl;
        ++ctr;
        ptr = ptr->next;
    }

}
