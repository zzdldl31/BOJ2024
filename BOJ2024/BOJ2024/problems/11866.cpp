#include "common.h"

#include <stdio.h>

int P11866() {
	int N, K;

	scanf("%d %d", &N, &K);
	bool elim[1200] = { 0 };

	int cur = 0;
	printf("<");
	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(", ");
		for (int j = 0; j < K; j++) {
			do {
				cur++;
				if (cur > N)cur -= N;
			} while (elim[cur]);
		}
		elim[cur] = true;
		printf("%d", cur);
		

	}
	printf(">");
	return 0;
}