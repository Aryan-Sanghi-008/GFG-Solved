//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    const long long mod = 1e9 + 7;
    long long solve(int curr, vector<long long> &dp, int n)
    {
        if(curr >= n)
        {
            return curr == n;
        }
        if(dp[curr] != -1)
        {
            return dp[curr];
        }
        long long ans = 0;
        for(int i = 1; i <= 3; i++)
        {
            ans += solve(curr + i, dp, n);
        }
        return dp[curr] = ans % mod;
    }
    long long countWays(int n)
    {
        vector<long long> dp(n + 1, -1);
        return solve(0, dp, n);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends