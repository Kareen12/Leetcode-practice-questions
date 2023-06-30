class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        
        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
            
        }
        return ans;
    }
    
     vector<int> prevSmaller(vector<int>& heights, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<n; i++){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
            
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int>next = nextSmaller(heights, n);
        
        vector<int>prev = prevSmaller(heights, n);
        
        
        int maxArea = INT_MIN;
        
        for(int i=0; i<n; i++){
            int l = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            int w = next[i] - prev[i] - 1;
            
            int area = l * w;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0; i<row; i++){
            vector<int> t;
            for(int j=0; j<col; j++){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        int area = largestRectangleArea(v[0]);
        for(int i=1; i<row; i++){
            for(int j=0; j<col; j++){
                if(v[i][j]){
                   v[i][j] += v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
           area =max(area, largestRectangleArea(v[i]));
        }
        return area;
     }
};