#include <bits/stdc++.h>
using namespace std;

int Solve(string X, int n) {
	int dp[n + 1][n + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i >= j) {
				dp[true][i][j] = (X[i] == 'T');
				dp[false][i][j] = (X[i] == 'F');
			}
		}
	}

	for (int i = 0; i < n; i += 2) {
		for (int j = i; j < n; j += 2) {
			if (i == j)
				dp[true][i][j] = (X[i] == 'T');
			else {
				for (int k = i + 1; k <= j; k += 2) {
					int l_T = dp[true][i][k - 1];
					int r_T = dp[true][k + 1][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i + 1; k < j; k += 2) {
				int l_T = dp[true][i][k - 1];
				int l_F = dp[false][i][k - 1];
				int r_T = dp[true][k + 1][j];
				int r_F = dp[false][k + 1][j];

				if (X[k] == '|') {
					if (isTrue == true)
						ans += l_T * r_T + l_T * r_F + l_F * r_T;
					else
						ans += l_F * r_F;
				}
				else if (X[k] == '&') {
					if (isTrue == true)
						ans += l_T * r_T;
					else
						ans += l_T * r_F + l_F * r_T + l_F * r_F;
				}
				else if (X[k] == '^') {
					if (isTrue == true)
						ans += l_T * r_F + l_F * r_T;
					else
						ans += l_T * r_T + l_F * r_F;
				}
			}
		}
	}

	return dp[1][1][n];
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	string X; cin >> X;

	memset(dp[0], -1, sizeof(dp[0]));
	memset(dp[1], -1, sizeof(dp[1]));

	cout << Solve(X, X.length()) << endl;
	return 0;
}