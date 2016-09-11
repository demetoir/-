//��Ŭ���� ȣ����
//
//�ִ������� �ּҰ������ ������ ���ϴ� ���
//
//�ð� ���⵵ : O( log2(min(a, b)) )
//
//������
//a<=b �̾���� 
//�����ڷ�
//https://en.wikipedia.org/wiki/Euclidean_algorithm
//https://opentutorials.org/course/1685/9533
//
//����
//
//
//

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, b%a);
}

int main() {

	int a = 28;
	int b = 16;

	//�ִ� �����
	int gcd_val = gcd(a, b);

	//�ּ� �����
	//�����÷ο��� �������ִ�
	int lcm_val = (a*b) / gcd_val;
}