#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int romanToInt(string s) {
        int result = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            result += roman[s[i]];
            if (i > 0 && roman[s[i - 1]] < roman[s[i]]) {
                result -= roman[s[i - 1]];
                i--;
            }
        }

        return result;
    }

    int romanToIntOld(string s) {
        int result = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            char element = s[i];
            unordered_map<char, int>::const_iterator itor = roman.find(element);

            if (itor != roman.end()) {
                result += itor->second;
                if (i > 0) {
                    char prev_element = s[i - 1];
                    unordered_map<char, int>::const_iterator prev_itor =
                        roman.find(prev_element);

                    if (prev_itor != roman.end() &&
                        prev_itor->second < itor->second) {
                        result -= prev_itor->second;
                        i--;
                    }
                }
            }
        }

        return result;
    }

    int romanToIntError(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int result = 0;

        for (size_t i = 0; i < s.size(); i++) {
            char element = s[i];
            unordered_map<char, int>::const_iterator itor = roman.find(element);

            if (itor != roman.end()) {
                result += itor->second;
                char prev_element = s[i + 1];
                unordered_map<char, int>::const_iterator prev_itor =
                    roman.find(prev_element);

                if (prev_itor != roman.end()) {
                    char next_prev_element = s[i + 2];
                    unordered_map<char, int>::const_iterator next_prev_itor =
                        roman.find(next_prev_element);

                    if (next_prev_itor != roman.end() &&
                        next_prev_itor->second / 10 == prev_itor->second) {
                        result += (next_prev_itor->second - prev_itor->second);
                    }
                }
            }
        }

        return result;
    }
};
