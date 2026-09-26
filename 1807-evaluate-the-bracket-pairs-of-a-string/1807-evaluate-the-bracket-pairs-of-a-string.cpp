#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string result = "";
        string current_key = "";
        bool in_bracket = false;
        
        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
                current_key = "";
            } else if (c == ')') {
                in_bracket = false;
                if (dict.count(current_key)) {
                    result += dict[current_key];
                } else {
                    result += '?';
                }
            } else {
                if (in_bracket) {
                    current_key += c; 
                } else {
                    result += c;      
                }
            }
        }
        
        return result;
    }
};