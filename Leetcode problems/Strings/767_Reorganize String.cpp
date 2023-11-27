class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        
        int max_freq = INT_MIN;
        char max_freq_char;
        for (int i=0;i<26;i++){
            if(hash[i]>max_freq){
                max_freq = hash[i];
                max_freq_char=i+'a';
            }
         }
        
        int index=0;
        while(max_freq>0 && index<s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index+=2;
        }
        
        if(max_freq != 0){
            return "";
        }
        
        hash[max_freq_char-'a']=0;
        
        for(int i=0;i<26;i++){
            while(hash[i]>0){
                index= index>=s.size() ? 1 : index;
                s[index] = i+'a';
                hash[i]--;
                index+=2;
              }
         }
        return s;
    }
};

// SOLUTION USING HEAP
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char> > pq;

        for(auto i: s){
            mp[i]++;
        }

        for(auto k: mp){
            pq.push({k.second, k.first});
        }

        string ans = "";
        while(pq.size() > 1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            ans += top1.second;
            ans += top2.second;

            top1.first--;
            top2.first--;

            if(top1.first > 0){
                pq.push(top1);
            }
            if(top2.first > 0){
                pq.push(top2);
            }
        }

        if(pq.size()==1){
            auto top = pq.top();
            pq.pop();
            if(top.first == 1){
                ans+=top.second;
            }
            else{
                return "";
            }
        }
        return ans;
    }
};