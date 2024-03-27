#include "common.h"

#include <stdio.h>

long long upto(unsigned long long N) {
	if (N == 0) return 0;

	unsigned long long Ncopy = N;
	int L = 0;
	while (Ncopy != 0) {
		Ncopy >>= 1;
		L++;
	}

	long long oneCnt = 0;
	for (int i = 0; i < L; i++) {
		oneCnt += ((N + 1) >> (i + 1)) << i;
		if (((N + 1) >> i) & 1) {
			unsigned long long mask = (((unsigned long long)1) << i) - 1;
			oneCnt += (N + 1) & mask;
		}
	}

	return oneCnt;
}

int P9527() {
	unsigned long long A, B;
	scanf("%lld %lld", &A, &B);

	printf("%lld", upto(B) - upto(A - 1));

	return 0;
}