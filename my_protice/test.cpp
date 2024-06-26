#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int solve(vector<int>& tasks) {
    int res = 2^31 - 1;
    vector<int> dp(tasks.size());
    dp[0] = tasks[0];
    for (size_t i = 1; i < tasks.size(); ++i) {
        dp[i] = dp[i - 1] + tasks[i];
    }

    for (size_t i = 0; i < dp.size(); ++i) {
        res = min(res, max(dp[i], dp.back() - dp[i]));
    }

    return res;
}

int minEditTime(int n, int k, vector<int>& tasks) {
    vector<int> list(tasks.begin(), tasks.end());

    sort(tasks.begin(), tasks.end());

    for (int i = 0; i < n - k; ++i) {
        auto it = find(list.begin(), list.end(), tasks[tasks.size() - 1 - i]);
        if (it != list.end()) {
            list.erase(it);
        }
    }

    return solve(list);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<int> tasks(n);
        for (int i = 0; i < n; ++i) {
            cin >> tasks[i];
        }

        int ans = minEditTime(n, k, tasks);
        cout << ans << endl;
    }

    return 0;
}