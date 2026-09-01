#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct State {
    int r, c;
    int mask;
    int energy;
};

class Solution {
    int max_energy_seen[20][20][1024];

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int start_r = -1, start_c = -1;
        int litter_cnt = 0;
        int litter_idx[20][20];
        memset(litter_idx, -1, sizeof(litter_idx));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_idx[i][j] = litter_cnt++;
                }
            }
        }

        int target_mask = (1 << litter_cnt) - 1;
        if (target_mask == 0) return 0;

        memset(max_energy_seen, -1, sizeof(max_energy_seen));

        queue<State> q;
        q.push({start_r, start_c, 0, energy});
        max_energy_seen[start_r][start_c][0] = energy;

        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                State cur = q.front();
                q.pop();

                if (cur.mask == target_mask) {
                    return moves;
                }

                if (cur.energy == 0) {
                    continue;
                }

                for (int d = 0; d < 4; ++d) {
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int next_mask = cur.mask;
                    if (classroom[nr][nc] == 'L') {
                        next_mask |= (1 << litter_idx[nr][nc]);
                    }

                    int next_energy = (classroom[nr][nc] == 'R') ? energy : (cur.energy - 1);

                    if (next_energy > max_energy_seen[nr][nc][next_mask]) {
                        max_energy_seen[nr][nc][next_mask] = next_energy;
                        q.push({nr, nc, next_mask, next_energy});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};