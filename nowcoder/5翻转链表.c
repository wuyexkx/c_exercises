/*
只需要完成逆置链表函数
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
*/
// 不好理解, 一个指头一个指尾，之前一直用的方法
// 1 2 3 4 prev
// 2 3 4 prev 1  
// 3 4 prev 2 1  
// 4 prev 3 2 1
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* p = pHead;    // 头
        ListNode* q = NULL;     // NULL
        while (p != NULL) {     
        ListNode* prev = q;
            q = p;
            p = p->next;
            q->next = prev;
        }
        return q;
    }
};

// 很好理解
// 1 2 3 4
// NULL<-1->2->3->4
// NULL<-1<-2->3->4
// NULL<-1<-2<-3->4
// NULL<-1<-2<-3<-4 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* crt = head;
        ListNode* theNext;
        while (crt) {
            theNext = crt->next;
            crt->next = prev;
            prev = crt;
            crt = theNext;
        }
        return prev;
    }
};