/*
952. Largest Component Size by Common Factor
Hard

1289

86

Add to List

Share
You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:


Input: nums = [4,6,15,35]
Output: 4
*/
class Solution {
public:
    int parent[100001];
    int find (int x)
    {
        if(parent[x]==-1)
            return x;
        else return parent[x]=find(parent[x]);
    }
    bool uni(int x,int y)
    {
        int xp=find(x);
        int yp=find(y);
        if(xp!=yp)
            parent[yp]=xp;
        else return false;
        return true;
    }
    int largestComponentSize(vector<int>& arr) 
    {
        unordered_map<int,int> memo;
        memset(parent,-1,sizeof(parent));
        int ret=0;
        for(int x:arr)
        {
           int flag=0;
            for(int i=2;i*i<=x;++i)
                if(x%i==0)
                {
                    uni(i,x);
                    uni(x,x/i);
                    flag=1;
                }
        }
        for(int x:arr)
            ret=max(ret,++memo[find(x)]);
        return ret;
    }
};
