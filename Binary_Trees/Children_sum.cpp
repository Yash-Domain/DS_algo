class Solution {
  public:
    void isSumProperty(Node *root) {
        // code here
        if(!root) return 0 ;
        int child = 0 ;
        if(root -> left){
            child += root -> left -> data;
        }
        if(root -> right){
            child += root -> right -> data;
        }
        if(child >= root -> data) root -> data  = child;
        else{
            if(root -> left) root -> left -> data = root -> data;
            if(root -> right) root -> right -> data = root -> data;
        }
        isSumProperty(root -> left);
        isSumProperty(root -> right);
        
        int total = 0 ;
        if(root -> left) total += root -> left -> data;
        if(root -> right) total += root -> right -> data;
        if(root -> left || root -> right) root -> data = total ;
    } 
};

// to check 
class Solution {
  public:
    int isSumProperty(Node *root) {
        // code here
        if(!root) return 1 ; // both leaf and null nodes are valid 
        if(!(root -> left) && !(root -> right)){
            return 1;
        }
        int child = 0 ;
        if(root -> left){
            child += root -> left -> data;
        }
        if(root -> right){
            child += root -> right -> data;
        }
        
        if(child != root -> data) return 0;
        
        int left = isSumProperty(root -> left);
        if(left == 0) return 0;
        int right = isSumProperty(root -> right);
        if(right == 0 ) return 0;
        
        
        return 1;
    }
};