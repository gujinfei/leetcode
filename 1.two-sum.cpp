/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> key;
        vector<int>  result;
        for (auto i = 0; i < nums.size(); i++)
        {
            auto need_val = target - nums[i];
            if (key.find(nums[i]) != key.end())
            {
                result.push_back(key[nums[i]]);
                result.push_back(i); 
                return result;
            }
            key[need_val] = i;  
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
// @lc code=end

