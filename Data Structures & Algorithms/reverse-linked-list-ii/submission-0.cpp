class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        // Dummy node handles the case where left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* before = dummy;

        // Move before to the node just before left
        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        // current is the first node of the section
        ListNode* current = before->next;

        // Reverse by moving nodes to the front
        for (int i = 0; i < right - left; i++) {

            ListNode* temp = current->next;

            current->next = temp->next;

            temp->next = before->next;

            before->next = temp;
        }

        return dummy->next;
    }
};