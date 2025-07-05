#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

int main() {
    //In every linked list must have a start
    Node n1, n2, n3, n4, *start;
    Node *ptr;


    n1.value = 111;
    n2.value = 222;
    n3.value = 333;
    n4.value = 444;

    start = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;

    ptr = start;
    cout << "====================================================================" << endl;
    cout << "The value of the node is " << ptr -> value << endl;
    cout << "The value of the next node is " << ptr -> next -> value << endl;
    cout << "The next node is " << ptr -> next -> next -> value << endl;
    cout << "====================================================================" << endl;

}