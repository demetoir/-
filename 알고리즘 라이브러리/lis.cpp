//lis (longest increasing sequence, ���� ��������)
//
//�ð� ���⵵ 
//���� dp : O(n^2)
//lower_bound �̿� : O(nlog(n))
//
//�����ڷ�
//https://en.wikipedia.org/wiki/Longest_increasing_subsequence
//http://hoon222y.tistory.com/45
//https://www.youtube.com/watch?v=RzPElBr3L5A
//1 : 24 : 07 �κ� ���� ���� �ִ� ���� ��ø�̶�� �����ִµ� Ȯ���� �˷��� ���� �ѹ� ���°� ��õ
//
//����
//1956 ���ڳֱ� https://www.acmicpc.net/problem/1965
//2565 ������ https://www.acmicpc.net/problem/2565
//2352 �ݵ�ü ���� https://www.acmicpc.net/problem/2352
//1365 ���� ������ https://www.acmicpc.net/problem/1365
//2568 ������ - 2 https://www.acmicpc.net/problem/2568
//11055 ���� ū ���� �κ� ���� https://www.acmicpc.net/problem/11055
//2532 ���̻罽 https://www.acmicpc.net/problem/2532
//1937 ������� �Ǵ� https://www.acmicpc.net/problem/1937
//

#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int seq1[1000];
//���� dp
#define MAX_N 1001
int n;
int seq[MAX_N];
int dp[MAX_N];
int main() {
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (seq[j] < seq[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	return 0;
}

//lower_bound �̿��
int seq2[100000];
int dp2[100000];
int n = 100000;
int main() {

	dp[0] = seq[0];
	int size = 1;
	for (int i = 1; i < n; i++) {
		if (dp[size - 1] < seq[i]) {
			dp[size] = seq[i];
			size++;
		}
		else {
			dp[lower_bound(dp, dp + size, seq[i]) - dp] = seq[i];
		}
	}
	int ans = size;
	printf("%d\n", ans);
	return 0;
}