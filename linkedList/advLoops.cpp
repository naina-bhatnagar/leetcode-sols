#include <iostream>
using namespace std;

struct ListNode {
    int val;  
    ListNode* next;

    ListNode(int v) : val(v), next(NULL) {}
};

// check if a cycle is present
// if yes, return the starting point of the node (the point which has two branches pointing at it)
// remove the loop
ListNode *detectCycle(ListNode *head) {
    bool isCycle = false;
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){       // if they meet at some point, there must be a loop (this point is not the starting)
            isCycle = true;
            break;
        }
    }

    if(!isCycle) return NULL;

    // prev node for 3rd purpose
    // it points at the last node of fast!
    ListNode *prev = NULL;

    slow = head;        
    // mathematically, if a loop is present: dist bet(head and starting) & (starting and intersec) is equal

    // edge case, when the st is the head
    if (slow == fast) {
        // We must find the node that points back to head to break the link
        while (fast->next != slow) {
            fast = fast->next;
        }
        prev = fast;
    }

    while(slow!=fast){
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }


    prev-> next = NULL; // this removes the link bet st and the tail !
    return slow;
}

int main(){
    return 0;
}