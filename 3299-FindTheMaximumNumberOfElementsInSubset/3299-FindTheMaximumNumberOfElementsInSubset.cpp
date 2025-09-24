// Last updated: 9/24/2025, 2:15:36 AM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, long long> freq;
        set<int> st;
        for(auto i:nums){
            freq[i]++;
            st.insert(i);
        }
        long long ans=1;
        cout<<freq[1];
        for(auto i:st){
            if(i==1){
                if(freq[1]%2==0){
                    ans=max(ans,freq[1]-1);
                }
                else{
                    ans=max(ans,freq[1]);
                }
            }
            else{
                long long currAns=0;
                long long toFind = i;
                if(freq[toFind]>=2){
                    while(true){                        
                        if(freq[toFind]>=1 ){                            
                            ans=max(ans,currAns+1);
                            if(freq[toFind]==1) break;
                            currAns+=2;
                            toFind = toFind*toFind;
                        }else break;
                        
                    }
                    
                }
            }
            
        }
        return ans;        
    }
};