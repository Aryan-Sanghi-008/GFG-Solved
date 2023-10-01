//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    const int mod = 1e9 + 7;
	int distinctSubsequences(string s)
	{
	    int n = s.length();
	    vector<int> alph(26, -1), dp(n + 1, -1);
	    dp[0] = 1;
	    for(int i = 0; i < n; i++)
	    {
	        if(alph[s[i] - 'a'] == -1)
	        {
	            dp[i + 1] = (dp[i] << 1);
	        }
	        else
	        {
	            dp[i + 1] = ((dp[i] << 1) % mod) - dp[alph[s[i] - 'a'] - 1] + mod;
	        }
	        alph[s[i] - 'a'] = i + 1;
	        dp[i + 1] %= mod;
	    }
	    return dp[n] % mod;
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends