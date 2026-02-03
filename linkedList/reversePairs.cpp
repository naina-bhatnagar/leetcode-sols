#include <iostream>
using namespace std;

// REVERSE PAIRS
// starting from head, reverse all pairs.
// if the length is odd, keep the last element as it is
// this function does the work

struct ListNode{ // see leetcode impl on problem 430
    int val;
    ListNode *next;
}; 

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode *ptr = head;
    ListNode *nex = head->next;
    
    ptr->next = swapPairs(nex->next);
    nex->next = ptr;
    return nex;
}

int main(){
    return 0;
}