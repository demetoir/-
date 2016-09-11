//�̺�Ž��
//
//�ð� ���⵵ O(log(n))
//
//���� ����
//ã������ �ڷ�� ���� ���� �̾���Ѵ�
//
//���� �ڷ�
//
//����
//

using namespace std;
#define MAX_N 10000000
int A[MAX_N];
int bi_search(int x) {
	int low = 0;
	int high = MAX_N - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (A[mid] == x)
			return mid;
		else if (A[mid] < x) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}
	return -1;
}
