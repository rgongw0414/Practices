int prices[N];
int weights[N];
int c[N+1][W+1];
memset(prices, 0, sizeof(prices));
memset(weights, 0, sizeof(weights));
memset(c, 0, sizeof(c));

int knapsack(int n, int w) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (j - weights[i] < 0) {
				c[i][j] = c[i-1][j];
			}
			else {
				c[i][j] = max(
					c[i-1][j], 
					c[i-1][j-weights[i]] + prices[i]
				);
			}
		}
	}
	cout << "ans: " << c[n][w] << endl;
}