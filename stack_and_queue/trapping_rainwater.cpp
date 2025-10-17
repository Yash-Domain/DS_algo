// better solution uisng pmsx,smax
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pmax(n);
        vector<int> smax(n);
        pmax[0] = height[0];
        smax[n-1] = height[n-1];
        int ans = 0;

        for(int i = 1 ; i < n ;i++ ){
            pmax[i] = max(pmax[i-1],height[i]);
        }
        for(int i = n-2; i >=0 ; i--){
            smax[i] = max(smax[i+1],height[i]);
        }

        for(int i =0 ; i< n ; i++){
            int watercount = min(pmax[i],smax[i]) - height[i];
            ans+= watercount; 
        }

        return ans;
    }
};

// optimal solution 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1 ;
        long long ans = 0;
        int lmax = 0;
        int rmax = 0;
        while(l<r){
             lmax = max(lmax,height[l]);
             rmax = max(rmax,height[r]);
            if(lmax < rmax){
                ans += lmax - height[l]; 
                l++;           
            }
            else{
                ans += rmax - height[r];
                r--;
            }
        }
        return int(ans);
    }
};