// Last updated: 9/24/2025, 2:15:39 AM
struct compare{
   bool operator ()(pair<char,int> p1, pair<char,int> p2){
       return p1.second <= p2.second ;
   } 
};


class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq;
        for(auto i:word){
            freq[i]++;
        }
        cout<<"size"<<freq.size()<<endl;
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;

        for(auto p: freq){
            pq.push({p.first,p.second});
        }
        vector<int>v{1,9,16,23};
        int size =pq.size();
        int multi =0;
        int ans =0;
        for(int i=0;i<min(4,(size/8))+1;i++){
            multi= multi+1;
            int start=v[i];
            int end =start+7;
            while(!pq.empty() && start<=min(end,size)){
                auto temp   =pq.top();
                cout<<temp.first<<"-"<<temp.second<<"-"<<"multi"<<multi<<endl;
                pq.pop();
                ans+=pq.top().second*multi;
                start++;
            }
        }
        return ans;
        
    }
};