#include "common.h"

#include <stdio.h>

int P2562() {
	
	int N;
	int max;
	int maxIdx;
	for (int i = 1; i < 10; i++) {
		scanf("%d", &N);
		if (i == 1) {
			max = N;
			maxIdx = 1;
		}
		if (max < N) {
			max = N;
			maxIdx = i;
		}
	}
	printf("%d\n%d", max, maxIdx);

	return 0;
}