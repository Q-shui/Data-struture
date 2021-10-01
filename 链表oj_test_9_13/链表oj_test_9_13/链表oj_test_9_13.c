#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return head;
//    }
//
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//
//        if (n3)
//        {
//            n3 = n3->next;
//        }
//
//    }
//
//    return n1;
//}

//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newnode = NULL;
//
//
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = newnode;
//        newnode = cur;
//
//        cur = next;
//
//    }
//
//    return newnode;;
//}

//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//
//    return slow;
//}

//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    // write code here
//    struct ListNode* fast = pListHead;
//    struct ListNode* slow = pListHead;
//    while (k--)
//    {
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}

//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//    if (l1 == NULL)
//        return l2;
//    if (l2 == NULL)
//        return l1;
//
//    struct ListNode* n1 = l1;
//    struct ListNode* n2 = l2;
//    struct ListNode* n3 = NULL;
//    struct ListNode* newhead = NULL;
//    while (n1 && n2)
//    {
//
//        if (n1->val < n2->val)
//        {
//            if (n3 == NULL)
//            {
//                newhead = n3 = n1;
//            }
//            else
//            {
//                n3->next = n1;
//                n3 = n1;
//            }
//            n1 = n1->next;
//        }
//        else
//        {
//            if (n3 == NULL)
//            {
//                newhead = n3 = n2;
//            }
//            else
//            {
//                n3->next = n2;
//                n3 = n2;
//            }
//            n2 = n2->next;
//        }
//
//
//    }
//
//    if (n1)
//        n3->next = n1;
//    if (n2)
//        n3->next = n2;
//    return newhead;
//
//}

int main(void)
{



	return 0;

}