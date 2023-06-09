class Solution {
public:
    int TopDownSolve(int n, vector<int> &dp) {
        
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = TopDownSolve(n-1,dp)+ TopDownSolve(n-2,dp);
        return dp[n];
    }

    int BottomUpSolve(int n) {
        vector<int> dp(n+1,-1);
        if(n==0 || n==1){
            return n;
        }
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<n+1;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    
    }
    int SpaceOptSolve(int n) {
        int prev2=0;
        if(n==0){
            return prev2;
        }
        int prev1=1;
        int curr;

        for(int i=2;i<n+1;i++){
            curr = prev2 + prev1;
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    
    }

    int fib(int n) {
        int ans= SpaceOptSolve(n);
        return ans;
    }
};