// dfs (depth first search, ���� �켱 Ž��)
// �ð� ���⵵ O(|V| + |E|)
//
//���� �ڷ�
//https://ko.wikipedia.org/wiki/%EA%B9%8A%EC%9D%B4_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89
//http://blog.eairship.kr/268
//
//����
//1260 dfs�� bfs https://www.acmicpc.net/problem/1260
//2178 �̷� Ž�� https://www.acmicpc.net/problem/2178
//2589 ������ https://www.acmicpc.net/problem/2589
//4963 ���� ���� https://www.acmicpc.net/problem/4963
//1697 ���ٲ��� https://www.acmicpc.net/problem/1697
//11403 ��� ã�� https://www.acmicpc.net/problem/11403
// 5014 ��ŸƮ ��ũ https://www.acmicpc.net/problem/5014
//2468 ���� ���� https://www.acmicpc.net/problem/2468

using namespace std;

// �Ϲ� �׷����󿡼��� dfs
#include <vector>
#define MAX_V 100000

vector<int>G[MAX_V]; // �Ϲ����� ���� �׷���
bool visited[MAX_V];	// ������ �湮�ߴ��� üũ�ϴ� �迭
						// false -> ���� �湮���� ����
						// true -> �̹� �湮 ����
void dfs(int cur) {
	if (visited[cur] == true) return;
	visited[cur] = true;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (visited[next] == false)
			dfs(next);
	}
}

// ����(�׸���) �׷��� �󿡼� dfs
#define DIRECTION_SIZE 4
#define MAX_N 1000
#define MAX_M 1000
int dx[DIRECTION_SIZE] = { 1,-1,0,0 };// �̵������� �����ϴ� dx,dy �迭
int dy[DIRECTION_SIZE] = { 0,0,1,-1 };
int grid_visited[MAX_N][MAX_M]; // N*M ¥�� ���� �׷������� �湮�ߴ��� üũ�ϴ� �迭
								// false -> ���� �湮���� ����
								// true -> �̹� �湮 ����
void dfs(int x, int y) {
	if (grid_visited[x][y] == true)return;
	grid_visited[x][y] = true;
	for (int i = 0; i < DIRECTION_SIZE; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		//��� �� �˻� ���� �׷������� ����°��� �����Ѵ�
		if (a < 0 || MAX_N <= a) continue;
		if (b < 0 || MAX_N <= b) continue;

		if (grid_visited[a][b] == false) 
			dfs(a,b);
	}
}
