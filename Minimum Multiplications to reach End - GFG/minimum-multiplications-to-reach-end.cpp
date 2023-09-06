//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    const int mod = 1e5;
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        vector<int> minn(1e5, 1e9);
        queue<int> q;
        q.push(start);
        int ops = 0;
        while (!q.empty())
        {
            int si = q.size();
            for (int i = 0; i < si; i++)
            {
                int val= q.front();
                q.pop();
                if (val == end)
                {
                    return ops;
                }
                for (int j : arr)
                {
                    int newNum = ((val % mod) * (j % mod)) % mod;
                    if ((1 + ops) < minn[newNum])
                    {
                        q.push(newNum);
                        minn[newNum] = 1 + ops;
                    }
                }
            }
            ops++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends