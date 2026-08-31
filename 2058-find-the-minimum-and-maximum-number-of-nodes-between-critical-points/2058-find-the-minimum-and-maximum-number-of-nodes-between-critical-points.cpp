/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int first_cp = -1;
        int prev_cp = -1;
        int min_dist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1; // 0-indexed position of curr

        while (curr->next != nullptr) {
            bool is_max = (curr->val > prev->val && curr->val > curr->next->val);
            bool is_min = (curr->val < prev->val && curr->val < curr->next->val);

            if (is_max || is_min) {
                if (first_cp == -1) {
                    first_cp = idx;
                } else {
                    min_dist = min(min_dist, idx - prev_cp);
                }
                prev_cp = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (first_cp == -1 || first_cp == prev_cp) {
            return {-1, -1};
        }

        int max_dist = prev_cp - first_cp;
        return {min_dist, max_dist};
    }
};