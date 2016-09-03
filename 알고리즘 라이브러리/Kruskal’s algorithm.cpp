// Kruskal��s algorithm (ũ�罺Į �˰���)
//
//�ð� ���⵵ O(Elog(v))
//
//���� ����
//union-find �� set�� �ʿ��ϴ�
//
//�����ڷ�
//https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
//
//������
//����
//1197 �ּ� ���д� Ʈ�� https://www.acmicpc.net/problem/1197
//7627 ���д� Ʈ�� https://www.acmicpc.net/problem/7627
//
#include <vector>
#include <queue>
#include <set>
using namespace std;

//usion find�� ����� ũ�罺Į �˰���
#define MAX_V 10000
#define MAX_E 100000
struct Edge{
	int cur;
	int next;
	int cost;
};
Edge edge[MAX_E];

int parent[MAX_V];
int level[MAX_V];
int init_union_find() {
	for (int i = 0; i < MAX_V; i++) {
		parent[i] = i;
		level[i] = 0;
	}
}

int find(int cur){
	if (parent[cur] == cur)return cur;
	return parent[cur] = find(parent[cur]);
}

void unite(int A, int B) {
	int a = find(A);
	int b = find(B);
	if (a == b)return;

	if (level[a] < level[b]) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
		if (level[a] == level[b])
			level[a]++;
	}
}

bool cmp(Edge A, Edge B) {
	return A.cost < B.cost;
}

int Kruskal() {
	init_union_find();
	sort(edge, edge + MAX_E, cmp);
	int totalcost = 0;
	int edgecount = 0;
	for (int i = 0; i < MAX_E; i++) {
		int a = edge[i].cur;
		int b = edge[i].next;
		int cost = edge[i].cost;

		if (find(a) == find(b)) continue;
		
		unite(a, b);
		totalcost += cost;
		edgecount++;
		if (edgecount == MAX_V)
			break;
	}
	return totalcost;
}


//set�� �̿��� ũ�罺Į �˰���
//�̿ϼ�
set<int> vertex_set;
bool cmp(Edge A, Edge B) {
	return A.cost < B.cost;
}

int Kruskal() {
	sort(edge, edge + MAX_E, cmp);
	int totalcost = 0;
	int edgecount = 0;
	for (int i = 0; i < MAX_E; i++) {
		int a = edge[i].cur;
		int b = edge[i].next;
		int cost = edge[i].cost;

		if (find(a) == find(b)) continue;

		unite(a, b);
		totalcost += cost;
		edgecount++;
		if (edgecount == MAX_V)
			break;
	}
}



