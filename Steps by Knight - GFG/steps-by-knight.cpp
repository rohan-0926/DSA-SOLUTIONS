// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kpos,vector<int>&tpos,int n)
	{
	    // Code here
	    queue<vector<int>> q;
	    int di[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
	    int count=0;
	    vector<int>v;
	    vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
	    vis[kpos[0]][kpos[1]]=true;
	    v.push_back(kpos[0]);
	    v.push_back(kpos[1]);
	    q.push(v);
	    while(!q.empty()){
	        int qop=q.size();
	        for(int hg=0;hg<qop;hg++){
	            vector<int>p;
	            p = q.front();
	            q.pop();
	            if(p[0]==tpos[0] && p[1]==tpos[1]){
	              return count;
	            }
	            else{
	              for(int i=0;i<8;i++){
	                vector<int>y;
	                y.push_back(p[0]+di[i][0]);
	                y.push_back(p[1]+di[i][1]);
	                if(y[1]>=1 && y[0]<=n && y[0]>=1 && y[1]<=n && !vis[y[0]][y[1]]){
	                    q.push(y);
	                    vis[y[0]][y[1]]=true;
	                }
	                y.clear();
	              }
                  

	        }
                p.clear();
	    }
	    count++;
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends