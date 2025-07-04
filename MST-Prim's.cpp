#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;


// reference: https://web.ntnu.edu.tw/~algo/SpanningTree.html#3

int adj[9][9];	// adjacency matrix
int d[9];		// 記錄目前的MST到圖上各點的距離
int parent[9];	// 記錄各個點在MST上的父親是誰
bool visit[9];	// 記錄各個點是不是已在MST之中

void prim() {
    // 如同 Dijkstra's Algorithm ，使用 Priority Queue 可以得到更低的時間複雜度。
	for (int i=0; i<9; i++) visit[i] = false;
	for (int i=0; i<9; i++) d[i] = INT_MAX;

	// 選擇任意一點作為樹根。此處選擇第零點作為樹根。
	d[0] = 0;
	parent[0] = 0;

	// 需要n-1個edge來建立n個node的MST
	// 每個iter新增一個edge (除了最初的iter)
	for (int i=0; i<9; i++) {
		// 找不在樹上、離樹最近的點。
		int a = -1, b = -1, min = 1e9;
		for (int j=0; j<9; j++) {
			if (!visit[j] && d[j] < min) {
				a = j;	// 持續記錄最近的點
				min = d[j];
			}
        }
		// 從起點可連通的點已經找完
		if (a == -1) break;
		visit[a] = true; // 新增一個 node (edge)，其 parent 已在前一個 iter 決定，可由 parent[a] access。

		// relaxation
		// 此處與Dijkstra's Algorithm不同
		// 離樹最近，不是離根最近。
		// 更新生成樹與新節點的鄰居間的最短距離
		for (b=0; b<9; b++) {
			if  (!visit[b] && adj[a][b] < d[b]) {
				d[b] = adj[a][b];
				parent[b] = a;
			}
        }
	}
}