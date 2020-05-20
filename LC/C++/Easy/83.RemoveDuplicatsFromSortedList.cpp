class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)
        {
            return head;
        }
        ListNode* headptr = head;
        while(head->next != NULL)
        {
            if(head->val == head->next->val)
            {
                head->next = head->next->next;
            }
            else
            {
                head = head->next;
            }
        }
        head = headptr;
        return head;
    }
};
