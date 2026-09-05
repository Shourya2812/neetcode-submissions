class Solution {
public:
    
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        // If node is already cloned
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create clone
        Node* clone = new Node(node->val);

        // Store it BEFORE exploring neighbours
        mp[node] = clone;

        // Clone all neighbours
        for (Node* neighbour : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbour));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {

        if (node == nullptr)
            return nullptr;

        return dfs(node);
    }
};