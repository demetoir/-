//���װ�� (�Ľ�Į�� �ﰢ��)
//
//
//�ð����⵵ O(n*k)
//
//

//dp�� ���ϴ� ���
#define MAX_N 1000
int bi[MAX_N][MAX_N];
void make_binomial() {
	bi[0][0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		for (int j = 0; j <= i; j++) {
			bi[i][j] = bi[i-1][j] + bi[i-1][j + 1];
		}
	}
}