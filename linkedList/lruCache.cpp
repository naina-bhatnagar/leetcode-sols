#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node{
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int k, int v){
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map <int,Node*> m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addhead(Node* curr){
        Node *nex = head->next;
        curr->next = nex;
        curr->prev = head;
        head->next = curr;
        nex->prev = curr;
    }

    void removeNode(Node *curr){
        Node* pre = curr->prev;
        Node* nex = curr->next;
        pre->next = nex;
        nex->prev = pre;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node *curr = m[key];
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            addhead(curr);
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* existing = m[key];
            existing->val = value;
            removeNode(existing);
            addhead(existing);
        }else {
            if (m.size() == capacity) {
                Node* lru = tail->prev;
                m.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            m[key] = newNode;
            addhead(newNode);
        }
    }
};

int main(){
    return 0;
}