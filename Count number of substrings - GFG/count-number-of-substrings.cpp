//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long solve(string &s, int k, int n)
    {
        int i = 0, j = 0;
        vector<int> mp(26, 0);
        long long ans = 0;
        int cnt = 0;
        while(i < n)
        {
            mp[s[i] - 'a']++;
            if(mp[s[i] - 'a'] == 1)
            {
                cnt++;
            }
            while(cnt > k)
            {
                mp[s[j] - 'a']--;
                if(!mp[s[j] - 'a'])
                {
                    cnt--;
                }
                j++;
            }
            ans += (i - j + 1) * 1LL;
            i++;
        }
        return ans;
    }
    long long int substrCount (string s, int k) 
    {
        int n = s.length();
        long long int ans = solve(s, k, n) - solve(s, k - 1, n);
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends