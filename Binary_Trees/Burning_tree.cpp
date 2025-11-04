/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void parent_child(Node* root , unordered_map<Node*, Node*> &mp){
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr -> left){
                q.push(curr -> left);
                mp[curr -> left] = curr;
            }
            if(curr -> right){
                q.push(curr -> right);
                mp[curr -> right] = curr;
            }
        }
    }
    Node* find_node(Node* root , int target){
        if(!root) return NULL;
        if(root -> data == target) return root;
        
        Node* left = find_node(root -> left,target);
        if(left) return left;
        Node* right = find_node(root -> right,target);
        if(right) return right;
        
        return NULL;
    }
    
    int minTime(Node* root, int target) {
        // code here
        if(!root) return 0 ;
        unordered_map<Node*,Node*> mp;
        parent_child(root , mp);
        unordered_set<Node*>visited;
        
        Node* newtarget = find_node(root,target);
        
        visited.insert(newtarget);
        queue<Node*> q;
        q.push(newtarget);
        int ans = 0;
        while(!q.empty()){
        int n = q.size();
        for(int i = 0 ; i < n ; i++){
            Node* curr = q.front();
            q.pop();
            if(curr -> left && !visited.count(curr-> left)){
                q.push(curr -> left);
                visited.insert(curr -> left);
            }
            if(curr -> right && !visited.count(curr-> right)){
                q.push(curr -> right);
                visited.insert(curr -> right );
            }
            if(mp[curr] && !visited.count(mp[curr])){
                q.push(mp[curr]);
                visited.insert(mp[curr]);
            }
            
        }
         ans++;
        }
        return ans;
    }
};















