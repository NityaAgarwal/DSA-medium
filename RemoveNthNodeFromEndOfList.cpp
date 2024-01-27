//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

//READ CAREFULLY - nth from end of list

class Solution {
public:
    int func(ListNode* head){
        int count {0};
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //nth FROM THE END is to be deleted
        //nth from the end = count-n+1 from the beginning
        int count = func(head);
        n = count-n+1;

        if (n == 1) //means return the node next to the first 
        {
            return head->next;
        }
        if (n > count) return head; //none deleted
        
        ListNode* curr = head; //either middle or last node deleted
        //either way - reach the n-1th node
        for (int i = 0; i<n-2; i++) {
            curr = curr->next;
        }

        if (n == count) {
            curr->next = NULL;
        }//last node deleted
        else {
            ListNode* join_here = curr->next->next;
            curr->next = join_here;
        }//some node in the middle deleted

        return head;
        
        
    }
};
