//����� �ڸ��� dp
//
//
//
//
//���� �ڷ�
//
//
//����
//
//

#include <algorithm>
using namespace std;

//
//��͹��� 
#define MAX_N 100000
int dp1[MAX_N];
int A[MAX_N];
int find1(int x) {
	if (dp1[x] != 0) 
		return dp1[x];
	if (x < 0)
		return 0;

	int ret = 0;
	for (int i = 0; i < x; i++) {
		ret = max(dp1[i], ret + A[i]);
	}
	return;
}