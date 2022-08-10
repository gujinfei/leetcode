/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (39.65%)
 * Likes:    9515
 * Dislikes: 3266
 * Total Accepted:    1.8M
 * Total Submissions: 4.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        string prefix = "";
        int loop = 0;
        while(1) {
            char val = ' ';
            for (auto i = 0; i < num; i++)
            {
                int len = strs[i].length();
                if(loop < len){
                    if (val == ' ')
                    {
                        val = strs[i].at(loop);
                    }
                    else
                        if(val != strs[i].at(loop))
                            return prefix;  
                }
                else
                    return prefix;
            }
            prefix.push_back(val);
            loop++;    
        }
    }
};
// @lc code=end

