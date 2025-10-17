#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        std::string result;

        /*
        [
            "flower",  // strs[0][0] -> j = 0, i = 0
            "flow",    // strs[1][0] -> j = 1, i = 0
            "flight"   // strs[2][0] -> j = 2, i = 0
        ]
        */
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return result;
                }
            }
            result += strs[0][i];
        }

        return result;
    }
};
