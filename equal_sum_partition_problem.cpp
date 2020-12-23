#include <bits/stdc++.h>
using namespace std;

bool EqualSumPartitionPossible(int arr[], int n) {
	int sum = 0; // sum of all elements of arr
	for (int i = 0; i < n; i++)
		sum += arr[i];

	if (sum % 2 != 0) // if sum is odd --> not possible to make equal partitions
		return false;
	sum /= 2; // modify sum to target value of sum

	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = false;
			if (j == 0)
				t[i][j] = true;
		}
	}

	// same code as subset sum problem
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j - arr[i - 1] >= 0)
				t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
			else t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	EqualSumPartitionPossible(arr, n) ? cout << "YES\n" : cout << "NO\n";
	return 0;
}