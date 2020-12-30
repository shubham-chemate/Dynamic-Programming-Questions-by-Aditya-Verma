
class Solution {
    int dp[107][10007];
public:
    int Solve(int eggs, int floors) {
        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        if (eggs == 1 || floors == 0 || floors == 1) {
            dp[eggs][floors] = floors;
            return floors;
        }

        int ans = floors;
        int low = 1, high = floors;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int bottom = Solve(eggs - 1, mid - 1); // egg broke
            int top = Solve(eggs, floors - mid); // egg doesn't broke
            int temp = 1 + max(top, bottom); // max for worst case
            if (bottom < top) // go upward for worst case
                low = mid + 1;
            else // go downward for worst case
                high = mid - 1;

            ans = min(ans, temp);
        }

        return dp[eggs][floors] = ans;
    }
    int superEggDrop(int K, int N) {
        memset(dp, -1, sizeof(dp));
        return Solve(K, N);
    }
};