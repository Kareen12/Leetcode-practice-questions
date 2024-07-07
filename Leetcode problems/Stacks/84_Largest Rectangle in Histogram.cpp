class Solution
{
public:
    vector<int> nextSmaller(vector<int> &heights, int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (st.top() != -1 && heights[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &heights, int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while (st.top() != -1 && heights[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    } // 215623

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next = nextSmaller(heights, n);

        vector<int> prev = prevSmaller(heights, n);

        // for(int i=0; i<n; i++){
        //     if(next[i] == -1){
        //         next[i] = n;
        //     }
        // }

        int maxArea = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }

            int w = next[i] - prev[i] - 1;

            int area = l * w;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};