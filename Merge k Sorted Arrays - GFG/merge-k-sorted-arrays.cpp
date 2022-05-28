// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
 
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<int>v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
        for(int i=0;i<k;i++){
            pair<int,int>p;
            p.first=arr[i][0];
            p.second=i;
            heap.push(p);
        }
        vector<int>index(k,0);
        while(!heap.empty()){
            auto r=heap.top();
            heap.pop();
            v.push_back(r.first);
            int j=index[r.second]+1;
            index[r.second]+=1;
            if(j<k){
                pair<int,int>p;
                p.first=arr[r.second][j];
                p.second=r.second;
                heap.push(p);
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends