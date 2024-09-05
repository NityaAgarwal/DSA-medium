//https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

//tabulation solution - 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        
        // 1 2 5
        // 3 1 1 
        // 3 3 3
        
        // 1 2 5
        // 8 6 3
        // 9 11 11
        
        //max1 = 8,index1 = 0,max2 = 6,index2 = 1
        
        int col = arr[0].size();
        vector<vector<int>>dp(n, vector<int>(col, 0));
        
        //fill first row of dp as the first row of arr
        for (int i = 0; i<col; i++) {
            dp[0][i] = arr[0][i];
        }
        
        //for remaining rows of dp - 
        for (int i = 1; i<n; i++) {
            int max1 = 0;
            int index1 = -1;
            int max2 = 0;
            int index2 = -1;
            
            //first step is to identify the max two elements
            for (int j = 0; j<col; j++) {
                if (dp[i-1][j] > max1) {
                    max2 = max1;
                    index2 = index1;
                    max1 = dp[i-1][j];
                    index1 = j;
                }
                else if (dp[i-1][j] > max2) {
                    max2 = dp[i-1][j];
                    index2 = j;
                }
            }
            
            //now make additions
            for (int j = 0; j<col; j++) {
                if (j!=index1) {
                    dp[i][j] = max1 + arr[i][j];
                }
                else dp[i][j] = max2 + arr[i][j];
            }
        }
        
        //recognise the max one from last row
        int maxi = INT_MIN;
        for(int i = 0; i<col; i++){
            if (dp[n-1][i] > maxi) maxi = dp[n-1][i];
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
