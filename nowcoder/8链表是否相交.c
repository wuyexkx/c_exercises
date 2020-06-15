/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 面试题 02.07. 链表相交
// 先用unordered_set保存A，然后B在set中索引
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> setA;

        while (headA) {
            setA.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (setA.count(headB))
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

// 双指针，都走三段，到末尾了就是交点，同时到达
// pa走完自己的从headB开始走，pb走完自己的从headA开始走,
// 速度一致，路程一致，若相交则一定同时到达终点，返回终点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;

        while (pa != pb) {
            if (pa) pa = pa->next;
            else pa = headB;
            if (pb) pb = pb->next;
            else pb = headA;  
        }
        return pa;
    }
};