#include "common.h"

#include <stdio.h>

int P31403() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	printf("%d\n", A + B - C);

	int scale = 1;
	while (scale <= B) {
		scale *= 10;
	}
	printf("%d", A * scale + B - C);


	return 0;
}