// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
class RandomizedCollection {
public:
    map<int, vector<int>> m; // key, index
    vector<pair<int,int>> data; // data, index
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        m[val].push_back(data.size());
        data.push_back({val, m[val].size()-1});
        return m[val].size() == 1;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        pair<int,int> lastEl = data.back();
        m[lastEl.first][lastEl.second] = m[val].back(); // updating the last value index
        data[m[val].back()] = lastEl; // update data with lastEl
        m[val].pop_back();
        if (m[val].size() == 0) {
            m.erase(val);
        }
        data.pop_back();
        return true;
    }
    
    int getRandom() {
        int size = data.size();
        return data[rand() % size].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */