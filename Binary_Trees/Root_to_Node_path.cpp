/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> ans;
    vector<Node*> nodes;
    vector<int> temp; 
    
    bool isleaf(Node * root){
        return (!(root -> left) && !(root -> right));
    }
    
    void find_p(Node* root){
        if(root == NULL) return ;
        if(isleaf(root)) nodes.push_back(root);
        find_p(root -> left);
        find_p(root -> right);
    }
    
    bool path(Node* root , Node * p ){
        
        if(!root) return false ;
        temp.push_back(root -> data);
        if(p == root) return true;
        
        if (path(root -> left , p) || path(root -> right , p)) return true;
        temp.pop_back();
        return false ;
    }
    
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        if(!root) return ans;
        find_p(root);
        
        for(int i = 0 ;  i < nodes.size() ; i++){
            temp.clear();
            path(root , nodes[i]);
            ans.push_back(temp);
        }
        return ans;
        
    }
};