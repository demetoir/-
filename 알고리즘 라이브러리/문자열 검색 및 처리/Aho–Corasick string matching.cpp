//aho-corasick
//
//kmp�� �����Ұ�
//
//�ð����⵵ O(N+M + P)
//N : ã�������ϴ� ���ڿ� ����
//m : ã�������ϴ� ¤���� ���ڿ� ����
//P : ������ ���� Ƚ��
//
//��ȣ �ڶ���� �����Լ�
//
//���� �ڷ�
//http://www.slideshare.net/ssuser81b91b/ahocorasick-algorithm
//http://channelofchaos.tistory.com/24
//http://hwamir.tistory.com/5
//http://blog.ivank.net/aho-corasick-algorithm-in-as3.html
//�˰��� �����ذ� 2��
//
//����
//���� �׷� ������ ����
//

#include <string>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define MAX_N 100001

#define pii pair<int,int>

const int alphabet = 26;
int tonum(char c) { return c - 'a'; }
struct Node {
	Node* children[alphabet];

	//���� ��ġ���� ������ ���ڿ� ��ȣ
	int terminal;
	//���п���
	Node* fail;
	//�̳�忡 �湮������ �����ϴ� �ٴõ��� ��ȣ
	vector<int>output;

	Node() :terminal(-1) {
		memset(children, 0, sizeof(children));
	}
	~Node() {
		for (int i = 0; i < alphabet; i++) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key, int id) {
		if (*key == 0)terminal = id;
		else {
			int next = tonum(*key);
			if (children[next] == NULL)
				children[next] = new Node();
			children[next]->insert(key + 1, id);
		}
	}

	//TrieNode* find(const char* key) {
	//	if (*key == 0) return this;
	//	int next = tonum(*key);
	//	if (children[next] == NULL)return NULL;
	//	return children[next]->find(key + 1);
	//}
};

void computeFailfunc(Node* root) {
	queue<Node*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();

		for (int edge = 0; edge < alphabet; edge++) {
			Node* child = cur->children[edge];
			if (!child)continue;

			if (cur == root)
				child->fail = root;
			else {
				Node* failnode = cur->fail;
				while (failnode != root && failnode->children[edge] == NULL)
					failnode = failnode->fail;
				if (failnode->children[edge])
					failnode = failnode->children[edge];
				child->fail = failnode;
			}

			child->output = child->fail->output;
			if (child->terminal >= 1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

int ahoCorasick(const string& s, Node* root) {
	/*vector<pii> ret;*/
	int count = 0;
	Node* cur = root;
	for (int i = 0; i < s.size(); i++) {
		int chr = tonum(s[i]);
		while (cur != root && cur->children[chr] == NULL) {
			cur = cur->fail;

		}
		if (cur->children[chr])
			cur = cur->children[chr];

		if (cur->output.size())
			return 1;

	}
	return 0;
}

