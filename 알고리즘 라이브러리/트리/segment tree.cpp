//segment tree (���׸�Ʈ Ʈ��)
//
//�ð����⵵
//update O(log(n))
//get O(log(n))
//
//�����ڷ�
//https://en.wikipedia.org/wiki/Segment_tree
//https://www.acmicpc.net/blog/view/9
//http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220791986409
//
//����
//2042 ���� �� ���ϱ� https://www.acmicpc.net/problem/2042
//10868 �ּҰ� https://www.acmicpc.net/problem/10868
//2357 �ּҰ��� �ִ밪 https://www.acmicpc.net/problem/2357
//https://www.acmicpc.net/problem/1275
//1377 ���׸�Ʈ Ʈ��
//6549 ������׷����� ���� ū ���簢��(https://www.acmicpc.net/problem/6549)
//12015 ���� �� �����ϴ� �κ� ���� 2 (https ://www.acmicpc.net/problem/12015)
//12738 ���� �� �����ϴ� �κ� ���� 3 (https ://www.acmicpc.net/problem/12738)
//2336 ������ �л�(https ://www.acmicpc.net/problem/2336)
//3006 �ͺ���Ʈ(https ://www.acmicpc.net/problem/3006)
//3653 ��ȭ ����(https ://www.acmicpc.net/problem/3653)
//7578 ����(https ://www.acmicpc.net/problem/7578)
//1280 ���� �ɱ�(https ://www.acmicpc.net/problem/1280)
//12016 ���� �κ� �����ٷ�(https ://www.acmicpc.net/problem/12016)
//5012 �Ҹ� ����(https ://www.acmicpc.net/problem/5012)
//5676 ���� �ڵ�(https ://www.acmicpc.net/problem/5676)
//2243 ��������(https ://www.acmicpc.net/problem/2243)
//1849 ����(https ://www.acmicpc.net/problem/1849)
//1168 �����۽� ����(https ://www.acmicpc.net/problem/1168)
//


#include <vector>
#include <math.h>
using namespace std;
#define MAX_N 100000 
vector<int> tree;
int main() {
	int n = MAX_N;
	int h = ceil(log2(n));
	int treesize = 1 << (h + 1);
	tree = vector<int>(treesize);
}
void update(int node, int left,int right,int index,int diff) {
	if (right < index || index < left) return;

	tree[node] += diff;
	if (left != right) {
		int mid = (left + right) / 2;
		update(node * 2, left, mid, index, diff);
		update(node * 2 + 1, mid + 1, right, index, diff);
	}
}

int get(int node, int left, int right, int a, int b) {
	if (a <= left && right <= b)return tree[node];
	if (b < left || right < a ) return 0;

	int ret = 0;
	int mid = (left + right) / 2;
	ret = get(node * 2, left, mid, a, b) + get(node * 2 + 1, mid + 1, right, a, b);
	return ret;
}