//https://leetcode.com/problems/reorder-list/

//NOTE - havent yet checked better solution for this - do that the next time you solve this
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextnode;
        while (curr) {
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //will find middle node - lets say N
        //list1 = from head to N, list2 = from N to tail
        //will reverse list2
        //merge list1 and list2 (as in - one node from both alternatively)
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        slow->next = NULL;
        list2 = reverseList(list2);

        ListNode* dummy = new ListNode (-1);
        ListNode* curr = dummy;
        while (head && list2) {
            curr->next = head;
            head = head->next;
            curr = curr->next;
            
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
        }
        if (head) {
            curr->next = head;
        }
        if (list2) {
            curr->next = list2;
        }
        
        head = dummy->next;
    }
};
