#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int current_index = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[current_index]) {
                nums[++current_index] = nums[i];
            }
        }

        return current_index + 1;
    }

    int removeDuplicatesOld(vector<int>& nums) {
        int length = nums.size();
        int temp = -101;

        for (int i = 0; i < length; i++) {
            if (nums[i] == temp) {
                nums.erase(nums.begin() + i);
                i--;
                length--;
            } else {
                temp = nums[i];
            }
        }

        return length;
    }
};
