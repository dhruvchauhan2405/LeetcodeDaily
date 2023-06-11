class Solution {
public:
    int recursion(int n){
        if(n==0 || n==1){
            return 1;
        }

        int steps = recursion(n-1) + recursion(n-2);
        return steps;
        
    }

    int solveTopDown(int n, vector<int>& dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] = solveTopDown(n-1,dp) + solveTopDown(n-2,dp);
        return dp[n];
        
    }

    int solveTab(int n){
         vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
    }

    int spaceOpt(int n){
        //  vector<int> dp(n+1,-1);
        int prev2=1;
        int prev1=1;
        int curr=0;

        for(int i=2;i<=n;i++){
            curr = prev2 + prev1;
            prev2= prev1;
            prev1=curr;
        }
        return prev1;
        
    }
    
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        return spaceOpt(n);
    }
};