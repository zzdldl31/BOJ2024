#include "common.h"

#include <stdio.h>

int P10250() {

	int W, H, N, T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d %d %d", &H, &W, &N);

		printf("%d\n", ((N - 1) / H + 1) + ((N - 1) % H + 1) * 100);

	}



	return 0;
}