//bfs(Breadth First Search, �ʺ� �켱 Ž��)
//�ð� ���⵵ O(|V| + |E|) ������ ���� + ������ ����
//
//����
//





#include <queue>
#include <vector>
using namespace std;

//�Ϲ� �׷��� �󿡼��� bfs
#define MAX_V 1001
vector <int>G[MAX_V];	// ���� �׷���
bool visited[MAX_V];	// ������ �湮�ߴ��� üũ�ϴ� �迭
						// false -> ���� �湮���� ����
						// true -> �̹� �湮 ����
void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}


// ����(�׸���) �׷��� �󿡼� bfs
#define MP pair<int,int> // x,y ��ǥ�� �����ϱ����� pair
#define DIRECTION_SIZE 4
#define MAX_N 1000
#define MAX_M 1000
int dx[DIRECTION_SIZE] = { 1,-1,0,0 };// �̵������� �����ϴ� dx,dy �迭
int dy[DIRECTION_SIZE] = { 0,0,1,-1 };
int grid_visited[MAX_N][MAX_M]; // N*M ¥�� ���� �׷������� �湮�ߴ��� üũ�ϴ� �迭
								// false -> ���� �湮���� ����
								// true -> �̹� �湮 ����
void bfs(int start_x, int start_y) {
	queue<MP> q;
	q.push(MP(start_x, start_y));
	grid_visited[start_x][start_y] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		for (int i = 0; i < DIRECTION_SIZE; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			
			//��� �� �˻� ���� �׷������� ����°��� �����Ѵ�
			if (a < 0 || MAX_N <= a) continue;
			if (b < 0 || MAX_N <= b) continue;
			
			if (grid_visited[a][b] == true) continue;

			q.push(MP(a, b));
			grid_visited[a][b] = true;
		}
	}
}