//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
    sort(arr, arr + n);
 
    // Maximum possible height difference
    int ans = arr[n - 1] - arr[0];
 
    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];
 
    for (int i = 1; i < n; i++) {
 
        // If on subtracting k we got 
        // negativeie. arr[i]-k<0 then continue as 
        //then arr[i]+k will be +ve but diff. ie. (+ve)-(-ve) is very large & we
        //need to minimise the diff. not maximise
        // 
        if (arr[i] - k < 0)
            continue;
 
        // Minimum element when we add k to whole array is compared to arr[0]+k as we need to take min of all
        //also diff. b/w arr[i]-k will b compared to arr[i-1]+k as consequtive nos. have low diff.
        //provided they both must be higher and lower of all given heights
        tempmin = min(arr[0] + k, arr[i] - k);
 
        // Maximum element when we subtract k from whole array is compared to arr[n-1]-k as we need 
        //to take max of all
        //here we took consequtively elements in sorted array as diff. b/w arr[i]-k will b 
        //compared to arr[i-1]+k as consequtive nos. have low diff. provided they both
        //must be higher and lower of all given heights
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k);
 
        ans = min(ans, tempmax - tempmin);
        //checking if neither inc or dec happended then value is min or other min values are min
    }
    return ans;
}
 
    
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
