class Solution {
public:
    vector<bool> pathExistenceQueries(int n,
                                      vector<int>& nums,
                                      int maxDiff,
                                      vector<vector<int>>& queries) {

        // component[i] = Connected Component number of node i
        vector<int> component(n);

        int comp = 0;
        component[0] = 0;

        // Build connected components.
        // Since nums is sorted, if two adjacent numbers differ by more than
        // maxDiff, then no node on the left can connect to any node on the right.
        for (int i = 1; i < n; i++) {

            // Gap too large -> start a new component
            if (nums[i] - nums[i - 1] > maxDiff)
                comp++;

            component[i] = comp;
        }

        vector<bool> ans;

        // Two nodes have a path between them
        // iff they belong to the same connected component.
        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            ans.push_back(component[u] == component[v]);
        }

        return ans;
    }
};