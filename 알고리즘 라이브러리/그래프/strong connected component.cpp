//strong connected component (������ ���)
//
//�ڻ���� �˰���, Ÿ�� �˰��� �ΰ��� ������ �ִ�
//
////
//�ð����⵵
//�ڻ���� �˰��� O( V + E)
//
//�����ڷ�
//http://egloos.zum.com/musicdiary/v/4243023
//http://wiki.yonseics.net/Strongly_Connected_Component
//https://hgkim.gitbooks.io/algorithm/content/scc.html
//
//����
//
//2150 Strongly Connected Component


//�ڻ���� �˰��� 
#include <vector>
#include <algorithm>
using namespace std;

#define all(x)			(x).begin(),(x).end()
#define MAXN			10001

int n, m;
vector<int> G[MAXN], revG[MAXN];
int check[MAXN];
vector<int> vcheck;
void numbering_dfs(int cur) {
	if (check[cur]) return;
	check[cur] = true;

	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		numbering_dfs(next);
	}
	vcheck.push_back(cur);
}

void find_cc_dfs(int cur, vector<int> &cc) {
	if (check[cur]) return;
	check[cur] = true;

	for (int i = 0; i < revG[cur].size(); i++) {
		int next = revG[cur][i];
		find_cc_dfs(next, cc);
	}
	cc.push_back(cur);
}

vector< vector<int> > find_scc() {
	vector< vector<int> > scc;
	memset(check, 0, sizeof(check));
	for (int i = 1; i <= n; i++)
		numbering_dfs(i);

	memset(check, 0, sizeof(check));
	reverse(all(vcheck));
	for (int i = 0; i < n; i++) {
		int start = vcheck[i];
		vector<int> cc;
		find_cc_dfs(start, cc);
		if (cc.size() > 0) {
			sort(all(cc));
			scc.push_back(cc);
		}
	}

	return scc;
}








