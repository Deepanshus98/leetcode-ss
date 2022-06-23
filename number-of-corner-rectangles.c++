/* Given a grid where each entry is only 0 or 1, find the number of corner rectangles.

A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.

Example 1:

Input: grid = 
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
Output: 1
Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
Example 2:

Input: grid = 
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
Example 3:

Input: grid = 
[[1, 1, 1, 1]]
Output: 0
Explanation: Rectangles must have four distinct corners.
Note:

The number of rows and columns of grid will each be in the range [1, 200].
Each grid[i][j] will be either 0 or 1.
The number of 1s in the grid will be at most 6000.


Solution 1:
One straight-forward solution is: we can iterate any two rows, say r1 and r2, and for every column, we check if grid[r1][c] == grid[r2][c]. IF yes, we increate the count by 1. Then the number of rentangles formed by these two rows are count * (count - 1) / 2.
*/
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int NR = grid.size();
        int NC = grid[0].size();
 
        int res = 0;
 
        for (int i = 1; i <= NR; ++i) {
            for (int j = i+1; j <= NR; ++j) {
                int cnt = 0;
                for (int k = 1; k <= NC; ++k) {
                    if (grid[i-1][k-1] && grid[j-1][k-1]) {
                        cnt += 1;
                    }
                }
                res += (cnt*(cnt-1))/2;
            }
        }
 
        return res;
    }
};
