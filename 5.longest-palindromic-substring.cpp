/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.84%)
 * Likes:    19876
 * Dislikes: 1151
 * Total Accepted:    2M
 * Total Submissions: 6.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * 
 * 
 */
#include <string>
using namespace std;


// @lc code=start
int GetStatus(string& s, int i, int j, int len)
{
    if (s[i] != s[j])
    {
        return 0;
    }
    if( ++i < --j)
        return GetStatus(s, i, j, len);
    else 
        return 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int status[n][n];
        for ( size_t i = 0; i < n; ++i )
        {
            status[i][i] = 0;
        }
        int start = -1, end = 0, max = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = n-1; j > 0; j--)
            {
                if (i < j)
                {
                    status[i][j] = GetStatus(s, i, j, n);
                    if(status[i][j] == 1) {
                        int len = j-i+1;
                        if(len > max) {
                            start = i;
                            max = len;
                        }
                    }
                } 
            }    
        }
        if (n == 1)
        {
            return s;
        } 
        if (n == 2) {
            if(s[0] == s[1])
                return s;
            else
                return s.substr(0,1);
        }
        if (-1 == start)
        {
            return s.substr(0,1);
        }
        return s.substr(start, max);
    }
};
// @lc code=end

