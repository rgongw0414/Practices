/*
此時背包裡面放了哪些物品

建立一個二維陣列，記錄每一個問題的答案，是由哪個子問題推導出來的。每個問題只有「放」或「不放」兩種情形。

這段程式碼只能找出其中一種組合方式，是字典順序最小的組合方式。只是列印順序剛好前後顛倒。
*/

const int N = 100, W = 100000;
int cost[N], weight[N];
int c[W + 1];
bool p[N][W + 1];	// 記錄放還是不放，false為不放，true為放。

void knapsack(int n, int w)
{
	memset(c, 0, sizeof(c));
	memset(p, false, sizeof(p));	// 初始化為false

	for (int i = 0; i < n; ++i)
		for (int j = w; j >= weight[i]; --j)
			if (c[j - weight[i]] + cost[i] > c[j])
			{
				c[j] = c[j - weight[i]] + cost[i];
				p[i][j] = true;	// 有放
			}

	cout << "最高的價值為" << c[w];

	// 往回逆推，求出背包內的所有物品。
	for (int i = n-1, j = w; i >= 0; --i)
		if (p[i][j])	// 背包有該物品
		{
			cout << "背包裡面有第" << i << "個物品";
			j -= weight[i];
		}
}