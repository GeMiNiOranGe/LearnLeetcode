// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy;
        ListNode *tail = &dummy;

        ListNode *p1 = list1;
        ListNode *p2 = list2;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                tail->next = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                tail->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            tail = tail->next;
        }

        ListNode *remaining = (p1 != nullptr) ? p1 : p2;
        while (remaining != nullptr) {
            tail->next = new ListNode(remaining->val);
            tail = tail->next;
            remaining = remaining->next;
        }

        return dummy.next;
    }

    ListNode *mergeTwoListsOld(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        ListNode *list1_walker = list1;
        ListNode *list2_walker = list2;

        ListNode *result = nullptr;

        if (list1_walker->val <= list2_walker->val) {
            result = new ListNode(list1_walker->val);
            list1_walker = list1_walker->next;
        } else {
            result = new ListNode(list2_walker->val);
            list2_walker = list2_walker->next;
        }

        ListNode *result_walker = result;

        while (list1_walker != nullptr && list2_walker != nullptr) {
            if (list1_walker->val <= list2_walker->val) {
                result_walker->next = new ListNode(list1_walker->val);
                result_walker = result_walker->next;
                list1_walker = list1_walker->next;
            } else {
                result_walker->next = new ListNode(list2_walker->val);
                result_walker = result_walker->next;
                list2_walker = list2_walker->next;
            }
        }

        while (list1_walker != nullptr) {
            result_walker->next = new ListNode(list1_walker->val);
            result_walker = result_walker->next;
            list1_walker = list1_walker->next;
        }

        while (list2_walker != nullptr) {
            result_walker->next = new ListNode(list2_walker->val);
            result_walker = result_walker->next;
            list2_walker = list2_walker->next;
        }

        return result;
    }
};
