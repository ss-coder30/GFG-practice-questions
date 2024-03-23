//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        stack<long long> st;
        vector<long long> ans(n, -1); // Initialize ans with -1
        
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack smaller than or equal to arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack is not empty, set the answer for arr[i]
            if (!st.empty()) {
                ans[i] = st.top();
            }
            
            // Push the current element onto the stack
            st.push(arr[i]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends