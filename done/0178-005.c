#include "stdio.h"

int factorial (int n) {
	int i, f = 1;
	for (i = 1; i <= n; ++ i)
		f *= i;
	return f;
}

int pow_2 (int n) {
	int i, p = 1;
	for (i = 0; i < n; ++ i)
		p *= 2;
	return p;
}

int predicate (int a, int i) {
	return pow_2(i) < a && a < factorial(i);
}

int solution () {
	int n, i, scheck, count = 0;
	int a [100000];
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n > 100000)
		return 1;
	if (n < 1)
		return 1;
	
	for (i = 0; i < n; ++ i) {
		scheck = scanf("%d", a + i);
		if (scheck != 1)
			return 1;
		if (*(a + i) < 1)
			return 1;
	}
	
	for (i = 0; i < n; ++ i) {
		if (predicate(*(a + i), i + 1))
			++ count;
	}
	
	printf("%d\n", count);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
