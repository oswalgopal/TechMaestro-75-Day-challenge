// https://leetcode.com/problems/lru-cache/
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    map<int, Node*> m;
    int cap;
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        next->prev = node;
        node->next = next;
    }
    void removeNode(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;
        next->prev = prev;
        prev->next = next;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* t = m[key];
        m.erase(key);
        removeNode(t);
        addNode(t);
        m[key] = t;
        return t->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (cap == m.size()) {
                m.erase(tail->prev->key);
                removeNode(tail->prev);
            }    
        } else {
            Node* n = m[key];
            m.erase(key);
            removeNode(n);
        }
        Node* t = new Node(key, value);
        addNode(t);
        m[key] = t;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */