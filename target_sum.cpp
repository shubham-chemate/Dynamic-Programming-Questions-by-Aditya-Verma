// Target Sum

#include <bits/stdc++.h>
using namespace std;

int CountSubsetsWithSum(int arr[], int n, int sum) {
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization
	t[0][0] = 1;
	int k = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 && j > 0)
				t[i][j] = 0;
			if (j == 0 && i > 0) {
				if (arr[i - 1] == 0) {
					t[i][j] = pow(2, k);
					k++;
				}
				else
					t[i][j] = t[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}

int TargetSum(int arr[], int n, int diff) {
	int sumOfArray = 0;
	for (int i = 0; i < n; i++)
		sumOfArray += arr[i];

	if ((sumOfArray + diff) % 2 != 0)
		return 0;
	else
		return CountSubsetsWithSum(arr, n, (sumOfArray + diff) / 2);
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum; cin >> sum;

	cout << TargetSum(arr, n, sum) << endl;
	return 0;
}