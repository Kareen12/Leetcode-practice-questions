class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min = 0;
        int max = 0;
        int ans = 0;
        int index = 0;

        while(max < n){
            for(int i=index; i<ranges.size(); i++){
                if(i-ranges[i]<=min && i+ranges[i]>max){
                    max = i + ranges[i];
                    index  = i;
                }
            }
            if(min == max)  return -1;
            ans++;
            min = max;
        }
        return ans;
    }
};

// 0 1 2 3 4 5
// 3 4 1 1 0 0

// -3  3
// -3  5
//  1  3
//  2  4
//  4  4
//  5  5