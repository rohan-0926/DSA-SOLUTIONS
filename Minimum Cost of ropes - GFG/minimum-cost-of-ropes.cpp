// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long int,vector<long long int>,greater<long long int>>p;
        for(int i=0;i<n;i++){
            p.push(arr[i]);
        }
        vector<long long int>sum; 
        long long int cost=0;
        while(p.size()>=2){
            auto i=p.top();
            p.pop();
            auto j=p.top();
            p.pop();
            cost=cost+i+j;
            p.push(i+j);
        }
        
        return cost;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends