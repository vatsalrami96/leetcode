// Last updated: 9/24/2025, 2:15:26 AM
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {

        priority_queue<int> pq;
        int n = queries.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            int d = abs(queries[i][0]) + abs(queries[i][1]);
            pq.push(d);
            if(pq.size()<k) result.push_back(-1);
            else if(pq.size()>k){
                pq.pop();
                result.push_back(pq.top());
            }
            else result.push_back(pq.top());
        }    
        return result;    
    }
};



// 5
// 3


// max heap


