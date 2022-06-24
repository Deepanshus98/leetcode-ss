/*
839. Similar String Groups
Hard

841

170

Add to List

Share
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
*/
class Solution {
    vector<vector<int> > vec;
    unordered_map<int,unordered_set<int> > mp;
    vector<int> par;
public:
    bool comp(string &a,string &b){
        int n=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] && (++n)>2){
                return false;
            }
        }
        return true;
    }
    int find(int i){
        if(par[i]==-1) return i;
        return par[i]=find(par[i]);
    }
    void unio(int i,int j){
        int x=find(i);
        int y=find(j);
        if(x!=y){
            par[x]=y;
        }
    }
    int numSimilarGroups(vector<string>& A) {
        int n=A.size();
        par.resize(n+1,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(comp(A[i],A[j])){
                    unio(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(par[i]==-1){
                ans++;
            }
        }
        return ans;
    }
};
