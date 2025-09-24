// Last updated: 9/24/2025, 2:16:13 AM
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0;
        int n =skill.size();
        int check = skill[0]+skill[n-1];
        for(int i =1;i<n/2;i++){
            if(skill[i] + skill[n-i-1] !=check) return -1;
        }

        for(int i =0;i<n/2;i++){
            ans+= (skill[i] * skill[n-i-1]);
        }

        return ans;


    }
};