class MyHashSet {
    vector<int> mp;

public:
    MyHashSet() { mp = {}; }

    void add(int key) {
        if (!contains(key))
            mp.push_back(key);
    }

    void remove(int key) {
        int i;
        int n = mp.size();
        if(n == 0) return;
        for (i = 0; i < n; i++) {
            if (mp[i] == key)
                break;
        }
        if(i >= n) return;
        mp[i] = mp[n-1];
        mp.pop_back();
    }

    bool contains(int key) {
        for (int i : mp) {
            if (i == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */