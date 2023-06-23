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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
     ListNode* merge(ListNode* left, ListNode* right) {
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        
        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while(left && right){
            if(left->val <= right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else
            {
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        if(left){
            mptr->next=left;
        }
        if(right){
            mptr->next=right;
        }
        return ans->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* mid = findMid(head);
        
        ListNode* left = head;
        ListNode* right =mid->next;
        
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* mergeLL = merge(left, right);
        return mergeLL;
        
    }
};