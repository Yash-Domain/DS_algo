class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0 , rsum = 0 , maxsum = 0;
        for(int i = 0 ; i < k ; i++) {
            lsum += cardPoints[i];
        }
        int rind = n-1;
        maxsum = lsum;
        for(int i = k-1 ; i >=0 ; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rind];
            rind--;
            maxsum = max(maxsum,lsum+rsum);
        }
    return maxsum;
    }
};