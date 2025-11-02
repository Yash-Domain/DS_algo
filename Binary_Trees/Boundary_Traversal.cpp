/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> ans;
    bool isLeaf(Node * root){
        return (!(root -> left) && !(root -> right)) ;
    }
    
    void addLeft(Node* root){
        Node* curr = root -> left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr -> data);
            if(curr -> left) curr = curr -> left;
            else curr = curr ->right;
        }
    }
    
    void addright(Node* root){
        vector<int> temp;
        Node* curr = root -> right;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr -> data);
            if(curr -> right) curr = curr -> right;
            else curr = curr ->left;
        }
        for(int i = temp.size()-1 ; i >= 0 ; i--){
            ans.push_back(temp[i]);
        }
    }
    
    void addleaf(Node* root){
        Node* curr = root;
        if(isLeaf(curr)){
            ans.push_back(curr -> data);
            return;
        }
        if(curr -> left) addleaf(curr -> left);
        if(curr -> right) addleaf(curr -> right);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root -> data);
        addLeft(root);
        addleaf(root);
        addright(root);
        return ans;
    }
};