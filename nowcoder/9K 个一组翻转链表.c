/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 翻转链表的前k部分，返回翻转后的  head  和  tail
void reverse(ListNode* head, int k, ListNode*& pnewHead, ListNode*& pnewTail)
{ 
    ListNode* cur = head;   // 当前指针
    ListNode* prev = NULL;  // 上一个指针
    while (k--) {
        ListNode* theNext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = theNext;
    }
    pnewTail = head;
    pnewHead = prev;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        // 取出各段的头先保存  顺便计算长度
        vector<ListNode*> v;
        int len = 0;
        while (p) {
            if (len%k == 0) v.push_back(p);
            p = p->next;
            len++;
        }

        // 翻转段小于2  或者  大于长度  都不用翻转
        if (k < 2 || k > len) return head;

        ListNode* newHead, * retHead;
        ListNode* newTail, * prevTail;
        int flag = 1;
        // 翻转所有k整数倍的段
        for (int i=0; i<len/k; ++i) {
            // 翻转本段
            reverse(v[i], k, newHead, newTail);
            // 除首次外，将上段的尾巴和本段链接
            if (!flag) prevTail->next = newHead; 
            // 首次应该保存整个链表的头
            else {
                flag = 0;
                retHead = newHead;
            }
            // 保存上一段的tail
            prevTail = newTail;
        }

        // 没有小尾巴
        if (len%k == 0) prevTail->next = NULL;
        // 还有小尾巴
        else prevTail->next =  v.back();    
    
        return retHead;
    }
};