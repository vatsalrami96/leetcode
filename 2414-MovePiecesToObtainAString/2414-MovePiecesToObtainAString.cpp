// Last updated: 9/24/2025, 2:16:31 AM
class Solution {
public:
    bool canChange(string start, string target) {
        int idx1=0;
        int idx2=0;
        int n = start.size();

        while (idx1 < n || idx2 < n) {
            // Skip blanks ('_') in both strings
            while (idx1 < n && start[idx1] == '_') idx1++;
            while (idx2 < n && target[idx2] == '_') idx2++;

            // If both pointers reached the end, return true
            if (idx1 == n && idx2 == n) return true;

            // If one pointer reached the end but the other did not, return false
            if (idx1 == n || idx2 == n) return false;

            // Check if the current characters match
            if (start[idx1] != target[idx2]) return false;

            // Check the movement constraints
            if (start[idx1] == 'L' && idx1 < idx2) return false; // 'L' cannot move right
            if (start[idx1] == 'R' && idx1 > idx2) return false; // 'R' cannot move left

            // Move both pointers
            idx1++;
            idx2++;
        }
        

        


        return true;
    }
};


//sequence matters
// if i have a left its position should be less than or equal to in the target
//if i have a right its position should be greater than or equal to in the target