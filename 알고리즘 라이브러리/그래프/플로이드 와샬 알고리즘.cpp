//�÷��̵� �ͼ� �˰���
//
//�ð� ���⵵ O(V^3)
//
//�����ڷ�
//https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
//http://m.blog.naver.com/cky5122/80195173113
//
//����
//11403 ��� ã�� https://www.acmicpc.net/problem/11403
//11404 �÷��̵� https://www.acmicpc.net/problem/11404
//1389 �ɺ� �������� 6�ܰ� ��Ģ https://www.acmicpc.net/problem/1389
//1238 ��Ƽ https://www.acmicpc.net/problem/1238
//2606 ���̷��� https://www.acmicpc.net/problem/2606

using namespace std;

//���� ��� �ϋ�
#define MAX_V 100

int G[MAX_V][MAX_V];
int n;
void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (G[j][k] > G[j][i] + G[i][k]) {
					G[j][k] = G[j][i] + G[i][k];
				}
			}
		}
	}
}