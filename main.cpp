#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int value;
    Node *next;
};

int main() {
    Node *start, *ptr1, *ptr2;
    int i, numOfNodes;

    start = NULL;
    cout << "Enter number of nodes: ";
    cin >> numOfNodes;

    for (i = 1; i <= numOfNodes; i++) {
        ptr1 = (Node *)malloc(sizeof(Node));
        cout << "Enter the value for Node " << i << ": ";
        cin >> ptr1->value;
        ptr1->next = NULL;

        if (start == NULL) {
            start = ptr1;
            ptr2 = ptr1;
        }
        else {
            ptr2->next = ptr1;
            ptr2 = ptr2 -> next;
        }
    }

    ptr1 = start;
    if (ptr1 == NULL) {
        cout << "The list is empty" << endl;
    }
    else {
        i = 1;
        while (ptr1 != NULL) {
            cout << ptr1->value << endl;
            ++i;
            ptr1 = ptr1 -> next;
        }
    }

}
