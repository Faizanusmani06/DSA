class MyHashMap {
    vector<pair<int, int>> mp;

public:
    MyHashMap() { mp = {}; }

    void put(int key, int value) { 
        int i;
        for(i = 0; i < mp.size(); i++) {
            if(mp[i].first == key) {
                mp[i].second = value;
                break;
            }
        }
        if(i >= mp.size()) mp.push_back({key, value});
    }

    int get(int key) {
        for (int i = 0; i < mp.size(); i++) {
            if(mp[i].first == key) return mp[i].second;
        }
        return -1;
    }

    void remove(int key) {
        int i;
        for(i = 0; i < mp.size(); i++) {
            if(mp[i].first == key) {
                mp[i] = mp[mp.size() - 1];
                mp.pop_back();
                break; 
            }
        }

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */