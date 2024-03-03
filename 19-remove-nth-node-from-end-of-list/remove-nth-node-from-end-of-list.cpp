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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;
        ListNode* temp = head;
        while(temp){
        length++;
        temp=temp->next;
    }
    
    
    if(length==1 && n==1){  //EDGE CASE1
        return NULL;
    }
    

    length = length-n;
    if(length==0){
        return head->next; //EDGE CASE2
    }
    int count =0;
    ListNode* temp1 = head;



    while(temp1){
        count++;
        if(count==length){
            ListNode* sub=temp1->next;
            temp1->next=sub->next ;
            return head;
        }
        temp1=temp1->next;
    }
    return head;
}
};