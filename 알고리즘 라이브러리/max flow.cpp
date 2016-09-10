// maxflow (�ִ�����)
//
//�˰����� ���� �ϰ� ���°͵� �߿������� �׷����� �𵨸��ϴ� ����� �������Ѵ�
//
//Ford-Fulkerson, edmond karp �ΰ��� ������ִ�
//Ford_Fulkerson �� ��θ� dfs �� ã��
//edmond karp �� ��θ� bfs �� ã�´�
//�Ϲ������� dfs�� ���°ͺ��ٴ� bfs �� ���¹���� �� ������
//�� ���� ������δ� Dinic algorithm, Hopcroft-karp �� ������ �����Ѵ�
//
//�ð� ���⵵ O(V*E^2)
//
//�����ڷ�
//https://en.wikipedia.org/wiki/Maximum_flow_problem
//https://1ambda.github.io/91/algorithm/algorithm-part2-5/
//http://m.blog.naver.com/choyi0521/80207731515
//http://musicdiary.egloos.com/4207458
//http://musicdiary.egloos.com/4213579
//
//����
//11375 ������ȣ https://www.acmicpc.net/problem/11375
//2188 ��� ���� https://www.acmicpc.net/problem/2188
//1298 ��Ʈ���� ������ ã�Ƽ� https://www.acmicpc.net/problem/1298
//1017 �Ҽ� �� https://www.acmicpc.net/problem/1017
//11376 ������ȣ 2 https://www.acmicpc.net/problem/11376
//1671 ����� ����Ļ� https://www.acmicpc.net/problem/1671
//11377 ������ȣ 3 https://www.acmicpc.net/problem/11377
//11378 ������ȣ 4 https://www.acmicpc.net/problem/11378
//1799 ��� https://www.acmicpc.net/problem/1799
//2316 ���� �պ��ϱ� https://www.acmicpc.net/problem/2316


#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

//���� ��� ����
#define MAX_V 1000
#define INF 2e9
#define pii pair<int,int>
int G[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int maxflow(int s,int t) {
	int maxflow = 0;
	
	while (1) {
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty() && parent[t] != -1) {
			int cur = q.front(); q.pop();

			for (int next = 0; next < MAX_V; next++) {
				if (G[cur][next] == false) continue;
				if (parent[next] == -1 && flow[cur][next] > 0) {
					parent[next] = cur;
					q.push(next);
				}
			}
		}
		if (parent[t] == -1) break;

		int amount = INF;
		for (int p = s; parent[p] != -1; p = parent[p]) {
			amount = min(amount, flow[parent[p]][p]);
		}

		for (int p = s; parent[p] != -1; p = parent[p]) {
			G[parent[p]][p] -= amount;
			G[p][parent[p]] += amount;
		}
		maxflow += amount;
	}
	return maxflow;
}

//���� ����Ʈ ����
struct Maxflow {
	int size;
	struct Edge {
		int next;
		int flow;
		int rev_index;
		Edge(int n, int f, int r) {
			next = n;
			flow = f;
			rev_index = r;
		}
	};
	vector< vector<Edge> > G;

	Maxflow(int n) {
		size = n;
		G.assign(size, vector<Edge>());
	}

	void make_edge(int cur, int next, int flow, int rev_flow) {
		Edge A(next, flow, G[next].size());
		Edge B(cur, rev_flow, G[cur].size());
		G[cur].push_back(A);
		G[next].push_back(B);
	}

	int bfs(int s, int t) {
		vector <pii> parent(size, pii(-1, -1));
		vector <bool> check(size, false);
		queue<int>q;
		q.push(s);
		check[s] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int i = 0; i < G[cur].size(); i++) {
				Edge &e = G[cur][i];

				if (e.flow > 0 && check[e.next] == false) {
					check[e.next] = true;
					q.push(e.next);
					parent[e.next].first = cur;
					parent[e.next].second = i;
				}
			}
		}

		if (parent[t].first == -1) return 0;

		int flow = INF;
		for (int p = t; parent[p].first != -1; p = parent[p].first) {
			Edge &e = G[parent[p].first][parent[p].second];
			flow = min(flow, e.flow);
		}

		for (int p = t; parent[p].first != -1; p = parent[p].first) {
			Edge &e = G[parent[p].first][parent[p].second];
			e.flow -= flow;
			G[e.next][e.rev_index].flow += flow;
		}
		return flow;
	}

	int getmaxflow(int s, int t) {
		int maxflow = 0;
		int flow = 0;
		while (flow = bfs(s, t))
			maxflow += flow;
		return maxflow;
	}
};

