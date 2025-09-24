// Last updated: 9/24/2025, 2:15:43 AM
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<long long> xSet;
        long long mod =1e9+7;
        long long ans =-1;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        for(int i=0;i<hFences.size()-1;i++){
            for(int j=i+1;j<hFences.size();j++){
                xSet.insert(hFences[j]-hFences[i]);
            }
        }
        
        //for(auto it=xSet.begin();it!=xSet.end();it++) cout <<*it<<endl;
        
        for(int i=0;i<vFences.size()-1;i++){
            for(int j=i+1;j<vFences.size();j++){
                if(xSet.find(vFences[j]-vFences[i])!=xSet.end())ans = max(ans,((long long)(vFences[j]-vFences[i])*(vFences[j]-vFences[i])));
            }
        }

        return ans%mod;        
        
    }
};

                