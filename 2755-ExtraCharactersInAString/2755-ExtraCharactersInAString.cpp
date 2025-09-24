// Last updated: 9/24/2025, 2:16:05 AM
class Solution {
public:
    //int dp[51];
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> uset;
        for(auto i:dictionary){
            uset.insert(i);
        }
        int n = s.size();
        // memset(dp,-1,sizeof(dp));
        // return solve(0,s,n,uset);
        int dp[n+1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = 1e9;
        }
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=min(dp[i],1+dp[i+1]);
            for(int j=i;j<n;j++){
                string temp = s.substr(i,j-i+1);
                    if(uset.find(temp)!=uset.end()){
                        dp[i]=min(dp[i],dp[j+1]);
                    }

            }
        }
        return dp[0];
    }

    // int solve(int i,string s,int n,unordered_set<string> uset){
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int ans=1e9;
    //     ans=min(ans,1+solve(i+1,s,n,uset));
    //     for(int j=i;j<n;j++){
    //         string temp = s.substr(i,j-i+1);
    //         if(uset.find(temp)!=uset.end()){
    //             ans=min(ans,solve(j+1,s,n,uset));
    //         }
    //     }

    //     return dp[i]=ans;
    // }
};




// leetscode 

// obs:- 
// my worst case answer will always be the number of characters in the string
// i can break if i am at a single character, in this case i do 1+
// i can also break if the substring that i have is present in my dict, in this vase i do 0+

// BC:- if i reach the length of the string i return 0 if if i reach it through a single charcter


// leetscode



// l+ eetscode     leet scode























