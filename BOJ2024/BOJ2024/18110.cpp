#include "common.h"

#include <stdio.h>
#include <algorithm>
#include <math.h>

int N;
int scores[300020];
int P18110() {

	scanf("%d", &N);

	if (N == 0) {
		printf("0");
		return 0;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &scores[i]);
	}

	std::sort(scores, scores + N);
	
	int skip = round(N * 15 / 100.0f);

	int added = 0;
	for (int i = skip; i < N - skip; i++) {
		added += scores[i];
	}
	float av = added / ((float)(N - 2 * skip));

	printf("%d", (int)round(av));

	return 0;
}