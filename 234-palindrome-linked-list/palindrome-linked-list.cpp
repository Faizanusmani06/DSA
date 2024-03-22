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
    bool isPalindrome(ListNode* head) {
        //find mid node

        ListNode* fast = head;
        ListNode* slow = head;
        if(fast==nullptr)return false;
        if(fast->next==nullptr)return true;
        if(fast->next->next==nullptr){
            if(fast->val == fast->next->val)return true;
            else return false;
        }
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next;
            if(fast!=nullptr&&fast->next!=nullptr){
                fast=fast->next;
                slow=slow->next;
            }
        }

        //revese other half

        ListNode* curr_next;
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        while(curr!=nullptr){
            curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }

        // Join 

        slow->next = prev;

        fast = head;
        slow = slow->next;
        while(slow!=nullptr){
            if(slow->val!=fast->val)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};