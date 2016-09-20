//kmp (Knuth-Morris-Pratt)
//
//���ڿ� ��Ī �˰���
//�� ������ ��Ÿ���� ��� ��ġ�� ã�´�
//
//�ð����⵵ O(N + H)
//N -> ���ϱ���, H-> ¤���� ���ڿ� ����
//
//���� �ڷ�
//https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
//http://codedoc.tistory.com/416
//http://carstart.tistory.com/143
//
//����
//1786 ã�� https://www.acmicpc.net/problem/1786
//1701 Cubeditor https://www.acmicpc.net/problem/1701
//1305 ���� https://www.acmicpc.net/problem/1305
//4354 ���ڿ� ���� https://www.acmicpc.net/problem/4354
//
//������
//
#include <vector>
using namespace std;
#define MAX_N 100001
#define MAX_H 100001
int pie[MAX_N];//���� �Լ�
int str[MAX_H];//ã�� ¤����
int patern[MAX_N];// ã�� ����
int h;//ã�� ¤���� ����
int n;//ã�� ���� ���� 

#define MAX_N 1000001
#define MAX_H 1000001
int pie[MAX_N];//���� �Լ�
char str[MAX_H];//ã�� ¤����
char patern[MAX_N];// ã�� ����
int h;//ã�� ¤���� ����
int n;//ã�� ���� ���� 
vector<int>ans;
void make_Pie() {
	//start =1 �� ������  
	int start = 1, matched = 0;
	while (start + matched < n) {
		if (patern[start + matched] == patern[matched]) {
			matched += 1;
			pie[start + matched - 1] = matched;
		}
		else {
			if (matched == 0)start += 1;
			else {
				start += matched - pie[matched - 1];
				matched = pie[matched - 1];
			}
		}
	}
}

void kmp() {
	make_Pie();
	int matched_count = 0;
	int start = 0, matched = 0;
	while (start <= h - n) {
		//��Ī �Ǿ���
		if (str[start + matched] == patern[matched]
			&& matched < n) {
			matched += 1;
			if (matched == n)
				ans.push_back(start);
		}
		//�� ��...
		else {
			if (matched == 0) start++;
			else {
				start += matched - pie[matched - 1];
				matched = pie[matched - 1];
			}
		}
	}

	return;
}
