//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
    int maxElement = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > maxElement) 
            maxElement = arr[i];
    }

    vector<int> freq(maxElement + 1, 0); // Increase size by 1 to handle elements up to maxElement

    for (int i = 0; i < N; i++) {
        int x = arr[i];
        freq[x]++;
    }

    int ans = 0;
    int count = 0; // Move count initialization outside the loop
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] > 0) { // Check if the element exists
            count++;
        } else {
            ans = max(ans, count); // Update ans if count is greater
            count = 0; // Reset count for the next consecutive sequence
        }
    }
    ans = max(ans, count); // Check for the last consecutive sequence
    return ans;
}

};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends