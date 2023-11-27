
class Node{
    public:
    int data;
    int row;
    int col;
    
    Node(int val, int r, int c){
        this->data = val;
        this->row = r;
        this->col = c;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        int k = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<Node*, vector<Node*>, compare> pq;

        for(int i=0; i<k; i++){
            int element = nums[i][0];
            Node* temp = new Node(element, i, 0);
            mini = min(mini, element);
            maxi = max(maxi, element);
            pq.push(temp);
        }

        int minRange = mini;
        int maxRange = maxi;
        while(!pq.empty()){
            Node* top = pq.top();
            pq.pop();

            int topEle = top->data;
            int topRow = top->row;
            int topCol = top->col;

            mini = topEle;

            if(maxi - mini < maxRange - minRange){
                minRange = mini;
                maxRange = maxi;
            }

            if(top->col+1 < nums[topRow].size()){
                maxi = max(maxi, nums[topRow][top->col+1]);
                pq.push(new Node(nums[topRow][top->col+1], topRow, topCol+1));
            }
            else{
                break;
            }
        }
        ans.push_back(minRange);
        ans.push_back(maxRange);
        return ans;
    }
};