class MyHashSet {
    vector<int> hashSet;
    unordered_map<int, int> mpp;

public:
    MyHashSet() {
        hashSet = {};
        mpp = {};
    }

    void add(int key) {
        if (mpp.find(key) != mpp.end())
            return;

        hashSet.push_back(key);
        mpp[key] = hashSet.size() - 1;
    }

    void remove(int key) {
        if (mpp.find(key) == mpp.end())
            return;
        int index = mpp[key];

        hashSet[index] = hashSet[hashSet.size() - 1];
        hashSet.pop_back();

        mpp.erase(key);
    }

    bool contains(int key) {
        if (mpp.find(key) != mpp.end())
            return true;
        else
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