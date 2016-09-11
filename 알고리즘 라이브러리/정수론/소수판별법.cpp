//���� �ʿ�

//�Ҽ� �Ǻ���
//
//�� ���� ���� �Ҽ� �Ǻ���
//�ð� ���⵵ O(root(n))
//
//�����佺�׳׽��� ü
//�ð� ���⵵ 
//��ó�� O(n)
//�Ǻ� O(1)
//
//ü�� �̿��� ���μ� ����
//
//�����ڷ�
//
//
//
//���� 
//
#include <vector>
using namespace std;

//�� ���� ���� �Ҽ� �Ǻ���
bool is_prime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return true;
}

//�����佺�׳׽��� ü
#define MAX_N 100000
vector<bool> seive;// ü
vector<int> prime;// �Ҽ��� ����ִ� ����
void make_seive(int size) {
	seive = vector<bool>(size, true);
	seive[0] = seive[1] = false;
	for (int i = 2; i < size; i++) {
		if (seive[i] == false)continue;
		prime.push_back(i);
		for (int j = i + i; j < size; j += i)
			seive[j] = false;
	}
}

//ü�� �̿��� ���μ� ����
void make_seive_with_factorize(int size) {
	seive = vector<bool>(size, 1);
	seive[0] = 0;
	seive[1] = 1;
	for (int i = 2; i < size; i++) {
		if (seive[i] > 1)continue;
		prime.push_back(i);
		for (int j = i + i; j < size; j += i)
			seive[j] = i;
	}
}

void integer_factorization(int n, vector<int> &factor) {
	while (seive[n] != 1) {
		factor.push_back(seive[n]);
		n = n / seive[n];
	}
	factor.push_back(n);
}
//����ȭ �Ǿ��� ü ;������ ��
int dp[1234], p;
int main() {
	int n, a, b;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		dp[a]++;
	}
	for (int i = 2; i < 1000; i++) {
		b = 1;
		for (int j = 2; j <= sqrt(i); j++)
			if (i % j == 0) {
				b = 0; break;
			}
		if (b) p += dp[i];
	}
	printf("%d", p);
	return 0;
}