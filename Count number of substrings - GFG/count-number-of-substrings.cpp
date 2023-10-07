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
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        long long sum = 0;
        int dis = 0;
        while(i < n)
        {
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] == 1)
            {
                dis++;
            }
            while(dis > k)
            {
                freq[s[j] - 'a']--;
                if(freq[s[j] - 'a'] == 0)
                {
                    dis--;
                }
                j++;
            }
            sum += (i - j + 1) * 1LL;
            i++;
        }
        return sum;
    }
    long long int substrCount (string s, int k) {
        int n = s.length();
        long long ans = solve(s, k, n) - solve(s, k - 1, n);
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