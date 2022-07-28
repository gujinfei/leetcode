/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool add_one = false;
        ListNode* result = nullptr;
        ListNode** cur_node = nullptr;
        ListNode* next = nullptr;
        while (l1 || l2)
        {
            int a = 0, b = 0;
            if(l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
                
            if(l2){
                b = l2->val;
                l2 = l2->next;
            }
               
            int var = a + b;
            if(add_one)
                var = var + 1;
            if(var >= 10)
                add_one = true;
            else
                add_one = false;
            if (result == nullptr)
            {
                result = new ListNode(var%10,next);
                cur_node = &result;
            }
            else
                *cur_node = new ListNode(var%10,next);
            cur_node = &((*cur_node)->next);
        }
        if(add_one)
            *cur_node = new ListNode(1,next);
        return result;
    }
};
// @lc code=end

