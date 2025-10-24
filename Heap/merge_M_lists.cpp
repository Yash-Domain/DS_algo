//Nlogk (log k for dividing ans into N for merging )
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
    ListNode* merge2lists(ListNode* l , ListNode* r){
        if(l == NULL ) return r;
        if(r == NULL) return l;

        if(l -> val <= r -> val){
            l -> next = merge2lists(l -> next,r);
            return l;
        }
        else{
            r -> next = merge2lists(l, r -> next);
            return r;
        }
    }

    ListNode* mergeSort(int s , int e , vector<ListNode*>& lists){
        if(s > e) return NULL;
        if(s == e ) return lists[s];

        int mid = s + (e-s)/2;

        ListNode* l = mergeSort(s , mid , lists);
        ListNode* r = mergeSort(mid +1 , e , lists);

        return merge2lists(l,r);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return mergeSort(0,n-1,lists);
    }
};