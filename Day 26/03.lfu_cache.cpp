// https://leetcode.com/problems/lfu-cache/
class Node {
    public:
    int key;
    int val;
    int count;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
        this->count = 1;
    }
};
class List {
    public:
    Node* head;
    Node* tail;
    int size;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->size = 0;
    }
    void addNode(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        next->prev = node;
        node->next = next;
        this->size++;
    }
    void removeNode(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;
        prev->next = next;
        next->prev = prev;
        this->size--;
    }
};


class LFUCache {
public:
    map<int, List*> freq_list;
    map<int, Node*> m;
    int cap;
    int minFreq;
    int currSize;
    LFUCache(int capacity) {
        this->cap = capacity;
        this->currSize = 0;
    }
    void updateFreqList(Node* node) {
        // remove the node from the current state
        m.erase(node->key);
        freq_list[node->count]->removeNode(node);
        // if this is the last element in the minFfreq list
        if (node->count == minFreq && freq_list[node->count]->size == 0) {
            minFreq++;
        }
        
        node->count += 1; // update the count of the current node
        
        // update list of the node with freq+1;
        List* newList = new List();
        if (freq_list.find(node->count) != freq_list.end()) {
            newList = freq_list[node->count];
        }
        newList->addNode(node);
        freq_list[node->count] = newList;
        m[node->key] = node;
    }
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* node = m[key];
        int val = node->val;
        updateFreqList(node);
        return val;
    }
    
    void put(int key, int value) {
        if (this->cap == 0) {
            return;
        }
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->val = value;
            updateFreqList(node);
        } else {
            // remove the least freq element
            if (currSize == this->cap) {
                List* l = freq_list[minFreq];
                m.erase(l->tail->prev->key);
                l->removeNode(l->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* newList = new List();
            if (freq_list.find(minFreq) != freq_list.end()) {
                newList = freq_list[minFreq]; 
            }
            Node* node = new Node(key, value);
            newList->addNode(node);
            m[key] = node;
            freq_list[minFreq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */