// Last updated: 9/24/2025, 2:16:51 AM
class Solution {
public:
    void fillPrevMin(vector<int> &prevMin,vector<int>& nums ){
        stack<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) {
                st.push(i);
                prevMin[i]=-1;
            }
            else {
                prevMin[i]=st.top();
                st.push(i);
                
            }
            
        }

        for(auto i : prevMin) cout << i;
        cout <<endl;
    }
    void fillNextMin(vector<int> &nextMin,vector<int>& nums ){
        stack<int> st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(st.empty()) {
                st.push(i);
                nextMin[i]=n;
            }
            else {
                nextMin[i]=st.top();
                st.push(i);                
            }
            
        }
        for(auto i : nextMin) cout << i;
        cout <<endl;
    }
    void fillPrevMax(vector<int> &prevMax,vector<int>& nums ){
        stack<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(st.empty()) {
                st.push(i);
                prevMax[i]=-1;
            }
            else {
                prevMax[i]=st.top();
                st.push(i);
                
            }
            
        }
        for(auto i : prevMax) cout << i;
        cout <<endl;
    }
    void fillNextMax(vector<int> &nextMax,vector<int>& nums ){
        stack<int> st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(st.empty()) {
                st.push(i);
                nextMax[i]=n;
            }
            else {
                nextMax[i]=st.top();
                st.push(i);                
            }
            
        }
        for(auto i : nextMax) cout << i;
        cout <<endl;
    }






    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
       vector<int> prevMin(n);
       vector<int> nextMin(n);
       vector<int> prevMax(n);
       vector<int> nextMax(n);
       fillPrevMin(prevMin,nums);
       fillNextMin(nextMin,nums);
       fillPrevMax(prevMax,nums);
       fillNextMax(nextMax,nums); 
       long long ans=0;
       for(int i=0;i<n;i++){
           long long  maxRange = (nextMax[i]-i)*(i-prevMax[i]);
           long long minRange = (nextMin[i]-i)*(i-prevMin[i]);
           ans+= (maxRange-minRange)*nums[i];
       }

       //for first test case 
       //sum of all maxi - sum of all min
       //i.e( sum no of time each element is maxi) - (sum of all time each number is min)
       //each element(no of time it was maxi - num of time it was min)
    
       return ans;
    }
};