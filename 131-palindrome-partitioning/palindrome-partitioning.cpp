#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        
        // PART 1: Your exact first loop
        // Traverse i = 0 till string length and push every element one by one into current
        for (int i = 0; i < s.length(); i++) {
            current.push_back(string(1, s[i]));
        }
        // Close the for loop and push current vector into result vector
        result.push_back(current);
        
        // PART 2: Your concatenation approach (without sort so "efe" stays in order)
        // Track seen partitions so we never push duplicates like in "ab"
        set<vector<string>> seen;
        seen.insert(current);
        
        // Go through result and check if adjacent elements are the same
        for (int r = 0; r < result.size(); r++) {
            vector<string> base = result[r];
            
            // 1. Your check: if element i is same as element i + 1, concatenate and push!
            for (int i = 0; i + 1 < base.size(); i++) {
                if (base[i].length() == 1 && base[i] == base[i + 1]) {
                    current.clear();
                    for (int k = 0; k < base.size(); k++) {
                        if (k == i) {
                            current.push_back(base[i] + base[i + 1]); // Concatenate
                            k++; // Skip i + 1
                        } else {
                            current.push_back(base[k]);
                        }
                    }
                    if (seen.find(current) == seen.end()) {
                        seen.insert(current);
                        result.push_back(current);
                    }
                }
            }
            
            // 2. Same check for 1 element in between (e.g., "e", "f", "e" -> "efe")
            for (int i = 0; i + 2 < base.size(); i++) {
                if (base[i].length() == 1 && base[i] == base[i + 2]) {
                    current.clear();
                    for (int k = 0; k < base.size(); k++) {
                        if (k == i) {
                            current.push_back(base[i] + base[i + 1] + base[i + 2]); // Concatenate
                            k += 2; // Skip i + 1 and i + 2
                        } else {
                            current.push_back(base[k]);
                        }
                    }
                    if (seen.find(current) == seen.end()) {
                        seen.insert(current);
                        result.push_back(current);
                    }
                }
            }
        }
        
        return result;
    }
};
