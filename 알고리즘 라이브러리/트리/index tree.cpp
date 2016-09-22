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
//http://183.106.15.130/30stair/bindexedtree/bindexedtree.php?pname=bindexedtree
//
//
//����
//2042 ���� �ձ��ϱ� https://www.acmicpc.net/problem/2042
//2934 LRH �Ĺ� https://www.acmicpc.net/problem/2934
//

#include <vector>
#include <math.h>
using namespace std;
#define MAX_N 100001 //10^6

//1���� �ε��� Ʈ��
int n;
vector <int>tree1(n);
void update(int i, int diff) {
	while (i < n) {
		tree1[i] += diff;
		i += (i & -i);
	}
}
int getsum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree1[i];
		i -= (i & -i);
	}
	return ret;
}


//2���� index tree 
#define max_x 1000
#define max_y 1000

int tree[max_x][max_y];

int read(int x, int y){
	int sum;
	int y1;

	sum = 0;
	while (x > 0) {
		y1 = y;
		while (y1 > 0) {
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}

	return sum;
}
void update(int x, int y, int val){
	int y1;

	while (x <= max_x) {
		y1 = y;
		while (y1 <= max_y) {
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

