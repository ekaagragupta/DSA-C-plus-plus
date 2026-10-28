class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    // Helper to find the representative (root) of a node with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Helper to unite two sets; returns false if already in the same set (cycle detected)
    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) {
            return false; // Cycle detected: this edge is redundant
        }

        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // 1-based indexing for graph vertices
        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        // Initialize each node to be its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Process edges in order
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            if (!unionSets(u, v)) {
                return edge; // Return the first edge that forms a cycle
            }
        }

        return {};
    }
};