class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long findpower(long long a, long long b) {
        if (b == 0) return 1;
        if (b % 2 == 0) return findpower(a*a % MOD ,b/2) % MOD ;
        return (a* findpower(a*a % MOD ,b/2) ) % MOD ;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  
        long long odd = n / 2;        

        long long ans = (findpower(5, even) * findpower(4, odd)) % MOD;
        return (int)ans;
    }
};
