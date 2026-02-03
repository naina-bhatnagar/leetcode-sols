#include <iostream>
using namespace std;

// REVERSE K IN GROUPS
// given an integer k, starting from head, reverse all k elements.
// k <= n (n is the length of the linked list)
// return the head of the list obtained
// if the last elements are less than k, then return them as it is...

// tc: O(n) for total n elements...

struct ListNode{ // see leetcode impl on problem 430
    int val;
    ListNode *next;
}; 

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || head->next == NULL) return head;
    ListNode *ptr = head;
    // check if k elements exist
    for(int i=0;i<k;i++){
        if(ptr==NULL) return head;
        ptr = ptr->next;
    }
    
    ptr = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    for(int i=0;i<k;i++){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    if(next!=NULL){
        head->next = reverseKGroup(ptr,k);
    }
    return prev;
}