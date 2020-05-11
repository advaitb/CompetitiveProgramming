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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *resultbuild, *resulthead;
        if (l1->val >= l2->val) {
            resultbuild = new ListNode(l2->val);
            l2 = l2->next;
        } else {
            resultbuild = new ListNode(l1->val);
            l1 = l1->next;
        }
        resulthead = resultbuild;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val >= l2->val) {
                resultbuild->next = new ListNode(l2->val);
                resultbuild = resultbuild->next;
                l2 = l2->next;
            } else {
                resultbuild->next = new ListNode(l1->val);
                ret_list = resultbuild->next;
                l1 = l1->next;
            }
        }
        while (l1 != NULL) {
            resultbuild->next = new ListNode(l1->val);
            ret_list = resultbuild->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            resultbuild->next = new ListNode(l2->val);
            ret_list = resultbuild->next;
            l2 = l2->next;
        }
        resultbuild = resulthead;
        return resultbuild;
    }
};
