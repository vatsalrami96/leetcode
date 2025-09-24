// Last updated: 9/24/2025, 2:16:20 AM
const int ALPHABET_SIZE = 26;
 
class Trie
{
    class Node {
        public:
        char data;
        Node* children[ALPHABET_SIZE];
        bool isEndOfWord;
        int f;
        Node(char c){
            data = c;
            isEndOfWord = false;
            f=0;
            for(int i = 0; i < ALPHABET_SIZE; i++){
                children[i] = nullptr;
            }
        }
    };
 
    Node* root;
 
    public:
 
    Trie(){
        root = new Node('\0');
    }
 
    void insert(const string word){
        Node* temp = root;
        for(char c : word){
            int index = c - 'a';
            if(temp->children[index] == nullptr) {
                temp->children[index] = new Node(c);
            }
            temp = temp->children[index];
            temp->isEndOfWord = true;
            temp->f++;
        }
        
        
    }

    void findfreq(const string word, int &ans){
        Node* temp = root;
        for(char c : word){
            int index = c - 'a';
            temp = temp->children[index];
            ans+=temp->f;
        }
        
    }
	
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        Trie tries;
        for(auto i:words){
            tries.insert(i);
        }
        vector<int> ans;
        for(auto i:words){
            int c=0;
            tries.findfreq(i,c);
            ans.push_back(c);
        }

        return ans;
        
    }
};


