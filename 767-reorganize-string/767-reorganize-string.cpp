class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>m;
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>>p;
        for(auto i:m){
            pair<int,char>y;
            y.first=i.second;
            y.second=i.first;
            p.push(y);
        }
        string k="";
        while(p.size()>=2){
            pair<int,char>a=p.top();
            p.pop();
            pair<int,char>b=p.top();
            p.pop();
            k=k+a.second+b.second;
            
            if((a.first-1)!=0){
                 pair<int,char>y;
                 y.first=(a.first-1);
                 y.second=a.second;
                 p.push(y);
            }
            if((b.first-1)!=0){
                p.push({(b.first-1),b.second});
            }
        }
        if(p.size()>0){
            pair<int,char>a=p.top();
            if(a.first==1){
                k=k+a.second;
                return k;
            }
            return "";
        }
        return k;
        
    }
};