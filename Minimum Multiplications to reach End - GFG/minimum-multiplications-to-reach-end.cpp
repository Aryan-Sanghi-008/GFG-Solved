//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int mod = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        if(start == end)
        {
            return 0;
        }
        vector<int> minn(1e5 + 1, 1e9);
        queue<int> q;
        int ops = 0;
        q.push(start);
        while(!q.empty())
        {
            int si = q.size();
            for(int i = 0; i < si; i++)
            {
                int val = q.front();
                q.pop();
                if(val == end)
                {
                    return ops;
                }
                for(auto j : arr)
                {
                    int res = ((val % mod) * (j % mod)) % mod;
                    
                    if(ops + 1 < minn[res])
                    {
                        q.push(res);
                        minn[res] = ops + 1;
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