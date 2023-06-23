/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//APPROACH 1
class Solution {
public:
    Node* solve(Node* head,  unordered_map<Node*, Node*>& mp){
        if(head == 0) return 0;
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = solve(head->next, mp);
        if(head->random){
           newHead->random =  mp[head->random];
        }
        return newHead;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        
        return solve(head, mp);
    }
};

// Approach 2
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   
    Node* copyRandomList(Node* head) {
        if(head==0) return 0;
        // step1: clioning old list to new list
        // 7->13->11->10->1 => 7->7->13->13->11->11->10->10->1->1-x (consider old nodes are pointing to random pointers too)
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        
        // step2: assigning random pointers to the newNode 
        temp = head;
        while(temp){
            Node* cloneNode = temp->next;
            cloneNode->random = temp->random ?  temp->random->next : NULL;
            temp = temp->next->next;
        }
        
        // step3: detaching list from old list
        temp = head;
        Node* cloneHead = temp->next;
        while(temp){
            Node* cloneNode = temp->next;
            temp->next = temp->next->next;
            if(cloneNode->next){
                cloneNode->next= cloneNode->next->next;
            }
            temp = temp->next;
        }
        return cloneHead;
    }
};