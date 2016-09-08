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