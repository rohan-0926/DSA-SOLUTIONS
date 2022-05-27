// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void heapify(int arr[],int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int max=i;
    if(left<n && arr[left]<arr[max]){
        max=left;
    }
    if(right<n && arr[right]<arr[max]){
        max=right;
    }
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n=r+1;
        int ma=-1;
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
        for(int i=r;i>=max(0,r-k+1);i--){
            swap(arr[0],arr[i]);
            ma=arr[i];
            heapify(arr,i,0);
        }
        return ma;
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends