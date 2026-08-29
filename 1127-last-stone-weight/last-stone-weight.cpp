#include <vector>
#include <algorithm> // Required for make_heap, pop_heap, push_heap

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Convert the initial vector into a max-heap
        make_heap(stones.begin(), stones.end());
        
        while (stones.size() > 1) {
            // Extract the heaviest stone (y)
            pop_heap(stones.begin(), stones.end());
            int y = stones.back();
            stones.pop_back();
            
            // Extract the second heaviest stone (x)
            pop_heap(stones.begin(), stones.end());
            int x = stones.back();
            stones.pop_back();
            
            // If they are not equal, the remaining stone has weight y - x
            if (x != y) {
                stones.push_back(y - x);
                // Rearrange the vector to restore the max-heap property
                push_heap(stones.begin(), stones.end());
            }
        }
        
        // If the vector is empty, return 0. Otherwise, return the last remaining stone.
        return stones.empty() ? 0 : stones.front();
    }
};