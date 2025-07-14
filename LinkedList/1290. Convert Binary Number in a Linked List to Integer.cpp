// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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

 // With vector
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> bits;
        while(head){
            bits.push_back(head->val);
            head = head->next;
        }

        int n = bits.size();
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            int bit = bits[i];
            int pos = n-i-1;
            ans += bit*(int)(1<<pos);
        }
        return ans;
    }
};

 // Without Vector
 class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head){
            ans = (ans<<1) + head->val;
            head = head->next;
        }
        return ans;
    }
};