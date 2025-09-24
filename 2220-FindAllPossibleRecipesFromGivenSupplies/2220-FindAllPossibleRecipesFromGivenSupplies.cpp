// Last updated: 9/24/2025, 2:16:52 AM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       unordered_set<string> suppliesAvailable;
       int n = recipes.size();
       for(auto supply:supplies){
           suppliesAvailable.insert(supply);
       }
       unordered_set<string> result;

       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               string dish = recipes[j];
               if(result.find(dish)==result.end()){
                   bool flag = true;
                   for(auto required :ingredients[j] ){
                       if(suppliesAvailable.find(required)==suppliesAvailable.end()){
                           flag=false;
                           break;
                       }
                   }
                   if(flag){
                       result.insert(dish);
                       suppliesAvailable.insert(dish);
                   }
               }
           }
       }

       vector<string>recipiesMade(result.begin(),result.end());
       return recipiesMade;
    }
};