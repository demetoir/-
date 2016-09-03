//bellman-ford short path (����-���� �ִܰ��)
//�ð����⵵ O(V*E)
//
//���� ����Ŭ �Ǻ� ������
//
//�����ڷ�
//https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
//http://koosaga.myungwoo.kr/entry/Floyd-Warshall-Bellman-Ford-Dijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
//http://blog.naver.com/PostView.nhn?blogId=infoefficien&logNo=220100077659&parentCategoryNo=&categoryNo=65&viewDate=&isShowPopularPosts=true&from=search
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
void bellman_ford(int start) {
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







