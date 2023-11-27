class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char> > pq;

        if(a > 0){
            pq.push({a, 'a'});
        }
        if(b > 0){
            pq.push({b, 'b'});
        }
        if(c > 0){
            pq.push({c, 'c'});
        }

        string ans = "";

        while(pq.size() > 1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            if(top1.first >= 2){
                ans += top1.second;
                ans += top1.second;
                top1.first-=2;
            }
            else{
                ans += top1.second;
                top1.first--;
            }
            if(top2.first >= 2 && top2.first >= top1.first){
                ans += top2.second;
                ans += top2.second;
                top2.first-=2;
            }
            else{
                ans += top2.second;
                top2.first--;
            }

            if(top1.first > 0){
                pq.push(top1);
            }
            if(top2.first > 0){
                pq.push(top2);
            }
        }
        if(pq.size() == 1){
            auto top = pq.top();
            pq.pop();
            if(top.first >= 2){
                ans += top.second;
                ans += top.second;
                top.first-=2;
            }
            else{
                ans += top.second;
                top.first--;
            }
            // if(top.second >= 3){
            //     return "";
            // }
            // else{
            //     while(top.second--){
            //         ans += top.first;
            //     }
            // }
        }
        return ans;
    }
};