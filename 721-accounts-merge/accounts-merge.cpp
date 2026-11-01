


#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DisjointSet {
    unordered_map<string, string> parent;
public:
    string find(const string& i) {
        if (parent.find(i) == parent.end()) {
            parent[i] = i;
        }
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unionSets(const string& i, const string& j) {
        string rootI = find(i);
        string rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet dsu;
        unordered_map<string, string> emailToName;

        // Step 1 & 2: Build email-to-name mapping and perform Union operations
        for (const auto& acc : accounts) {
            const string& name = acc[0];
            const string& firstEmail = acc[1];

            for (size_t i = 1; i < acc.size(); ++i) {
                emailToName[acc[i]] = name;
                dsu.unionSets(firstEmail, acc[i]);
            }
        }

        // Step 3: Group emails by their root parent
        unordered_map<string, vector<string>> components;
        for (const auto& pair : emailToName) {
            const string& email = pair.first;
            string root = dsu.find(email);
            components[root].push_back(email);
        }

        // Step 4: Sort emails and construct the final output
        vector<vector<string>> result;
        for (auto& pair : components) {
            vector<string>& emails = pair.second;
            sort(emails.begin(), emails.end());
            
            vector<string> mergedAccount;
            mergedAccount.push_back(emailToName[pair.first]);
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            
            result.push_back(mergedAccount);
        }

        return result;
    }
};