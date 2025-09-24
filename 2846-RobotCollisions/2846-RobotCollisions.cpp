// Last updated: 9/24/2025, 2:16:03 AM
class Solution {
public:
    static bool customComparator(const pair<int, pair<int, pair<int, int>>>& a,const pair<int, pair<int, pair<int, int>>>& b) {
        return a.second.second.first < b.second.second.first;
    }


    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {        
        vector<pair<int,pair<int,pair<int,int>>>> v;
        for(int i = 0; i < positions.size(); i++) {
                pair<int, pair<int, pair<int, int>>> p = make_pair(positions[i], make_pair(healths[i], make_pair(i,directions[i])));
                v.push_back(p);
        }


        sort(v.begin(),v.end());

        stack<pair<int,pair<int,pair<int,int>>>> st;
        vector<pair<int,pair<int,pair<int,int>>>> safe;
        for(auto i:v){
            if(i.second.second.second == 'R'){
                st.push(i);
            }else{
                bool isDead=0;
                while(!st.empty() && !isDead){
                    if(st.top().second.first==i.second.first){
                        isDead=1;
                        st.pop();
                    }
                    else if(st.top().second.first > i.second.first){
                        isDead=1;
                        auto e = st.top();
                        st.pop();
                        e.second.first--;
                        st.push(e);
                    }
                    else{
                        i.second.first--;
                        st.pop();
                    }
                }
                if(!isDead) safe.push_back(i);
            }
        }

        while(!st.empty()){
            auto i =st.top();
            st.pop();
            safe.push_back(i);
        }
        sort(safe.begin(), safe.end(), customComparator);

        vector<int> result;
        for(auto i:safe) result.push_back(i.second.first);

        return result;




    }
};









