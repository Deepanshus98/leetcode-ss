/* You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

 

Example 1:

Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
*/
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
