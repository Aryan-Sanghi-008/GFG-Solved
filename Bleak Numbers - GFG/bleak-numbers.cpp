//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    int total = __lg(n); // giving us total bits to work on
        for (int bit = 1; bit <= total; bit++)
        {
            int num = n - bit;
            int set_bits = __builtin_popcount(num);
            if (set_bits == bit)
            {
                return 0;
            }
        }
        return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends