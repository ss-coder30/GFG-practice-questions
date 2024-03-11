//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        
        
        if(num == 1){
            return arr[0];
        }
        
        int sum = 0;
        for(int i = 0; i<num; i++){
            sum += arr[i];
        }
        
        int currMax = arr[0], maxSoFar = arr[0], currMin = arr[0], minSoFar = arr[0];
        for(int i = 1; i<num; i++){
            currMax = max(arr[i], currMax + arr[i]);
            maxSoFar = max(maxSoFar, currMax);
            
            currMin = min(arr[i], currMin + arr[i]);
            minSoFar = min(minSoFar, currMin);
        }
        
        if(minSoFar == sum) return maxSoFar;
        
        return max(maxSoFar, (sum - minSoFar));
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends