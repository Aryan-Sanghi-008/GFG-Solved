//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int mx = 1e9;
    int palindromicPartition(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        auto check = [&](int l, int r) 
        {
            while (l < r) 
            {
                if (s[l] != s[r]) 
                {
                    return 0;
                }
                l++, r--;
            }
            return 1;
        };
        
        function<int(int, int)> solve = [&](int i, int prev) 
        {
            if (prev == n)
            {
                return 0;
            }
            if (i == n)
            {
                return mx;
            }

            if (dp[i][prev] != -1)
            {
                return dp[i][prev];
            }

            int pick = mx;
            if (check(prev, i)) 
            {
                pick = 1 + solve(i + 1, i + 1);
            }
            int not_pick = solve(i + 1, prev);
            dp[i][prev] = min(pick, not_pick);
            return dp[i][prev];
        };
        
        return solve(0, 0) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends