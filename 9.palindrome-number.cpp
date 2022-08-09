/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (52.50%)
 * Likes:    5994
 * Dislikes: 2157
 * Total Accepted:    2.1M
 * Total Submissions: 4.1M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is palindrome integer.
 * 
 * An integer is a palindrome when it reads the same backward as forward.
 * 
 * 
 * For example, 121 is a palindrome while 123 is not.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without converting the integer to a string?
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s = std::to_string(x);
        int start = 0; 
        int end = s.length() - 1;
        if (end == 0)
        {
            return true;
        }
        while (1)
        {
            if (start >= end)
                return true;
            if (s[start++] != s[end--])
            {
                return false;
            }   
        }
    }
};
// @lc code=end

