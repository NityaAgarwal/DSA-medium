// https://leetcode.com/problems/top-k-frequent-elements/description/

#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        queue<int> q;

        for (int i = 0; i < nums.size(); i++) {
            if (!m.count(nums[i])) {
                m[nums[i]] = 1;
                q.push(nums[i]);
            } else {
                m[nums[i]] += 1;
            }
        }

        vector<vector<int>> v(nums.size() - k + 1);
        /*
In your code, you're using `v` to store elements based on their frequencies. The outer vector `v` represents frequency buckets, 
where `v[i]` holds elements with frequency `i + 1` (since frequency starts from 1).

Consider the scenario where you have `n` elements and you want to find the top `k` frequent elements. 
The maximum frequency that any element can have is `n`. Therefore, the number of frequency buckets needed is `n - k + 1`. 
This ensures that you have enough buckets to accommodate all possible frequencies from 1 to `n - (n - k + 1) = k`.

Let's break it down:
- If `k = n`, then you would need `n - n + 1 = 1` bucket to accommodate all possible frequencies from 1 to `n`.
- If `k = 1`, then you would need `n - 1 + 1 = n` buckets to accommodate all possible frequencies from 1 to `n`.

So, `vector<vector<int>> v(nums.size() - k + 1);` is used to initialize `v` with the appropriate number of frequency buckets based on the value of `k`.
        */
        while (!q.empty()) {
            int key = q.front();
            int freq = m[key];
            q.pop();
            v[freq-1].push_back(key);
        }

        vector<int> ans;
        for (int i = v.size() - 1; i >= 0 && ans.size() < k; i--) {
            if (!v[i].empty()) {
                ans.insert(ans.end(), v[i].begin(), v[i].end());
            }
        }

        return ans;
    }
};
