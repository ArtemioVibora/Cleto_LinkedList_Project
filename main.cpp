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
        if (p != NULL) {
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
            if (discard == NULL) {
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
        while (ctr <= pos - 2) {
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
    start = NULL; //Should be declared for it will list it among the nodes

    int data, position, choice, count;

    while (choice != 9) {
        cout << "=======================" << endl;
        cout << "<1>Add \n<2>Delete \n<3>Locate \n<4>Print all \n<5>Add from within\n<9>Exit \n======================\n";
        count = countNodes(start);
        cout << "number of nodes: " << count << endl;
        cout << endl;
        cout << "What is your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "What would you like to insert: ";
                cin >> data;
                insertNodeRear(&start, data);
                break;
            case 2:
                cout << "What would you like to delete: ";
                cin >> data;
                deleteNode(&start, data);
                break;
            case 3:
                cout << "What would you like to locate: ";
                cin >> data;
                locateNode(start, data);
                break;
            case 4:
                printItems(start);
                break;
            case 5:
                cout << "What would you like to insert: ";
                cin >> data;
                cout << "What position: ";
                cin >> position;
                insertNodeWithin(&start, data, position);
                break;
            case 9:
                cout << "Good-bye!" << endl;
                break;
            default:
                break;
        }
    }//list should be in the main function
}
