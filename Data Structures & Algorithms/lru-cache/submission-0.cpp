class LRUCache {
private:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    // key → address of node in linked list
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Add node immediately after head
    void addFront(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove node from linked list
    void removeNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:

    LRUCache(int capacity) {

        this->capacity = capacity;

        // Dummy nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // This node was just used,
        // so move it to the front
        removeNode(node);
        addFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // Mark as recently used
            removeNode(node);
            addFront(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;
        addFront(node);

        // Cache exceeded capacity
        if (mp.size() > capacity) {

            // Least recently used node
            Node* lru = tail->prev;

            removeNode(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};