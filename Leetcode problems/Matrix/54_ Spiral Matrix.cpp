class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        int count=0;
        int total=rows*cols;

        int start=0;
        int end=cols-1;
        int top=0;
        int bottom=rows-1;

        vector<int> ans;

        while(count < total)
        {
            //first_row
            for(int row1=top;count<total && row1<=end;row1++)
            {
                ans.push_back(matrix[start][row1]);
                count++;
            }
            start++;
            //last_column
            for(int colLast=start;count<total && colLast<=bottom;colLast++)
            {
                ans.push_back(matrix[colLast][end]);
                count++;
            }
            end--;
            //last_row
            for(int rowLast=end;count<total && rowLast>=top;rowLast--)
            {
                ans.push_back(matrix[bottom][rowLast]);
                count++;
            }
            bottom--;
            //first_column
            for(int col1=bottom;count<total && col1>=start;col1--)
            {
                ans.push_back(matrix[col1][top]);
                count++;
            }
            top++;
        }
        return ans;
    }
};