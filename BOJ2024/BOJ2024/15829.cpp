#include "common.h"

#include <stdio.h>

int P15829() {
	long long R = 1, H = 0;
	const long long r = 31, M = 1234567891;
	char str[50];
	int L;
	scanf("%d", &L);
	scanf("%s", str);

	for (int i = 0; i < L; i++) {
		H += (R * (str[i] - 'a' + 1)) % M;
		H %= M;
		R = (R * r) % M;
	}
	printf("%lld", H);

	return 0;
}