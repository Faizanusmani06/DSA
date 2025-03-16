class MyHashSet {
    vector<int> hashSet;

public:
    MyHashSet() { hashSet = {}; }

    void add(int key) {
        if (Search(key) != -1)
            return;
        hashSet.push_back(key);
    }

    void remove(int key) {
        int index = Search(key);
        if (index == -1)
            return;

        for (int i = index + 1; i < hashSet.size(); i++) {
            hashSet[i - 1] = hashSet[i];
        }
        hashSet.pop_back();
    }

    int Search(int key) {
        if (hashSet.empty())
            return -1;

        for (int i = 0; i < hashSet.size(); i++)
            if (hashSet[i] == key)
                return i;
        return -1;
    }

    bool contains(int key) {
        if (Search(key) == -1)
            return false;
        else
            return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */