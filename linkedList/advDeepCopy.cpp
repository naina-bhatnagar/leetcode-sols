#include <iostream>
#include <unordered_map>
using namespace std;

// aim : implement the deep copy function for this data structure (notice the random pointer)

class Node {
public:
    int val;  
    Node* next;
    Node* random;

    Node(int v) : val(v), next(NULL) {}
};

Node* copyRandomList(Node* head) {
    if(head==NULL) return NULL;

    unordered_map <Node*,Node*> m;

    Node* newHead = new Node(head->val);
    Node* curr = newHead;
    Node* prev = head->next;
    m[head]=newHead;

    while(prev != NULL){
        Node* temp = new Node(prev->val);
        m[prev]=temp;
        curr->next = temp;
        curr = curr->next;
        prev = prev->next;
    }
    
    while(head!=NULL){
        m[head]->random = m[head->random];
        head = head->next;
    }

    return newHead;
}


int main(){
    return 0;
}