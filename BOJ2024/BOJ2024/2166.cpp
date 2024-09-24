#include "common.h"

#include <stdio.h>

int P2166() {
	int N;
	
	long long x0, y0, x1, y1, x2, y2;
	long long Area2 = 0;

	scanf("%d", &N);
	scanf("%lld %lld", &x0, &y0);
	scanf("%lld %lld", &x1, &y1);
	
	Area2 += x0 * y1 - x1 * y0;
	while (N-- > 2) {
		scanf("%lld %lld", &x2, &y2);
		Area2 += x1 * y2 - x2 * y1;
		x1 = x2; y1 = y2;
	}
	Area2 += x1 * y0 - x0 * y1;

	if (Area2 < 0)Area2 = -Area2;

	printf("%lld", Area2 / 2);
	if (Area2 % 2 == 0)
		printf(".0");
	else
		printf(".5");
	return 0;
}