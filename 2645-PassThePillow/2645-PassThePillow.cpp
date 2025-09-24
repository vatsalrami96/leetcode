// Last updated: 9/24/2025, 2:16:10 AM
class Solution {
public:
    int passThePillow(int n, int time) {
        queue<int> diff;
        for(int i=1-n ;i<n-1;i++){
            diff.push(n-abs(i));
        }
        while(time>0){
            int key = diff.front();
            diff.pop();
            diff.push(key);
            time--;
        }
        return diff.front();
    }
};


//1 2 3 4 3 2 1 2 3 4 3 2 1 2 3 4



// n = 3

// 2 1 0 1 2 1 0 1
// 1 2 3 2 1 2 3 2
// 0 1 2 3 


// 3 2 1 0 1 2 3
// 1 2 3 4 3 2 1


