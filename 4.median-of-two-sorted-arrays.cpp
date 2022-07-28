/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (34.30%)
 * Likes:    17900
 * Dislikes: 2122
 * Total Accepted:    1.5M
 * Total Submissions: 4.3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
int GetRealValue(int* a, int *b)
{
    if(a == nullptr)
        return *b;
    if (b == nullptr)
        return *a;
    return (*a) > (*b) ?(*b) :(*a);
    
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ele_sum = nums1.size()+ nums2.size();
        int mid_index = ele_sum/2;
        int mid_index2 = (ele_sum%2)?-1:(mid_index-1);
        
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        int index = 0;
        int result1 = 0;
        int result2 = 0;
        bool find = false;
        bool find1 = false;
        while (1)
        {
            int *a = nullptr;
            int *b = nullptr;
            if(it1 != nums1.end()) 
                a = &(*it1);
            if(it2 != nums2.end()) 
                b = &(*it2);
            int temp = GetRealValue(a, b);
            
            if(index == mid_index2) {
                find1 = true;
                result1 = temp;
            }   
            if(index == mid_index) {
                find = true;
                result2 = temp;
            }

            if(mid_index2 != -1){
                if(find && find1)
                    return (double(result1+result2))/2;
            } else
            {
                if (find)
                {
                    return result2;
                }    
            }
            index++;

            if(a != nullptr && b != nullptr)
            {
                if(*a > *b) {
                    it2++;
                }   
                else
                    it1++;
                continue;
            }
                
            if(a == nullptr)
                it2++;
            if (b == nullptr)
            {
                it1++;
            }
        }    
    }
};
// @lc code=end

