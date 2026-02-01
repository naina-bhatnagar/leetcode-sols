#include <iostream>
using namespace std;

struct Node {
    int val;  
    Node* next;

    Node(int v) : val(v), next(NULL) {}
};

class List{
public:
    Node* head;

    List(){
        head = NULL; // we can add a tail to make tc of rear ops O(1)
    }

    void push_front(int val){
        Node* ptr = new Node(val); // dynamic : we can not use the static method: Node ptr(val) {instantiation}
        ptr->next = head;
        head = ptr;
    }

    void printll(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void printll(Node* head){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

Node* loopRev(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node *temp = head;
    Node *prev = NULL;
    while(temp!=NULL){
        Node *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

Node* recRev(Node *curr, Node *prev){
    if(curr == NULL) return prev;
    Node *next = curr->next;
    curr->next = prev;
    return recRev(next,curr);
}

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printll();
    ll.head = loopRev(ll.head);
    ll.printll();

    List l2;
    l2.push_front(15);
    l2.push_front(14);
    l2.push_front(13);
    l2.push_front(12);
    l2.push_front(11);
    l2.printll();
    Node *prev = NULL;
    l2.head = recRev(l2.head,prev);
    l2.printll();

    return 0;
}