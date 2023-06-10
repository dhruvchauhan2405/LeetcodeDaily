class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[0];
        }
        
        int include = solveUsingRecursion(nums,n-2) + nums[n];
        int exclude = solveUsingRecursion(nums,n-1) + 0;

        return max(include,exclude);
    }

    int topDownApproach(vector<int>& nums, int n,vector<int>& dp){
        
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[0];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int include = topDownApproach(nums,n-2,dp) + nums[n];
        int exclude = topDownApproach(nums,n-1,dp) + 0;
        dp[n]= max(include,exclude);
        return max(include,exclude);
    }

    int bottomUpApproach(vector<int>& nums, int n){
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        
        for(int i=1;i<=n;i++){
            int temp =0;
            if(i-2>=0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1]+ 0;
            dp[i]= max(include,exclude);
            
        }
        return dp[n];
        
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        // int ans = solveUsingRecursion(nums,nums.size()-1);
        // return ans;

        
        // int ans = topDownApproach(nums,n,dp);
        int ans = bottomUpApproach(nums,n);
        return ans;
    }
};