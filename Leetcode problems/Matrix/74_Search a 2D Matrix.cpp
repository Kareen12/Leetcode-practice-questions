class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        
        int m=matrix.size();
        int n=matrix[0].size();

        int start=0;
        int end=(m*n)-1;

        
        while(start<=end)
        {
            int mid=(start+(end-start)/2);
            
            if(matrix[mid/n][mid%n]==target){
                return true;
            }
            if(matrix[mid/n][mid%n]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};

// SAME SOLUTION JUST ROW COL NAME CHANGED
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        
        int row=matrix.size();
        int col=matrix[0].size();

        int start=0;
        int end=(row*col)-1;

        
        while(start<=end)
        {
            int mid=(start+(end-start)/2);
            
            if(matrix[mid/col][mid%col]==target){
                return true;
            }
            if(matrix[mid/col][mid%col]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};