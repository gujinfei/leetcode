/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.15%)
 * Likes:    26336
 * Dislikes: 1144
 * Total Accepted:    3.6M
 * Total Submissions: 10.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dst;
        int max = 0;
        int left_index = 0;
        int right_index = 0;
        int count = 0;
        for (auto c:s)
        {
            auto iterator = dst.find(c);
            if( iterator != dst.end())
            {
                if(dst[c] >=  left_index) {
                    max = max > count ? max:count;
                    left_index = dst[c] + 1;
                    count = (right_index - left_index);
                } 
            }
            dst[c] = right_index;  
            count++;
            right_index++;
        }
        return max > (right_index - left_index)?max:right_index - left_index; 
    }
};
// @lc code=end

