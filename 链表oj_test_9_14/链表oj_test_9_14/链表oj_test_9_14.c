#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

//typedef struct ListNode 
//{
//    int val;
//    struct ListNode* next;
//}ListNode;
//
//ListNode* FindMidList(ListNode* head)
//{
//    ListNode* fast = head;
//    ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//
//        fast = fast->next->next;
//    }
//
//    return slow;
//}
//
//ListNode* reverse(ListNode* head)
//{
//    if (head == NULL)
//    {
//        return head;
//    }
//    ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//
//
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//
//
//        if (n3)
//        {
//            n3 = n3->next;
//        }
//
//
//    }
//
//    return n1;
//}
//bool chkPalindrome(ListNode* A)
//{
//    // write code here
//    ListNode* mid = FindMidList(A);
//    ListNode* rev = reverse(mid);
//
//    while (A && rev)
//    {
//        if (A != rev)
//            return false;
//        A = A->next;
//        rev = rev->next;
//    }
//    return true;
//}
//
//void ListNodePushBack(ListNode** head, int x)
//{
//    
//
//
//}

//class PalindromeList {
//public:
//    ListNode* FindMidList(ListNode* head)
//    {
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//
//            fast = fast->next->next;
//        }
//
//        return slow;
//    }
//
//    ListNode* reverse(ListNode* head)
//    {
//        if (head == NULL)
//        {
//            return head;
//        }
//        ListNode* n1, * n2, * n3;
//        n1 = NULL;
//        n2 = head;
//        n3 = head->next;
//
//
//
//
//        while (n2)
//        {
//            n2->next = n1;
//            n1 = n2;
//            n2 = n3;
//
//
//
//
//            if (n3)
//            {
//                n3 = n3->next;
//            }
//
//
//
//
//        }
//
//        return n1;
//    }
//    bool chkPalindrome(ListNode* A)
//    {
//        // write code here
//        ListNode* mid = FindMidList(A);
//        ListNode* rev = reverse(mid);
//        while (A && rev)
//        {
//            if (A->val != rev->val)
//                return false;
//            A = A->next;
//            rev = rev->next;
//        }
//        return true;
//    }
//};

//int ListNodeLength(struct ListNode* head)
//{
//    int len = 0;
//    while (head)
//    {
//        len++;
//        head = head->next;
//    }
//    return len;
//}
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    int lenA = ListNodeLength(headA);
//    int lenB = ListNodeLength(headB);
//
//    struct ListNode* longList = headA;
//    struct ListNode* shortList = headB;
//    if (lenA < lenB)
//    {
//        longList = headB;
//        shortList = headA;
//    }
//    int gap = abs(lenA - lenB);
//
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//
//    while (longList && shortList)
//    {
//        if (longList == shortList)
//            return longList;
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//    return NULL;
//
//}

//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//            return true;
//
//    }
//    return false;
//}

//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    struct ListNode* sslow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            struct ListNode* meet = slow;
//            while (meet != sslow)
//            {
//                meet = meet->next;
//                sslow = sslow->next;
//            }
//            return meet;
//
//        }
//
//    }
//    return NULL;
//
//}

//int main(void)
//{
//    ListNode* n1 = NULL;
//    ListNodePushBack(n1, 3);
//    ListNodePushBack(n1, 2);
//    ListNodePushBack(n1, 1);
//    ListNodePushBack(n1, 2);
//    ListNodePushBack(n1, 3);
//
//    printf("%d\n", chkPalindrome(n1));
//
//	return 0;
//
//}