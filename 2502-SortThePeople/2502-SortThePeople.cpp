// Last updated: 9/24/2025, 2:16:19 AM
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>> pq;
        vector<string> result;
        int n=names.size();
        for(int i=0;i<n;i++){
            pq.push({heights[i],names[i]});
        }

        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            result.push_back(i.second);
        }
        return result;
    }
};