#include <iostream>
using namespace std;

struct ListNode {
    int val;  
    ListNode* next;

    ListNode(int v) : val(v), next(NULL) {}
};

// for a given linked list this function detects if any loops are present
bool hasCycle(ListNode *head) {
    if(head == NULL) return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

// this function not only checks 

int main(){
    return 0;
}