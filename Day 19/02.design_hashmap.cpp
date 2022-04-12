// https://leetcode.com/problems/design-hashmap/
class MyHashMap {
public:
    vector<int> nums;
    MyHashMap() {
        nums.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        nums[key] = value;
    }
    
    int get(int key) {
        if (nums[key] != -1) {
            return nums[key];
        }
        return -1;
    }
    
    void remove(int key) {
        nums[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */