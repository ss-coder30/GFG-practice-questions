//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> LPF(n+1, -1);
        vector<int> prime(n+1, 0);
        
        LPF[0] = 0;
        LPF[1] = 1;
        
        for(int i = 2; i<=n; i++){
            if(prime[i] == 0){
                LPF[i] = i;
                for(int j = 2*i; j<=n; j += i){
                    prime[j] = 1;
                    if(LPF[j] == -1){
                        LPF[j] = i;
                    }
                }
            }
        }
        
        return LPF;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends