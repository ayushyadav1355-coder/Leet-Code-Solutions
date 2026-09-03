#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string winningPlayer(int x, int y) {
        int rounds = min(x, y / 4);
        return (rounds % 2 == 1) ? "Alice" : "Bob";
    }
};