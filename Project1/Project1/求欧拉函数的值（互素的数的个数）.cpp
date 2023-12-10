#include <stdio.h>
#include <math.h>

int isPrime(int n, int r) {
	for (int i = 2; i <= r; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);

	int c = n;

	for (int i = 2; i <= n / 2; i++) {
		int r = sqrt(i);
		if (n % i == 0 && isPrime(i, r)) {
			c *= (1 - 1.0 / i);
		}
	}

	printf("%d\n", c);
	return 0;
}