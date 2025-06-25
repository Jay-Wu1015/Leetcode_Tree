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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //建立虛頭節點
        ListNode *dummy = new ListNode(0);
        //建立curr節點，以方便進入loop時操作next，並將dummy指標指的位址複製給curr
        ListNode *curr= dummy;
        
        int carry =0;

        //判斷l1, l2 是否為nullptr, carry 是否有值進位，若非則進入loop
        while(l1 || l2 || carry){

            int sum= carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2 ->val;
                l2 = l2->next;
            }

            carry = sum /10;
            curr->next = new ListNode( sum%10);
            curr=curr->next;

        }

        return dummy->next;
    
    }
};
