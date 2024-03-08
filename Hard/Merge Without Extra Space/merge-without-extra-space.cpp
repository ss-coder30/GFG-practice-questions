//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
    { 
        // code here 
        vector<long long> temp; // Using vector for temporary storage
        
        int i = 0, j = 0;
        
        // Merge the arrays into temp vector
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                temp.push_back(arr1[i]);
                i++;
            } else {
                temp.push_back(arr2[j]);
                j++;
            }
        }
        
        // Copy remaining elements from arr1
        while (i < n) {
            temp.push_back(arr1[i]);
            i++;
        }
        
        // Copy remaining elements from arr2
        while (j < m) {
            temp.push_back(arr2[j]);
            j++;
        }
        
        // Copy elements from temp vector back to arr1 and arr2
        for (int k = 0; k < n; k++) {
            arr1[k] = temp[k];
        }
        for (int k = 0; k < m; k++) {
            arr2[k] = temp[n + k];
        }
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends