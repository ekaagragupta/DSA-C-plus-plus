#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        // State 1: Currently visiting (Cycle detected)
        if (state[node] == 1) return true;
        // State 2: Fully visited (No cycle in this component)
        if (state[node] == 2) return false;

        // Mark node as currently visiting
        state[node] = 1;

        for (int neighbor : adj[node]) {
            if (dfs(neighbor, adj, state)) {
                return true;
            }
        }

        // Mark node as fully visited (backtrack)
        state[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list: b -> a (to take course a, you must take b first)
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        // State array: 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> state(numCourses, 0);

        // Run DFS from every unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) {
                    return false; // Found a cycle, cannot finish all courses
                }
            }
        }

        return true; // No cycles found
    }
};