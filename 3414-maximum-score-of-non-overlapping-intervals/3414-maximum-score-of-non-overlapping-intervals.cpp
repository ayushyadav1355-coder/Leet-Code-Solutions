#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int l, r, w, id;
};

struct State {
    long long weight;
    vector<int> indices;

    bool operator<(const State& other) const {
        if (weight != other.weight) {
            return weight < other.weight;
        }
        return indices > other.indices;
    }
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });

        vector<vector<State>> dp(n + 1, vector<State>(5, {0, {}}));

        for (int i = 1; i <= n; ++i) {
            int l = arr[i - 1].l;
            int r = arr[i - 1].r;
            int w = arr[i - 1].w;
            int id = arr[i - 1].id;

            int low = 0, high = i - 2, best_prev = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].r < l) {
                    best_prev = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            int p_idx = best_prev + 1;

            for (int k = 0; k <= 4; ++k) {
                dp[i][k] = dp[i - 1][k];
            }

            for (int k = 1; k <= 4; ++k) {
                if (k == 1 || dp[p_idx][k - 1].weight > 0 || (k - 1 == 0)) {
                    long long cand_weight = dp[p_idx][k - 1].weight + w;
                    vector<int> cand_indices = dp[p_idx][k - 1].indices;
                    cand_indices.push_back(id);
                    sort(cand_indices.begin(), cand_indices.end());

                    State cand = {cand_weight, cand_indices};
                    if (dp[i][k] < cand) {
                        dp[i][k] = cand;
                    }
                }
            }
        }

        State best = {0, {}};
        for (int k = 1; k <= 4; ++k) {
            if (best < dp[n][k]) {
                best = dp[n][k];
            }
        }

        return best.indices;
    }
};