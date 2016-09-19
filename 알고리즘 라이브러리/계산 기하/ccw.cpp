//ccw
//������ �̾����� �ݽð�������� �ð�������� �������� �Ǻ�
//
//�ð� ���⵵ O(1)
//
//���� �ڷ�
//http://blog.naver.com/PostView.nhn?blogId=kaheeyah&logNo=220592648266&parentCategoryNo=60&categoryNo=174&viewDate=&isShowPopularPosts=false&from=postView
//http://cookyworld.tistory.com/49
//
//����
//11758 ccw https://www.acmicpc.net/problem/11758

#include <utility>
#define pii pair<int,int>
using namespace std;
//P1, P2, P3�� ������� ���� ������ �ݽð� ������ ��Ÿ���� 1, �ð� �����̸� -1, �������̸� 0

//�ܼ� ��ǥ �迭 �����϶�
int x[3];
int y[3];
int ccw(int x[3],int y[3]) {
	int ret = 0;
	ret = (x[0] * y[1] + x[1] * y[2] + x[2] * y[0]) - (x[0] * y[2] + x[1] * y[0] + x[2] * y[1]);

	if (ret < 0) ret = -1;
	if (ret > 0) ret = 1;
	return ret;
}

//pair �� ���� �� 3�� ���� ��������
int ccw(pii p1, pii p2, pii p3) {
	return (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);
}

//vector2 ����ü�� �� ����ϴ� ccw
struct vector2 {
	double x, y;
	vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}

	bool operator == (const vector2 & rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	vector2 operator + (const vector2 &rhs)const {
		return vector2(x + rhs.x, y + rhs.y);
	}

	vector2 operator - (const vector2 &rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}

	//���� ��, ����
	double cross(const vector2& rhs) const {
		return x*rhs.y - rhs.x*y;
	}

};

//�� ������ ���ͷ� ���ϴ� ccw
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

//�� p�� ���� ��a,b�� �մ� �������� ccw
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}