//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S)
    {
        if ((S == 0 && N > 1) || S > (N * 9))
        {
            return to_string(-1);
        }
        
        string ans = "";
        while(S > 9)
        {
            ans += '9';
            S -= 9, N--;
        }
        ans += to_string(S);
        N--;
        while(N--)
        {
            ans += '0';
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends