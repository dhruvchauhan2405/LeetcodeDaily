#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int n, int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }

    int ans = (solveUsingRecursion(n-1,k)+solveUsingRecursion(n-2,k))*(k-1);
    return ans;
}

int topDown(int n, int k, vector<int>& dp){

    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }

    if(dp[n]!=-1)
    return dp[n];

    dp[n] = (topDown(n-1,k,dp)+topDown(n-2,k,dp))*(k-1);
    return dp[n];
}

int solveTab(int n, int k){
    // vector<int> dp(n+1,0);
    int prev2=k;
    int prev1 = (k+k*(k-1));
    int curr=0;
    for(int i=3;i<=n;i++){
        curr = (prev1+prev2)*(k-1);
        prev2= prev1;
        prev1=curr;
    }

    return prev1;
}

int main() {
   int n=4;
   int k=3;

//    int ans = solveUsingRecursion(n,k);
//    vector<int> dp(n+1,-1); 
//    int ans = topDown(n,k,dp);
   int ans = solveTab(n,k);
   cout<< "ans="<<ans<<endl;
   return 0;
}