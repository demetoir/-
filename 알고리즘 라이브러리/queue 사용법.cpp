//queue ����
//���̺귯�� �̸� queue

#include <queue>
using namespace std;

int main() {
	//����
	queue<int> q;

	//�ʱ�ȭ 
	q = queue<int>();

	//push 
	q.push(1);
	q.push(2);
	q.push(3);

	//pop()
	int val =q.front(); q.pop();

	// ����ִ��� �˻�
	q.empty();
	//��������� true ��ȯ


	// ���� ����Ҷ�
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
	}

}
