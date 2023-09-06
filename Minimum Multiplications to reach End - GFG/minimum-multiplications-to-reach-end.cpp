//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int mod = 1e5;
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        vector<int> v(100001, -1);
        int n = arr.size();
        int count = 0;
        if (start == end)
        {
            return 0;
        }
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty())
        {
            count++;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int temp = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    int ans = ((temp % mod) * (arr[j] % mod)) % mod;

                    if (ans == end)
                    {
                        return count;
                    }
                    
                    if (v[ans] == -1)
                    {
                        q.push(ans);
                        v[ans] = count;
                    }
                }
            }
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