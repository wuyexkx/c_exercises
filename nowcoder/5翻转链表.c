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


// 翻转链表， 分别用循环和递归实现
#include <stdio.h>


typedef struct Node {
    int val;
    struct Node* next;
}Node; 


// 1 -> 2 -> 3 -> 4 -> 5
// null <- 1 <- 2 <- 3 <- 4 <- 5
Node* reverse1(Node* head)
{
    Node* prev = NULL;
    Node* cur = head;
    Node* theNext = NULL;

    while (cur != NULL) {
        theNext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = theNext;
    }
    return prev;
}


// 1 -> 2 -> 3 -> 4 -> 5
// null <- 1 <- 2 <- 3 <- 4 <- 5
Node* _reverse(Node* cur, Node* prev)
{
    if (cur == NULL)                // 返回的是prev
        return prev;
    Node* theNext = cur->next;      
    cur->next = prev;
    prev = cur;
    cur = theNext;
    _reverse(theNext, prev);        // 下一个节点作为当前节点，当前节点作为上一个节点
}
Node* reverse(Node* head)
{  return _reverse(head, NULL); }


void print(Node* head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}


// 翻转链表，用循环和递归完成链表翻转
int main()
{
    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;     

    print(&node1);
    printf("\n");
    // Node* pp = reverse1(&node1); // 循环
    Node* pp = reverse(&node1);     // 递归
    print(pp);

    return 0;
}