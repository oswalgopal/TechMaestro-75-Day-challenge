// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, map<int, string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map<string, map<int, string>>::iterator itr;
        itr = m.find(key);
        if (itr != m.end()) {
            itr->second.insert({timestamp, value});
        } else {
            map<int, string> t;
            t.insert({timestamp, value});
            m.insert({key, t});
        }
    }
    
    string get(string key, int timestamp) {
        map<string, map<int, string>>::iterator itr;
        itr = m.find(key);
        if (itr != m.end()) {
            map<int, string>::iterator itr2;
            itr2 = itr->second.upper_bound(timestamp);
            if (itr2-- == itr->second.begin()) {
                return "";
            }
            return itr2->second;
        } else {
            return "";   
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */