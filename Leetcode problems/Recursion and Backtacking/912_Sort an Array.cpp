class Solution {
public:
    void merge(vector<int>& nums, int s, int e, int mid){
        int len1 = mid - s + 1;
        int len2 = e - mid;
        
        int *left = new int[len1];
        int *right = new int[len2];
        
        int k = s;
        for(int x=0;x<len1;x++){
            left[x] = nums[k];
            k++;
        }
        
        k = mid + 1;
        for(int y=0;y<len2;y++){
            right[y] = nums[k];
            k++;
        }
        
        int leftInd = 0;
        int rightInd = 0;
        int mainInd = s;
        
        while(leftInd<len1 && rightInd<len2){
            if(left[leftInd]<right[rightInd]){
                nums[mainInd++] = left[leftInd++];
            }
            else{
                nums[mainInd++] = right[rightInd++];
            }
        }
        
        while(leftInd<len1){
            nums[mainInd++] = left[leftInd++];
        }
        
        while(rightInd<len2){
            nums[mainInd++] = right[rightInd++];
        }
        
        // delete []left;
        // delete []right;
    }
    
    void mergeSort(vector<int>& nums, int s, int e){
        //Base case
        if(s >= e){
            return;
        }
        
        int mid = s+(e-s)/2;
        
        //First half
        mergeSort(nums, s, mid);
        
        //Second half
        mergeSort(nums, mid+1, e);
        
        //merge them after sorting
        merge(nums, s, e, mid);
    }
               
    vector<int> sortArray(vector<int>& nums) {
         mergeSort(nums, 0, nums.size()-1);
         return nums;
    }
};

//IN PLACE MERGE SORT, improved space complexity
class Solution {
public:
    void merge(vector<int>& nums, int s, int e, int mid){
        int totalLen = e - s + 1;
        int gap = totalLen/2 + totalLen % 2;
        while(gap > 0){
            int i = s;
            int j = gap + s;
            while(j <= e){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
                i++;
                j++;
            }
            gap = gap<=1 ? 0 : (gap/2 + gap%2);
        }
    }
    
    void mergeSort(vector<int>& nums, int s, int e){
        //Base case
        if(s >= e){
            return;
        }
        
        int mid = s+(e-s)/2;
        
        //First half
        mergeSort(nums, s, mid);
        
        //Second half
        mergeSort(nums, mid+1, e);
        
        //merge them after sorting
        merge(nums, s, e, mid);
    }
               
    vector<int> sortArray(vector<int>& nums) {
         mergeSort(nums, 0, nums.size()-1);
         return nums;
    }
};

