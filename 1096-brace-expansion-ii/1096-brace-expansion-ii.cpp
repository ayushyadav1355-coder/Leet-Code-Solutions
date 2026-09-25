class Solution {
    set<string> parseExpr(const string& s, int& i) {
        set<string> res = parseTerm(s, i);
        while (i < s.length() && s[i] == ',') {
            i++;
            set<string> next = parseTerm(s, i);
            res.insert(next.begin(), next.end());
        }
        return res;
    }

    set<string> parseTerm(const string& s, int& i) {
        set<string> res = {""};
        while (i < s.length() && s[i] != ',' && s[i] != '}') {
            set<string> f = parseFactor(s, i);
            set<string> next_res;
            for (const string& a : res) {
                for (const string& b : f) {
                    next_res.insert(a + b);
                }
            }
            res = move(next_res);
        }
        return res;
    }

    set<string> parseFactor(const string& s, int& i) {
        if (s[i] == '{') {
            i++; 
            set<string> res = parseExpr(s, i);
            i++; 
            return res;
        } else {
            string temp = "";
            while (i < s.length() && isalpha(s[i])) {
                temp += s[i++];
            }
            return {temp};
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = parseExpr(expression, i);
        return vector<string>(res.begin(), res.end());
    }
};