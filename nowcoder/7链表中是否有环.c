
// 力扣 141. 环形链表 
// 方法一： 用hash存储遍历过的节点，如果存在则true
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* p = head;
        while (p) {
            if (set.count(p))
                return true;
            else 
                set.insert(p);
            p = p->next;
        }
        return false;
    }
};

// 方法二
// 快慢指针
// 类似环形跑道，一人跑快一人跑满，快的迟早下次遇到慢的
// 那么快的走两步，慢的走一步，如果遇到了就是环，如果节点为NULL就不是环。
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (1) {
            if (fast)
                fast = fast->next;
            else
                break;
            if (fast)
                fast = fast->next;
            else
                break;             

            slow = slow->next;
            
            if (slow == fast) 
                return true;
        }
        return false;
    }
};
