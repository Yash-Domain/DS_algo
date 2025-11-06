class Solution {
  public:
    Node* succ(Node* root , int key){
        Node* ceil  = NULL;
        while(root){
        if(root -> data > key){
            ceil = root;
            root = root -> left;
        }
        else root = root -> right;
        }
        return ceil;
    }
    Node* pred(Node* root , int key){
        Node* floor = NULL;
        while(root){
        if(root -> data < key){
            floor = root ;
            root = root -> right;
        }
        else root = root -> left;
        }
        return floor;
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* a = pred(root,key);
        Node* b = succ(root,key);
        return {a,b};
    }
};


