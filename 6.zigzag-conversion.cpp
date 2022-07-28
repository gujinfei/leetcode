/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (41.81%)
 * Likes:    4018
 * Dislikes: 9060
 * Total Accepted:    804.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "A", numRows = 1
 * Output: "A"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 * 
 * 
 */

//https://leetcode.com/problems/zigzag-conversion/discuss/3435/If-you-are-confused-with-zigzag-patterncome-and-see!

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        string result="";
        string *row = new string[numRows];
        for (auto i = 0; i < numRows; i++)
        {
            row[i] = "";
        }
        int i = 0;
        int flag = -1;
        for (auto c:s)
        {
            row[i] += c;
            if (i ==0 || i == (numRows-1))
            {
                flag = -flag;
            }
            i+=flag;
        }
        for (auto i = 0; i < numRows; i++)
        {
            result += row[i];
        }
        delete[] row;
        return result;  
    }
};
// @lc code=end

