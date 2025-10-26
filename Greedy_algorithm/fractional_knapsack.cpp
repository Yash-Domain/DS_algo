class Solution {
  public:
    static bool mycomp(pair<double,double> &a , pair<double,double> &b){
        return (a.first / a.second)  > (b.first / b.second);
    };
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,double>> temp ;
        for(int i = 0 ; i < val.size() ; i++){
            temp.push_back({val[i],wt[i]});
        }
        
        sort(temp.begin() , temp.end() , mycomp);
        
        double currwt = 0;
        double currval = 0;
        for(int i = 0 ; i < val.size() ; i++){
            if(currwt + temp[i].second <= capacity){
              currwt += temp[i].second;
              currval += temp[i].first;
            }
            else{
                double rem = capacity - currwt;
                currval += temp[i].first / temp[i].second  * rem;
                break;
            }
        }
        return currval;
    }
};
