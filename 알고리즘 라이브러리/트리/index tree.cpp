//index tree (fenwick tree)
//�ð����⵵
//get O(log n)
//update O(log n)
//
//
//���� �ڷ�
//https://en.wikipedia.org/wiki/Fenwick_tree
//http://blog.secmem.org/486
//https://www.acmicpc.net/blog/view/21
//
//����
//2042 ���� �ձ��ϱ� https://www.acmicpc.net/problem/2042
//2934 LRH �Ĺ� https://www.acmicpc.net/problem/2934
//

#include <vector>
#include <math.h>
using namespace std;
#define MAX_N 100001 //10^6

int n;
vector <int>tree(n);
void update(int i, int diff) {
	while (i < n) {
		tree[i] += diff;
		i += (i & -i);
	}
}
int getsum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}


//2���� index tree 

