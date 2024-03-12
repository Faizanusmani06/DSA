/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefix_sum = 0;
        unordered_map<int, ListNode*> mp;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        ListNode* current = head;
        while(current) {
            prefix_sum += current->val;
            if(mp.find(prefix_sum) != mp.end()) {
                ListNode* start = mp[prefix_sum]->next;
                int temp = prefix_sum + start->val;

                while(start != current) {
                    mp.erase(temp);
                    start = start->next;
                    temp += start->val;
                }

                mp[prefix_sum]->next = current->next;
            }else {
                mp[prefix_sum] = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};