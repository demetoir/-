//�������οԴٰ��� �ϴ� dp, �͸� ���� dp
//
//
//
//��ȭ��
//i<=j �϶�
//dp[i][j] = (dp[i+1][j] + i������ ����ó��, dp[i][j-1]+ j������ ����ó��)
//
//�����ڷ�
//
//
//����
//
//
//
//

//��͹���
#define MAX_N 1000
int dp1[MAX_N][MAX_N];
int find1(int i, int j) {
	//i <= j �̾���Ѵ�
	if (i > j)
		return false;

	if (dp1[i][j] == -1)
		return dp1[i][j];

	//base case ó��
	if (i == j) {
		dp1[i][i];
		return dp1[i][i];
	}


	dp1[i][j] = find1(i + 1, j) /*i�� ���� ����ó��*/,
		find1(i, j - 1) /*j�� ���� ���� ó��*/;

	return dp1[i][j];
}
//for�� ����
#define MAX_N 1000
int dp2[MAX_N][MAX_N];

int find2() {
	for (int i = 0; i < MAX_N; i++) {
		dp2[i][i] /*base case*/;
	}
	for (int len = 0; len < MAX_N-1; len++) {
		for (int i = 0; i < MAX_N - len; i++) {
			int j = i + len;
			dp2[i][j] = dp2[i + 1][j] /*i������ ����ó��*/,
				dp2[i][j - 1] /*j������ ���� ó��*/;
		}
	}
	return dp2[0][MAX_N - 1];
}