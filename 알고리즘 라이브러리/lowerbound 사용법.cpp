//lowerbound ����
//�ð� ���⵵ O(log(n))
//
//��������
//ã���� �ϴ� �迭�� �̸� ������������ ���� �Ǿ���Ѵ�
//
//����
//
//


#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

int main() {
	//�Ϲ� �迭 ����
	int A[10] = { 2,6,4,3,2, 1,5,3,2,5 };

	sort(A, A + 10);
	//A={1,2,2,2,3,3,4,5,5,6}

	//ã�����ϴ� ��
	int val = 3;

	//ã�����ϴ°��� ��Ÿ���� ù���� index ��ȯ
	int index = lower_bound(A, A + 10, val) - A;
	// index -> 4

	//ã�����ϴ°��� �ٷ� ����
	int *temp = lower_bound(A, A + 10, val);
	//*temp -> 3


	//vecter ����
	vector<int> vi;
	vi.push_back(2);
	vi.push_back(6);
	vi.push_back(4);
	vi.push_back(3);
	vi.push_back(2);
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(3);
	vi.push_back(2); 
	vi.push_back(5);
	//vi = { 2,6,4,3,2,1,5,3,2,5 };


	//ã�����ϴ� ��
	int val = 3;

	//ã�����ϴ°��� ��Ÿ���� ù���� index ��ȯ
	int index = lower_bound(vi.begin(), vi.end(), val) - vi.begin();
	// index -> 4

	//ã�����ϴ°��� �ٷ� ����
	vector<int>::iterator iter = lower_bound(vi.begin(), vi.end(), val) ;
	iter;
	//*temp -> 3




}