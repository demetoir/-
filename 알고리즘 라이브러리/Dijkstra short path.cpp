//dijkstra short path �ٟ彺Ʈ�� �ִܰ�� �˰���
//
//�ð� ���⵵ 
//ť ���� O(V^2)
//�켱���� ť ���� O( (|V| + |E|)log(|V|) )
//
//���� ���� :
//�׷��� �󿡼� ���� ����Ŭ�� ������Ѵ�
//
//�����ڷ�
//https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
//http://koosaga.myungwoo.kr/entry/Floyd-Warshall-Bellman-Ford-Dijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
//http://makefortune2.tistory.com/26
//
//
//����
//1753 �ִܰ�� https://www.acmicpc.net/problem/1753
//1916 �ּҺ�� ���ϱ� https://www.acmicpc.net/problem/1916
//1238 ��Ƽ https://www.acmicpc.net/problem/1238
//1504 Ư���� �ִܰ�� https://www.acmicpc.net/problem/1504
//5427 �� https://www.acmicpc.net/problem/5427
//2206 ���μ��� �̵��ϱ� https://www.acmicpc.net/problem/2206
//1981 �迭������ �̵� https://www.acmicpc.net/problem/1981
//
//�켱���� ť ���� ���� �Ϸ�

#include <queue>
#include <vector>
#include <functional>
using namespace std;

//�Ϲ����� �׷��� ������ �ٟ彺Ʈ�� �Ϲ� ť ���
#define MAX_V 100000
#define INF 2e9
#define pii pair<int,int>
vector<pii>G[MAX_V];	//G[a][b].first -> ���� ����
					//G[a][b].second -> ���� ���� ���� ���µ� ���

vector<int> dist;	//dist[i] -> ���� �������� ���� �ٸ� ���������� �Ÿ�
					//���� INF ��� �����ִ� ����� ����
int dijkstra(int start) {
	queue<int> q;
	q.push(start);
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				q.push(next);
			}
		}
	}
}


//�Ϲ����� �׷��� ������ �ٟ彺Ʈ�� �켱 ����ť ���
//�׳� ť�� ���°ͺ��� �� ������
#define MAX_V 100000
#define INF 2e9
#define pii pair<int,int>
vector<pii>G[MAX_V];	//G[a][b].first -> ���� ����
					//G[a][b].second -> ���� ���� ���� ���µ� ���

vector<int> dist;	//dist[i] -> ���� �������� ���� �ٸ� ���������� �Ÿ�
					//���� INF ��� �����ִ� ����� ����

int dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0,start));
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cur_dist > dist[cur]) continue;

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				pq.push(pii(dist[next],next));
			}
		}
	}
}



//���� �׷����϶��� �ٟ彺Ʈ��
#define pii pair<int,int> // x,y ��ǥ�� �����ϱ����� pair
#define DIRECTION_SIZE 4
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
int dx[DIRECTION_SIZE] = { 1,-1,0,0 };// �̵������� �����ϴ� dx,dy �迭
int dy[DIRECTION_SIZE] = { 0,0,1,-1 };
int grid_dist[MAX_N][MAX_M];// N*M ¥�� ���� �׷���
							// ���������κ����� �ִܰŸ�
int grid_cost[MAX_N][MAX_M];//grid_cost[a][b] -> a,b �� ���µ� ���

int dijkstra(int start_x,int start_y) {
	queue<pii> q;
	q.push(pii(start_x,start_y));
	memset(grid_dist, 0, sizeof(grid_dist));
	grid_dist[start_x][start_y] = 0;

	while (!q.empty()) {
		int x = q.front().first; 
		int y = q.front().second;
		q.pop();

		for (int i = 0; i <DIRECTION_SIZE; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			//��� �� �˻� ���� �׷������� ����°��� �����Ѵ�
			if (a < 0 || MAX_N <= a) continue;
			if (b < 0 || MAX_N <= b) continue;

			if (grid_dist[a][b] > grid_dist[x][y] + grid_cost[a][b]) {
				grid_dist[a][b] = grid_dist[x][y] + grid_cost[a][b];
				q.push(pii(a,b));
			}
		}
	}
}



// �ٟ彺Ʈ�󿡼� �ִ� ��θ� �˰�������
#define MAX_V 100000
#define INF 2e9
#define pii pair<int,int>
vector<pii>G[MAX_V];	//G[a][b].first -> ���� ����
					//G[a][b].second -> ���� ���� ���� ���µ� ���

vector<int> dist;	//dist[i] -> ���� �������� ���� �ٸ� ���������� �Ÿ�
					//���� INF ��� �����ִ� ����� ����
vector<int>parent;  //parent[i] -> i�������� �����ϴ� �������� ���µ� �ִ� �Ÿ��� ����
					//��� �������� 
int dijkstra(int start) {
	queue<int> q;
	q.push(start);
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;
	parent = vector<int>(MAX_V, -1);
	parent[start] = -1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				parent[next] = cur;
				q.push(next);
			}
		}
	}
}
void print_path(int end) {
	if (dist[end] == INF) {
		printf("path not exist\n");
		return;
	}
	for (int p = end; parent[p] != -1; p = parent[p]) {
		printf("%d ->%d", p, parent[p]);
	}
}