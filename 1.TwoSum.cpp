#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // can also use `if (seen.find(complement) != seen.end())`
            // but it is slower
            if (seen.contains(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }

    vector<int> twoSumOld(vector<int> &nums, int target) {
        vector<int> result;

        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }
};
