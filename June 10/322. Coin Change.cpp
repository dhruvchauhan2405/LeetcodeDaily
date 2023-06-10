class Solution {
public:

    int solveUsingRecursion(vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveUsingRecursion(coins,amount-coins[i]);
            if(ans!= INT_MAX){
                mini= min(mini,1+ans);
            }
        }
        return mini;

    }

    int topDown(vector<int> &coins, int amount, vector<int>& dp){

        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = topDown(coins,amount-coins[i],dp);
            if(ans!= INT_MAX){
                mini= min(mini,1+ans);
            }
        }
        dp[amount]= mini;
        return mini;
    }

    int solveTab(vector<int>& coins, int amount){
        vector<int> dp(amount+1,INT_MAX);

        dp[0]=0;

        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]] != INT_MAX){
                    int ans = dp[i-coins[j]];
                    dp[i] = min(dp[i],ans+1);
                }
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins,amount);
        
        // vector<int> dp(amount+1,-1);
        int ans = solveTab(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};