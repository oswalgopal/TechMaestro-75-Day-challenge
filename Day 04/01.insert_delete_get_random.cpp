// https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
public:
    map<int,int> m;
    vector<int> v;
    RandomizedSet() {
        m.clear();
        v.clear();
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        } else {
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        } else {
            int index = m[val];
            int lastVal = v[v.size()-1];
            
            v[index] = lastVal;
            m[lastVal] = index;
            
            v.pop_back();
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int r = rand()%v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */