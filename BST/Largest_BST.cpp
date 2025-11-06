class info{
    public:
    int min , max , sz;
    
    info(int mmin , int mmax , int ssz){
        min = mmin;
        max = mmax;
        sz = ssz;
    }
};
class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    info helper(Node* root){
        if(root == NULL) return info(INT_MAX,INT_MIN,0);
        
        info l = helper(root -> left);
        info r = helper(root -> right);
        
        if(root -> data > l.max && root -> data < r.min){ //valid
            int currmin = min(root -> data , l.min);
            int currmax = max(root -> data , r.max);
            int currsz = 1 + l.sz + r.sz;
            return info(currmin , currmax , currsz);
        }
        return info(INT_MIN,INT_MAX,max(l.sz,r.sz)); // invalid
    }
    
    int largestBst(Node *root) {
        // Your code here
        return helper(root).sz;
        //return ans.sz;
    }
};