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
    int getLength(ListNode* head){
        int len = 0;
        ListNode* demo = head;
        while(demo){
            len++;
            demo = demo->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        
        int len = getLength(head);
        
        
        int modifiedK = k % len;
        
        if(modifiedK == 0) return head;
        
        int fromLast = len - modifiedK - 1;
        
        ListNode* oldHead = head;
        while(fromLast--){
            oldHead = oldHead->next;
        }
        
        ListNode* newHead = oldHead->next;
        oldHead->next = NULL;
        
        ListNode* temp = newHead;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        
        return newHead;
    }
};