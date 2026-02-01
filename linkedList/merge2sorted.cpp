#include <iostream>
using namespace std;

// aim : to merge two sorted lls such that the final ll is also sorted

struct ListNode {
    int val;  
    ListNode* next;

    ListNode(int v) : val(v), next(NULL) {}
};

// my method  uses iteration:
ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
    if(!list1) return list2;
    if(!list2) return list1;

    ListNode *head = NULL;
    if(list1->val < list2->val){
        head = list1;
        list1 = list1->next;
    }
    else{
        head = list2;
        list2 = list2->next;
    }
    ListNode *curr = head;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            curr->next = list1;
            list1 = list1->next;
        }
        else{
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if(list1 != NULL) curr->next = list1;
    if(list2 != NULL) curr->next = list2;
    return head;
}

// we can also solve this recursively
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){
    if(head1 == NULL || head2 == NULL){
        return head1 == NULL ? head2 : head1;
    }

    if(head1->val < head2->val){
        head1->next = mergeTwoLists(head1->next,head2);
        return head1;
    }else{
        head2->next = mergeTwoLists(head1,head2->next);
        return head2;
    }
}


int main(){
    return 0;
}