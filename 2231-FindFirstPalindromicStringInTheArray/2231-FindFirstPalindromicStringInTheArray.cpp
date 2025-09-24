// Last updated: 9/24/2025, 2:16:50 AM
class Solution {
public:
    bool isPalindrome(string s){
        int start =0;
        int end = s.size()-1;
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(auto i: words){
            if(isPalindrome(i)) return i;
        }
        return "";
    }
};