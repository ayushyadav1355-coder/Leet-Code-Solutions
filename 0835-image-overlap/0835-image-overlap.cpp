#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) {
                    ones1.push_back({r, c});
                }
                if (img2[r][c] == 1) {
                    ones2.push_back({r, c});
                }
            }
        }

        map<pair<int, int>, int> shifts;
        int max_overlap = 0;

        for (auto& p1 : ones1) {
            for (auto& p2 : ones2) {
                pair<int, int> shift = {p2.first - p1.first, p2.second - p1.second};
                shifts[shift]++;
                max_overlap = max(max_overlap, shifts[shift]);
            }
        }

        return max_overlap;
    }
};