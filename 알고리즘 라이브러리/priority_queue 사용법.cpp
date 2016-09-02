//priority_queue 
//���̺귯�� �̸� queue
//
//default �� ���������̴�
//
//�ð����⵵
//push O(lg(n))
//pop O(lg(n))
//top O(lg(1))

#include <queue>
#include <functional>
using namespace std;
#define pii pair<int,int>

int main() {
	//����
	priority_queue<int>pq;
	priority_queue<pii>pq_pair;

	//�ʱ�ȭ
	pq = priority_queue<int>();

	//push
	pq.push(4);
	pq.push(3);
	pq.push(2);
	pq.push(1);
	//pq = {1,2,3,4}

	//pop
	int val = pq.top();
	pq.pop();
	//val -> 1
	// pq = {2,3,4}


	//������������ priority_queue ����ϱ�

	//greater�� ����ؼ� �������� �ϱ�
	priority_queue<int,vector<int>, greater<int> > pq;
	//priority_queue<T,vector<T>, greater<T> > pq;


	//������ �״�� �ϰ� ���Ұ��� ��ȣ�� �ٲپ� �����
	priority_queue<int>pq;

	//push
	int val = 5;
	pq.push(-val);

	//pop
	int temp = -pq.top(); 
	pq.pop();
	
	//pair �� �̿��� priority_queue ����ϴ� ���
	priority_queue<pii> pq_pair;

	//push
	pq_pair.push(pii(4, 1));
	pq_pair.push(pii(3, 1));
	pq_pair.push(pii(1, 3));
	pq_pair.push(pii(1, 1));
	pq_pair.push(pii(2, 2));
	pq_pair.push(pii(2, 3));
	//pq ={(1,1),(1,3),(2,2),(2,3),(3,1),(4,1)}	
	
	//pop
	pii temp = pq_pair.top(); pq_pair.pop();
	//temp -> (1,1)

}