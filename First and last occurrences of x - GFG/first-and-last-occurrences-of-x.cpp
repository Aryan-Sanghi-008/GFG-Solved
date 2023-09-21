//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int binary_search_left(int arr[], int x, int lo, int hi)
    {
        int ans = -1;
        while(lo <= hi)
        {
            int mid = lo + ((hi - lo) >> 1);
            if(arr[mid] == x)
            {
                ans = mid;
                hi = mid - 1;
            }
            else if(arr[mid] > x)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
    int binary_search_right(int arr[], int x, int lo, int hi)
    {
        int ans = -1;
        while(lo <= hi)
        {
            int mid = lo + ((hi - lo) >> 1);
            if(arr[mid] == x)
            {
                ans = mid;
                lo = mid + 1;
            }
            else if(arr[mid] < x)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int val)
    {
        int lo = 0, hi = n - 1;
        int x = -1, y = -1;
        while(lo <= hi)
        {
            int mid = lo + ((hi - lo) >> 1);
            if(arr[mid] == val)
            {
                x = binary_search_left(arr, val, 0, mid);
                y = binary_search_right(arr, val, mid, n);
                return {x, y};
            }
            else if(arr[mid] < val)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return {-1, -1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends