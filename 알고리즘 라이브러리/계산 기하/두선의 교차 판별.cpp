//�μ��� �����Ǻ�
//������ ������ ���� �Ǻ�
//���а� ������ ���� �Ǻ� 
//������ ��ġ ���ϱ�
//
//
//���� �ڷ�
//
//http://bowbowbow.tistory.com/17
//http://3dmpengines.tistory.com/786
//
//����
//
//
//10255
//
//
#include <math.h>
#include <algorithm> 
using namespace std;

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


//a->b �ΰ��� ������ c->d �� ���� ������ ������ �Ǻ��ϰ� �����ϸ� x�� �������� ��ȯ�Ѵ�
bool lineIntersection(vector2 a, vector2 b,
	vector2 c, vector2 d, vector2 &x) {
	double det = (b - a).cross(d - c);
	if (fabs(det) < 1e-4)return false;
	//if (fabs(det) < EPSILON)return false;
	x = a+(b - a)*((c - a).cross(d - c) / det);
	return true;
}


double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}

bool parralledSegment(vector2 a, vector2 b,
	vector2 c, vector2 d, vector2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(d, c);

	if (ccw(a, b, c) != 0|| b < c || d < a) return false;

	if (a < c)p = c;
	else p = a;

	return true;
}

bool inbounding_ractangle(vector2 p, vector2 a, vector2 b) {
	if (b < a)swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

//a->b �ΰ��� ���а� c->d �� ���� ������ ������ �Ǻ��ϰ� �����ϸ� p�� �������� ��ȯ�Ѵ�
bool segmentIntersection(vector2 a, vector2 b,
	vector2 c, vector2 d, vector2 &p) {
	if (!lineIntersection(a, b, c, d, p))
		return parralledSegment(a, b, c, d, p);

	return inbounding_ractangle(p, a, b) &&
		inbounding_ractangle(p, c, d);
}

//a->b �ΰ��� ���а� c->d �� ���� ������ ������ �Ǻ����Ѵ�
bool segmentIntersection(vector2 a, vector2 b,
	vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a)*ccw(c, d, b);

	if (ab == 0 && cd == 0){
		if (b < a)swap(a, b);
		if (d < c) swap(c, d);
		return !(b< c || d < a);
	}
	return ab <= 0 && cd <= 0;
}


//������ ��ġ ������ �ʰ� ���� �ϴ����� �Ǵ��ϴ°� �����ѹ���..
//������
struct P {
	int x, y;
	int s() { return this->x + this->y; }// wtf???
} B[4];

//���� ����
struct L {
	L() {}
	L(const P &a, const P &b) : a(a), b(b) {}
	P a, b;
} A;

int ccw(const P &a, const P &b, const P &c) {
	int k = (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
	if (k > 0) return 1;
	if (k) return -1;
	return 0;
}

//0 :�������� ���� 
//1: �������� ����  
//-1: ���������� ����(��ģ��)
int insc(L p, L q) {
	//������ ���� �� �������� ������
	if (!ccw(p.a, p.b, q.a) && !ccw(p.a, p.b, q.b)) {
		if (p.a.s() > p.b.s()) swap(p.a, p.b);
		if (q.a.s() > q.b.s()) swap(q.a, q.b);
		int a = p.a.s(), b = p.b.s(), c = q.a.s(), d = q.b.s();
		//���� ������ ����
		if (b < c || d < a) return 0;

		//���а��� ���� �������� ������
		if (b == c || a == d) return 1;

		return -1;
	}

	//������ 
	if (ccw(p.a, p.b, q.a) == ccw(p.a, p.b, q.b)
		|| ccw(q.a, q.b, p.a) == ccw(q.a, q.b, p.b))
		return 0;
	return 1;
}



