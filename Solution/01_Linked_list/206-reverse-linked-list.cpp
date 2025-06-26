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
 //1->2->3->4->5->nullptr

 //pre=nullptr
 //curr=1
 //next: 2->3->4->5->nullptr
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head;
        ListNode *pre=nullptr;
        while(curr){
            ListNode *temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
            
        }

        return pre;
    }
};
