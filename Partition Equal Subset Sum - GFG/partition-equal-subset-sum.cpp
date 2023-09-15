//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int curr, int n, int arr[], vector<vector<int>> &dp, int sum)
    {
        if(i >= n)
        {
            return curr == sum;
        }
        if(dp[i][curr] != -1)
        {
            return dp[i][curr];
        }
        
        int take = 0, not_take = 0;
        not_take = solve(i + 1, curr, n, arr, dp, sum);
        if(curr + arr[i] <= sum)
        {
            take = solve(i + 1, curr + arr[i], n, arr, dp, sum);
        }
        return dp[i][curr] = (take + not_take);
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if(sum & 1)
        {
            return 0;
        }
        sum >>= 1;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(0, 0, n, arr, dp, sum);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends