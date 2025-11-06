class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil = -1;
        while(root){
        if(root -> data == x) return x;
        if(root -> data > x){
            ceil = root -> data; // valid hai left mei dhundo
            root = root -> left;
        }
        else root = root -> right;
        }
        return ceil;
    }
};
