// Last updated: 9/24/2025, 2:15:50 AM
class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int median =(n%2!=0)?nums[n/2]:(nums[n/2]+nums[(n-1)/2])/2; 
        long long ans=LLONG_MAX;
        long long sum=0;
        if(isPalindrome(to_string(median))){
            cout<<median<<endl;
            for(int i=0;i<nums.size();i++){
                sum+=(abs(nums[i]-median));
            }
            return sum;
        }
        string temp = to_string(median);
        int middle = calMiddle(temp);
        int left =  calLeft(temp);
        int right =calRight(temp);
        vector<int> medians {left,middle,right};
        if(isPalindrome(to_string(median-1)))medians.push_back(median-1);
        if(isPalindrome(to_string(median+1)))medians.push_back(median+1);
        for(int i=0;i<medians.size();i++){
            cout<<medians[i]<<endl;
            for(int j=0;j<nums.size();j++){
                sum+=(abs(nums[j]-medians[i]));
            }
            ans=min(ans,sum);
            sum=0;
        }
        return ans;

    }

    bool isPalindrome(string s){
        string rev=s;
        reverse(rev.begin(),rev.end());
        return rev==s;
    }

    int calMiddle(string s){
        int n=s.size();
        string middle = n%2==0?s.substr(0,(n/2)):s.substr(0,(n/2)+1);
        int copy = stoi(middle);
        middle = to_string(copy);
        string temp=middle;
        string rev="";
        for(int i=0;n%2==0?i<temp.size():i<temp.size()-1;i++){
            rev=temp[i]+rev;
        }
        return stoi(middle+rev);

    }
    int calLeft(string s){
        int n=s.size();
        string middle = n%2==0?s.substr(0,(n/2)):s.substr(0,(n/2)+1);
        int copy = stoi(middle);
        copy-=1;
        middle = to_string(copy);
        string temp=middle;
        string rev="";
        for(int i=0;n%2==0?i<temp.size():i<temp.size()-1;i++){
            rev=temp[i]+rev;
        }
        return stoi(middle+rev);
    }
    int calRight(string s){
        int n=s.size();
        string middle = n%2==0?s.substr(0,(n/2)):s.substr(0,(n/2)+1);
        int copy = stoi(middle);
        copy+=1;
        middle = to_string(copy);
        string temp=middle;
        string rev="";
        for(int i=0;n%2==0?i<temp.size():i<temp.size()-1;i++){
            rev=temp[i]+rev;
        }
        return stoi(middle+rev);
    }
    
};