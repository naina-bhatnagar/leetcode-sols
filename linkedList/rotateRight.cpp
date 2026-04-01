#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;  
    ListNode* next;

    ListNode(int v) : val(v), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || head==nullptr || head->next==nullptr) return head;
    int n = 1;
    ListNode *ptr = head;
    ListNode *prev = head;
    while(ptr->next != nullptr){
        prev = ptr;
        ptr = ptr->next;
        n++;
    }
    k = k%n;

    if(k==0) return head;

    ptr->next = head;

    ptr = head;
    for(int i=0; i<n-k;i++){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = nullptr;
    
    return ptr;
}

int main(){
    return 0;
}