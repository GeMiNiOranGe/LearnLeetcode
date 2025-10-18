#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> matching = {
            {')', '('}, {']', '['}, {'}', '{'}};

        std::stack<char> parentheses;

        for (char element : s) {
            if (element == '(' || element == '[' || element == '{') {
                parentheses.push(element);
            } else if (matching.contains(element)) {
                if (parentheses.empty() || parentheses.top() != matching[element]) {
                    return false;
                }
                parentheses.pop();
            }
        }

        return parentheses.empty();
    }

    bool isValidOld(std::string s) {
        std::stack<char> parentheses;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parentheses.push(s[i]);
            } else if (s[i] == ')') {
                if (!parentheses.empty() && parentheses.top() == '(') {
                    parentheses.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (!parentheses.empty() && parentheses.top() == '[') {
                    parentheses.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (!parentheses.empty() && parentheses.top() == '{') {
                    parentheses.pop();
                } else {
                    return false;
                }
            }
        }

        return parentheses.empty();
    }
};
