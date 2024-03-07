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
    int getDecimalValue(ListNode* head) {
        int n = 0;
        ListNode* ptr = head; 
        while(ptr != nullptr) {
            ptr = ptr->next;
            n++;
        }
        ptr = head;

        int ans = 0;
        int i = 1;
        while(ptr != nullptr) {
            if(ptr->val == 1) {
                ans += pow(2, (n-i));
            }
            i++;
            ptr = ptr->next;
        }

        return ans;

    }
};