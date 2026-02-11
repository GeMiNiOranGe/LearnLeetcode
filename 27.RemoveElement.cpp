#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.empty()) {
            return 0;
        }

        int current_index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (val != nums[i]) {
                nums[current_index++] = nums[i];
            }
        }

        return current_index;
    }
};
