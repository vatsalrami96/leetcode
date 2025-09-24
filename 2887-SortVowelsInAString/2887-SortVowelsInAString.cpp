// Last updated: 9/24/2025, 2:16:02 AM
class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>> pq;
        unordered_set<char> uset{'A','E','I','O','U','a','e','i','o','u'};
        for(auto c:s){
            if(uset.find(c)!=uset.end()) pq.push(c);
        }

        string output="";
        for(auto c:s){
            if(uset.find(c)!=uset.end()){
                auto i=pq.top();
                pq.pop();
                output+=i;
            }else output+=c;
        }
        return output;
    }
};