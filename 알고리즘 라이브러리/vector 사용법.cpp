//vector ����
//���̺귯�� �̸� vector
// �ð� ���⵵
//push_back O(lg(1))
//size O(lg(1))v
//
//
//
#include <vector>
using namespace std;

int main() {
	//����
	vector<int> vi;
	vector<long long> vll;
	
	//�ʱ�ȭ ���
	vi.clear();
	//��� vi = {}

	//Ư���� ���� ���̸� ������ �ʱ�ȭ 
	int n = 5;
	int val = -1;
	vi.assign(n,val);
	//��� vi = {-1,-1,-1,-1,-1}

	//���� 
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	// �����
	// vi= {1,2,3}

	//���� Ȯ��
	vi.size();
	//vi.size() -> 3

	//����
	vector<int> vi2;
	vi2 = vi;
}
