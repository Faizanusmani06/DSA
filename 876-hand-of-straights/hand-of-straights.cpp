class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;
        if(groupSize == 1) return true;
        map<int, int> mp;

        for(int i : hand) mp[i]++;
        int curr;

        while(mp.size() > 0) {
            curr = mp.begin() -> first;
            for(int i = 0; i < groupSize; i++) {
                if(mp[curr+i] == 0) return false;
                --mp[curr+i];
                if(mp[curr+i] == 0) mp.erase(curr+i);
            }
        }
        return true;
    }
};