#include <bits/stdc++.h>

using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	// base case
	if (n == 0 || W == 0)
		return 0;

	// recursive cases
	if (wt[n - 1] <= W) {
		return max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),
		           Knapsack(wt, val, W, n - 1));
	}
	else if (wt[n - 1] > W)
		return Knapsack(wt, val, W, n - 1);
	else
		return -1; // to avoid warning
}

signed main() {
	int n; cin >> n; // number of items
	int val[n], wt[n]; // values and wts array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; // Knappsack capacity

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}