#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vec[1001];
int visited[1001];
int n, m, v;

void sortEdge() {
	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}
}

void initVisited() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

void dfs(int r) {
	visited[r] = true;
	printf("%d ", r);
	for (int i = 0; i < vec[r].size(); i++) {
		if (!visited[vec[r][i]]) {
			dfs(vec[r][i]);
			visited[vec[r][i]] = true;
		}
	}
}

void bfs(int r) {
	queue<int> q;
	q.push(r);
	visited[r] = true;

	while (!q.empty()) {
		int front = q.front();
		printf("%d ", front);
		q.pop();
		for (int i = 0; i < vec[front].size(); i++) {
			if (!visited[vec[front][i]]) {
				q.push(vec[front][i]);
				visited[vec[front][i]] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	sortEdge();
	initVisited();
	dfs(v);
	printf("\n");
	initVisited();
	bfs(v);

	return 0;
}