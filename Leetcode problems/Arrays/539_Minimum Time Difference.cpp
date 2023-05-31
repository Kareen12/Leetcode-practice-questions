class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        //STEP 1: Converting the time into minutes then storing the time in vector minutes
        int i = 0;
        while(i < timePoints.size()){
            string curr = timePoints[i];
            //For this we need to convert the string to integer
            int hr = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));
            
            int totalMins = hr*60 + min;
            minutes.push_back(totalMins);
            i++;
        }
        
        //STEP 2: Sorting the array and finding the minimum difference 
        sort(minutes.begin(),minutes.end());
        
        int mini = INT_MAX;
        for(int i=0;i<minutes.size()-1;i++){
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini,diff);
        }
        
        //STEP 3: Handling the edge cases, the case of 00:00
        int diff1 = minutes[0]+1440 - minutes[minutes.size()-1];
        int diff2 = minutes[minutes.size()-1] - minutes[0];
        int diffCheck = min(diff1,diff2);
        mini = min(mini,diffCheck);
        
        return mini;
    }
};