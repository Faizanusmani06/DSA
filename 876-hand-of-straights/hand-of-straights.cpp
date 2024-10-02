class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        if(hand.size() % groupSize) return false;
        for (int i : hand)
            mp[i]++;
        if(groupSize == 1) return true;
        while (mp.size() != 0) {
            int n = groupSize;

            auto itr = mp.begin();
            int last = itr->first;
            cout << itr->first << " " << itr->second << endl;
            itr->second--;
            if (itr->second == 0)
                mp.erase(itr->first);
            itr++;
            if(itr == mp.end()) return false;
            while (itr != mp.end()) {
                
                if (n <= 1)
                    break;

                if (last + 1 != itr->first)
                    return false;
                last = itr->first;
                itr->second--;
                if (itr->second == 0)
                    mp.erase(itr->first);
                n--;
                itr++;
            }
        }

        return true;
    }
};