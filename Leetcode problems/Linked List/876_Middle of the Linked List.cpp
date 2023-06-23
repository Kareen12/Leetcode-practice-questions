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

//APPROACH 1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
          ListNode* slow = head;
          ListNode* fast = head;
           while(slow != NULL && fast != NULL){
               fast = fast->next;
               if(fast != NULL){
                   fast = fast->next;
                   slow = slow->next;
               }
           }
           return slow;       
    }
};

//APPROACH 2    
class Solution {
public:
    int findLength(ListNode* &head){
        int i=0;
        ListNode* temp = head;
        while(temp != NULL){
            temp=temp->next;
            i++;
        }
        return i;
    }
    ListNode* middleNode(ListNode* head) {
        int len = findLength(head);
            len =len/2;
            for(int i=0;i<len;i++){
                head=head->next;
            }
        
        
        return head;
    }
};