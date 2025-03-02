#include "common.h"

#include <stdio.h>

int P1676() {
	int N;
	scanf("%d", &N);
	int z = 0;
	while (N > 0) {
		z += N / 5;
		N /= 5;
	}
	printf("%d", z);

	return 0;
}