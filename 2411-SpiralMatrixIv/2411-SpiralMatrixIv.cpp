// Last updated: 9/24/2025, 2:16:32 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> mat(m,vector<int>(n,-1));

        int rowStart=0;
        int colStart=0;
        int rowEnd=m-1;
        int colEnd=n-1;

        while(head!=nullptr){
            for(int col=colStart;col<=colEnd && head!=nullptr;col++){
                mat[rowStart][col]=head->val;
                head=head->next;
            }
            rowStart++;
            for(int row=rowStart;row<=rowEnd && head!=nullptr;row++){
                mat[row][colEnd]=head->val;
                head=head->next;
            }
            colEnd--;
            if( rowStart<=rowEnd){
                for(int col=colEnd;col>=colStart && head!=nullptr;col--){
                    mat[rowEnd][col]=head->val;
                    head=head->next;
                }
                rowEnd--;
            }
            
            if(colStart<=colEnd){
                for(int row=rowEnd;row>=rowStart&& head!=nullptr;row--){
                    mat[row][colStart]=head->val;
                    head=head->next;
                }
                colStart++;
            }
            
        }


        return mat;





        
    }
};