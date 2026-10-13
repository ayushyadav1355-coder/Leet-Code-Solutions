using ll = long long;
class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](ll a, ll b) {
            return abs(a)>abs(b);
        }); ll n = nums.size(); ll ans = 0;
        ll pos = (n+1)/2;
        for (ll x:nums) {
            if (pos>0) {
                ans += x*x;
                pos--;
            } else ans -= x*x;
        } return ans;
    }
};