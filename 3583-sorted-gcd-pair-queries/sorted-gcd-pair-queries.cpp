class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // Step 1: Frequency of each number
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // Step 2: Count numbers divisible by each d
        vector<long long> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // Step 3: Count pairs divisible by d
        vector<long long> exact(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
        }

        // Step 4: Inclusion-Exclusion
        // exact[d] = pairs having gcd exactly d
        for (int d = mx; d >= 1; d--) {
            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        // Step 5: Prefix sum
        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exact[d];
        }

        // Step 6: Answer queries
        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};