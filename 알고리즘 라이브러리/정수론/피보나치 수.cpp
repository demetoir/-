//피보나치 수 
//
//참고 자료
//https://www.nayuki.io/page/fast-fibonacci-algorithms
//http://j1w2k3.tistory.com/357
//
#include<map>
#include <unordered_map>
using namespace std;

//성질
//f(1) ~ f(n) 합 = f(n+2) -1

//f(2) ~ f(n) 짝수 합 = f(2*n+1) - 1

//f(1) ~ f(n) 홀수 합 = f(2*n)

//f(1) ~ f(n) 제곱의 합 = f(n)*f(n+1)

//재귀버전
int fib1(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib1(n - 1) + fib1(n - 2);
}

//루프 dp 버전
#define MAX_N 100000
int fib2_val[MAX_N];
void fib2() {
	fib2_val[0] = 0;
	fib2_val[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fib2_val[i] = fib2_val[i - 1] + fib2_val[i - 2];
	}
}

//doubleding with cache 버전
typedef long long LL;
unordered_map<LL, LL> fib3_map;
#define pll pair<LL,LL>
void init() {
	fib3_map.insert(pll(0, 0));
	fib3_map.insert(pll(1, 1));
}
LL fib3(LL n) {
	
	if (fib3_map.find(n) != fib3_map.end()) {
		return fib3_map[n];
	}
	LL a = fib3(n / 2);
	LL b = fib3(n / 2 + 1);
	LL val;
	if (n % 2 == 0) {
		val = a*(2 * b - a);
	}
	else {
		val = a*a + b*b;
	}

	fib3_map.insert(pll(n, val));
	return fib3_map[n];
}