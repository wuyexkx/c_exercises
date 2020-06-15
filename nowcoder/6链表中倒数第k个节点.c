/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        int n = 1;
        while (p->next) {           // 记录总节点数
            p = p->next;
            n++;
        }

        p = head;
        for (int i=0; i<n-k; ++i)   // 找到倒数第k个
            p = p->next;            
        return p;
    }
};

// 快慢指针 fast先走k 还剩n-k, 本来就希望从头n-k步就是倒数第k个咯
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head; 
        while (k) {
            fast = fast->next;
            k--;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};