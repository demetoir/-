//Graham scan (�׶��� ��ĵ)
//
//�ð� ���⵵ O(nlog(n))
//
//��������
//vector2 class �� �˾ƾ��Ѵ�
//ccw �� �˰��־����
//���� ������ �ϴµ� �־ ���� ���ο찡 �־������
//
//�����ڷ�
//http://hns17.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-ConvexHull-Grahams-Scan
//http://www.slideshare.net/ssuser88a8b3/2-57761427
//http://blog.myungwoo.kr/104
//
//���� �Ϸ�
//����
//1708 ���� ����
//
//10254 ��ӵ��� https://www.acmicpc.net/problem/10254

// �̼ҽ������� ������ ����µ� �������� ������ ������ �������� �ʴ´�
#include <stack>
#include <algorithm>
using namespace std;
#define LL long long
#define INF 2e9
#define MAX_N 100001
const double PI = 2.0 * acos(0.0);

struct vector2 {
	double x, y;
	vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}

	bool operator == (const vector2 & rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator < (const vector2 & rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator + (const vector2 &rhs)const {
		return vector2(x + rhs.x, y + rhs.y);
	}

	vector2 operator - (const vector2 &rhs)const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	vector2 operator * (double rhs) const {
		return vector2(x*rhs, y*rhs);
	}

	double norm()const { return hypot(x, y); }

	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}

	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

	double dot(const vector2& rhs)const {
		return x*rhs.y + rhs.x*y;
	}

	double cross(const vector2& rhs) const {
		return x*rhs.y - rhs.x*y;
	}
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};


LL ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

vector2 minp(INF, INF);
bool cmp(const vector2 a, const vector2 b) {
	vector2 A = a - minp;
	vector2 B = b - minp;
	if (ccw(A, B) > 0) return true;
	return false;
}

vector2 points[MAX_N];
int n;
int scan() {
	//���� ���� ���� ã�� �Ǿ����� ����
	int minindex;
	for (int i = 0; i < n; i++) {
		if (minp.x > points[i].x ||
			minp.x == points[i].x && minp.y > points[i].y) {
			minp.x = points[i].x;
			minp.y = points[i].y;
			minindex = i;
		}
	}
	points[minindex] = points[0];
	points[0] = minp;

	// ������ ������ ���������κ����� ���������� ��Ʈ�Ѵ�
	sort(points + 1, points + n, cmp);

	//�������κ��� �ݽð� ������ ������ ����
	stack <vector2> st;
	st.push(points[0]);
	st.push(points[1]);
	for (int i = 2; i < n; i++) {
		vector2 b = st.top(); st.pop();
		vector2 a = st.top();

		while (1) {
			LL val = ccw(points[i] - a, points[i] - b);
			if (val > 0) {
				st.push(b);
				st.push(points[i]);
				break;
			}
			else {
				if (st.size() == 1) {
					st.push(points[i]);
					break;
				}
				else {
					b = st.top(); st.pop();
					a = st.top();
				}
			}
		}
	}
	//st �� convex hull �� ������
	return st.size();
}

