//�̿ϼ�
//����� �ڸ��� dp
//
//
//�������� �����ϴ� �Ǵ� ���ʿ��� �����ϸ鼭 �����Ѵ�
//ū�����  =  �߸� ����� + �������� ���´� 
//�׸����� �����Ұ� �ʿ��ϴ�
//�⺻���� dp�̴�
//f(n) = f(n-1) + ����ó����
//
//
//���� �ڷ�
//
//
//����
//
//
//
//
//
//
//

#include <algorithm>
using namespace std;

//��ȭ�� f(n) = f(n-1) 
//��͹��� 
#define MAX_N 100000
int dp1[MAX_N];
int A[MAX_N];
int n;
int find1(int x) {
	if (dp1[x] != 0) 
		return dp1[x];

	//base case ó��
	if (x < 0)
		return 0;

	//ū ����� dp[x]�� ���Ѵ� 
	for (int i = 0; i < x; i++) {
		//���� �����dp[i]�� ����ó���� �����Ѵ�
		
	}
	return dp1[x];
}

//for�� ���� 
#define MAX_N 100000
int dp2[MAX_N];
int A[MAX_N];
int n;
int find2(int x) {
	//base case ó��
	dp2[0] = 0;

	for (int i = 1; i < x; i++) {
		//dp[i] �ʱ�ȭ
		//ū����� dp[i]�� ���Ѵ� 
		for (int j = 0; j < x; j++) {
			//���� ����� dp[j] �� ���� ó���� �����Ѵ�			
		}
	}

	return dp2[x];
}