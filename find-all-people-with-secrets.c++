class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int p){
        if(par[p]==p) return p;
        return par[p]=find(par[p]);
    }
    void Union(int a,int b)
    {
        int p1=find(a),p2=find(b);
        int u=rank[p1],v=rank[p2];
        if(u==v) par[p2]=p1,rank[p1]++;
        else if(u>v) par[p2]=p1;
        else par[p1]=p2;
    }
    
    
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    
    void reset(int a) { par[a] = a; }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
        Union(0,firstPerson);
        
        vector<int> ans;
        sort(meetings.begin(),meetings.end(),[](vector<int>& a,vector<int>& b){
            if(a[2]<b[2]) return 1;
            return 0;
        });
        
        int m=meetings.size();
        int i=0;
        while(i<m){
           int currT=meetings[i][2]; 
            vector<int> persons;
            while(i<m && meetings[i][2]==currT){
                int a=meetings[i][0],b=meetings[i][1];
                Union(a,b);
                persons.push_back(a);
                persons.push_back(b);
                i++;
            }
            for(int& x:persons){
                if(!connected(0,x)) reset(x);
            }
        }
        for(int i=0;i<n;i++){
            if(connected(0,i)) ans.push_back(i);
        }
        return ans;
    }
};
