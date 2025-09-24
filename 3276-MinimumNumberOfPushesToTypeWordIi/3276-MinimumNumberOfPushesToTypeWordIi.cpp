// Last updated: 9/24/2025, 2:15:38 AM
class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int push=1;
        int count=0;

        priority_queue<pair<int,char>> pq;
        unordered_map<char,int>freq;

        for(auto i:word){
            freq[i]++;
        }

        for(auto i:freq) pq.push({i.second,i.first});

        while(!pq.empty()){
            auto i = pq.top();
            int freq = i.first;
            int c = i.second;
            pq.pop();

            ans= ans+ (freq*push);
            count++;
            if(count>=8){
                count=0;
                push++;
            }

        }

        return ans;

        
    }
};











