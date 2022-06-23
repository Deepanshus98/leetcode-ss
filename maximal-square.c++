/*
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
        dp[i][j]: length of the largest square side value with (i,j) as the bottom right cell
        if (matrix[i][j] == 1)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        */
 
        int NR = matrix.size();
        int NC = matrix[0].size();
 
        vector<vector<int>> dp(NR+1, vector<int>(NC+1));
 
        int res = 0;
        for (int i = 1; i <= NR; ++i) {
            for (int j = 1; j <= NC; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j]  = min(dp[i-1][j], min(dp[i-1][j-1],dp[i][j-1])) + 1;
                    res = max(res, dp[i][j]*dp[i][j]);
                }
            }
        }
 
        return res;
    }
};
