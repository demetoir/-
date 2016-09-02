//bellman-ford short path (����-���� �ִܰ��)
//�ð����⵵ O(V*E)
//
//���� ����Ŭ �Ǻ� ������
//
//����
//11657 Ÿ�Ӹӽ� https://www.acmicpc.net/problem/11657
//
//
//
//
//
#include <vector>
using namespace std;

//�Ϲ� �׷��� �󿡼� ���� ���� 
#define MAX_V 1000
#define INF 2e9
#define pii pair<int,int>
vector<pii> G[MAX_V];
vector<int> dist;
int bellman_ford(int start) {
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;

	for (int iter = 0; iter < MAX_V - 1; iter++) {
		bool isupdate = false;
		for (int i = 0; i < MAX_V; i++) {
			int cur = i;
			for (int j = 0; j < G[cur].size(); j++) {
				int next = G[cur][i].first;
				int cost = G[cur][i].first;
				if (dist[next] > dist[cur] + cost) {
					isupdate = true;
					dist[next] = dist[cur] + cost;
				}
			}
		}
		if (isupdate == false)
			break;
	} 

	//���� ����Ŭ �Ǻ�
	//��� �������	
	bool isupdate = false;
	for (int i = 0; i < MAX_V; i++) {
		int cur = i;
		for (int j = 0; j < G[cur].size(); j++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].first;
			if (dist[next] > dist[cur] + cost) {
				isupdate = true;
				dist[next] = dist[cur] + cost;
			}
		}
	}
	if (isupdate == true)
		printf("���� ����Ŭ �߰�");
}







