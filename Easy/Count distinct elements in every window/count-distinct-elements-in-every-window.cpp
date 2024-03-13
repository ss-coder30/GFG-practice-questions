//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector<int> countDistinct(int A[], int n, int k) {
    vector<int> ans;
    map<int, int> mp;
    
    // Initial counting of elements in the first window
    for (int i = 0; i < k; i++) {
        mp[A[i]]++;
    }
    ans.push_back(mp.size());

    // Sliding window and updating counts
    for (int i = k; i < n; i++) {
        mp[A[i]]++; // Include new element in the window
        mp[A[i - k]]--; // Remove the element leaving the window
        if (mp[A[i - k]] == 0) {
            mp.erase(A[i - k]); // If count becomes zero, remove from map
        }
        ans.push_back(mp.size()); // Count number of distinct elements in the window
    }
    return ans;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends