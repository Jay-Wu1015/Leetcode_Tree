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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (!head || left == right) return head;
        
            // 建立 dummy node 簡化邏輯
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prev = dummy;
        
            // 1. 找到 left 前一個節點
            cout<<"1. find a node"<<endl;
            for (int i = 1; i < left; ++i) {
                prev = prev->next;
            }
        
            // 2. 開始反轉
            ListNode* curr = prev->next;  // 先將curr指向第 left 個節點，目前prev的next
            ListNode* nextNode = nullptr;
            
            cout<<"2. start to reverse" <<endl;
            
            for (int i = 0; i < right - left; ++i) {
                nextNode = curr->next;
                curr->next = nextNode->next;
                nextNode->next = prev->next;
                prev->next = nextNode;
            }
        
            return dummy->next;
        }
    
};
