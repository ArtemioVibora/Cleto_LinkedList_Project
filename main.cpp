#include <iostream>
#include <cstdlib>
#include <malloc.h>

using namespace std;

struct Node {
    int value;
    Node *next;
};

bool isListEmpty(Node *start) {
    if (start == NULL) {
        return true;
    }
    return false;
}

int countNodes(Node *p) {
    int ctr = 0;

    while (p != NULL) {
        ++ctr;
        p = p->next;
    }
    return ctr;
}

void locateNode(Node *p, int searchValue) {
    int ctr;
    if (isListEmpty(p)) {
        cout << "List is empty" << endl;
    }
    else {
        ctr = 1;
        while (p != NULL && p->value != searchValue) {
            p = p->next;
            ++ctr;
        }
        if (ctr != NULL) {
            cout << "Node requested is Node " << ctr << "." << endl;
        }
        else {
            cout << "Node requested does not exist " << endl;
        }
    }
}

void printItems(Node *p) {
    int ctr;

    if (isListEmpty(p)) {
        cout << "The list is empty" << endl;
    }
    else {
        ctr = 1;
        while (p != NULL) {
            cout << "The value of node " << ctr << " is " << p->value << endl;
            p = p->next;
            ++ctr;
        }
    }
}

void deleteNode(Node **p_start, int delete_value) {
    Node *discard, *before;

    discard = *p_start;

    if (isListEmpty(*p_start)) {
        cout << "List is empty" << endl;
    }
    else {
        if ((*p_start)->value == delete_value) {
            *p_start = (*p_start)->next;
            free(discard);
            cout << "The value of node " << delete_value << " is deleted" << endl;
        }
        else {
            while (discard != NULL && discard->value != delete_value) {
                before = discard;
                discard = discard->next;
            }
            if (discard != NULL) {
                cout << "The Node does not exist!" << endl;
            }
            else {
                before->next = discard->next;
                free(discard);
                cout << "The value of node " << delete_value << " is deleted" << endl;
            }
        }
    }
}

//At the rear
void insertNodeRear(Node **p, int data) {
    Node *ptr1, *ptr2;
    ptr1 = (Node *)malloc(sizeof(Node));
    ptr1->value = data;
    ptr1->next = NULL;
    if (*p == NULL) {
        *p = ptr1;
    }
    else {
        ptr2 = *p;
        while (ptr2->next != NULL) {
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr1;
    }
}
//Within linked list
void insertNodeWithin(Node **p_start, int data, int pos) {
    Node *ptr, *before, *here;
    int ctr;

    ptr = (Node *)malloc(sizeof(Node));
    ptr->value = data;
    ptr->next = NULL;

    if (pos == 1) {
        ptr->next = *p_start;
        *p_start = ptr;
    }
    else {
        before = *p_start;
        here = (*p_start)->next;
        ctr = 1;
        //Divider
        while (ctr < pos - 2) {
            before = before->next;
            here = here->next;
            ++ctr;
        }
        //Linking between
        before->next = ptr;
        ptr->next = here;
    }
    cout << "\nInsertion at position " << pos << endl;
    cout << "Item inserted!" << endl;
}

int main() {

    Node *start;
    //list should be in the main function

}
