class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;

        // Pass 1: Create copy of every node
        Node* curr = head;

        while (curr != NULL) {

            mp[curr] = new Node(curr->val);

            curr = curr->next;
        }

        // Pass 2: Connect next and random
        curr = head;

        while (curr != NULL) {

            mp[curr]->next = mp[curr->next];

            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};