// Last updated: 9/24/2025, 2:16:11 AM


class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> sorted ;
        int n =nums1.size();
        for(int i=0;i<n;i++){
            sorted.push_back({nums2[i],nums1[i]});
        }
        sort(sorted.rbegin(),sorted.rend());

        
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int i=0 ;i<k-1;i++){
            pq.push(sorted[i].second);
            sum+=sorted[i].second;
        }
        cout<<sum;

        long long ans=0;
        for(int i=k-1;i<n;i++){
            int currentMin = sorted[i].first;
            int currentValue=sorted[i].second;
            ans=max(ans,(long long)currentMin*(sum+currentValue));
            if(!pq.empty() && currentValue > pq.top()){
                sum=sum-pq.top();
                pq.pop();
                pq.push(currentValue);
                sum=sum+currentValue;
            }
            //cout<<pq.size()<<endl;

        }
        return ans;
    }
};