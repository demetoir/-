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

//P1, P2, P3�� ������� ���� ������ �ݽð� ������ ��Ÿ���� 1, �ð� �����̸� -1, �������̸� 0
int x[3];
int y[3];
int ccw(int x[3],int y[3]) {
	int ret = 0;
	ret = x[0] * y[1] + x[1] * y[2] + x[2] * y[0] - (x[0] * y[2] + x[1] * y[0] + x[2] * y[1]);

	if (ret < 0) ret = -1;
	if (ret > 0) ret = 1;
	return ret;
}
