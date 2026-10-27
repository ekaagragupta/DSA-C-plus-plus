class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<bitset<100>> prereq(numCourses);

        for (const auto& edge : prerequisites) {
            int u = edge[0]; // prerequisite
            int v = edge[1]; // course
            adj[u].push_back(v);
            prereq[v].set(u);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                // Pass down all prerequisites of curr to neighbor
                prereq[neighbor] |= prereq[curr];

                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto& qry : queries) {
            int u = qry[0];
            int v = qry[1];
            // Check if u is a prerequisite for v
            ans.push_back(prereq[v][u]);
        }

        return ans;
    }
};