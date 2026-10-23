/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        Node* first = new Node(node->val, {});
        mp[node] = first;

        queue<Node*> q;
        q.push(node);
        while (q.empty() == false) {
            Node* curr = q.front();
            q.pop();
            for (auto adj: curr->neighbors) {
                if (mp.find(adj) == mp.end()) {
                    mp[adj] = new Node(adj->val, {}); // then create copy
                    q.push(adj);                      // push nto the queue
                }
                mp[curr]->neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
};