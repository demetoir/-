//���� ���� �̺�Ž��
//
//�ð� ���⵵ O(log(LIMIT) * O(deterministic function) )
//
//���� �ڷ�
//
//����
//1654 ���� �ڸ���
//1150 ���
//2110 ������ ��ġ
//2485 ���μ�
//2805 �����ڸ���
//3079 �Ա��ɻ�
//1939 �߷�����
//1981 �迭���� �̵�

//�����ذ� �ִ��ϋ� �ڵ� Ʋ

#define MINLIMIT 0		// �̺�Ž���� �� ����
#define MAXLIMIT 2e9 // 

bool ispossible(int x) {
	//deterministic function
	//�׸��� �Ǵ� dp �� �ذ��Ҽ��ִ� ����
	//x ���Ϸ� �����Ѱ�
	//
	//return bool
}
int bi_search() {	
	int lo = MINLIMIT, hi = MAXLIMIT;
	int ans;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ispossible(mid)) {
			lo = mid + 1;
			ans = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return ans;
}













