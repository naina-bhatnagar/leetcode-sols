#include <iostream>
using namespace std;

// FLATTEN A DOUBLY LINKED LIST
// these have an additional pointer 'child'. the aim is to flatten this multi-level linked list
// eg : 1 2 3 4 5 6 null
//          7 8 9 10 11 null
//                12 13 null

// ans : {1 2 3 7 8 9 10 12 13 11 4 5 6}

// tc: O(n) for total n elements...

struct Node{ // see leetcode impl on problem 430
    int val;
    Node *prev;
    Node *next;
    Node *child;

};

// we used recursion here
Node* flatten(Node* head) {
    if(head == NULL) return NULL;
    Node *ptr = head;
    Node *connect = NULL;
    while(ptr!=NULL){
        if(ptr->child != NULL){
            connect = ptr->next;
            Node *n = flatten(ptr->child);
            ptr->child = NULL;
            ptr->next = n;
            n->prev = ptr;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = connect;
            if(connect != NULL){
                connect->prev = ptr;
            }
        }
        ptr = ptr->next;
    }
    
    return head;
}

int main(){


    return 0;
}