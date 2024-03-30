//{ Driver Code Starts



#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution{
public:
    vector<int> gcd(int a, int b){
        // code here
        if(a == 0){
            return {b, 0, 1};
        }
        
        vector<int> v = gcd(b % a, a);
        int x = v[2] - (b/a)*v[1];
        int y = v[1];
        return {v[0], x, y};
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        vector<int> v = ob.gcd(a,b);
        if(v.size()!=3)
            return 0;
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
    return 0; 
}
// } Driver Code Ends