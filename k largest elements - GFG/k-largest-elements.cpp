// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void heapify(int arr[],int n,int i){
    int left=2*i +1;
    int right=2*i+2;
    int max=i;
    if(left<n && arr[left]>arr[max]){
        max=left;
    }
    if(right<n && arr[right]>arr[max]){
        max=right;
    }
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
    }
	vector<int> kLargest(int arr[], int n, int k) {
	    for(int i=n/2-1;i>=0;i--){
	        heapify(arr,n,i);
	    }
	    vector<int>v;
	    
	    for(int i=n-1;i>=max(0,(n-k));i--){
	        swap(arr[0],arr[i]);
	        v.push_back(arr[i]);
	        heapify(arr,i,0);
	    }
	    return v;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends