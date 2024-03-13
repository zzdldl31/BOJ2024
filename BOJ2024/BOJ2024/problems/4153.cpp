#include "common.h"

#include <stdio.h>

int P4153() {
	int q, w, e;
	while (true) {
		scanf("%d %d %d", &q, &w, &e);
		if (q == 0 && w == 0 && e == 0)
			break;
		if (q < w) {
			int temp = q;
			q = w;
			w = temp;
		}
		if (q < e) {
			int temp = q;
			q = e;
			e = temp;
		}
		printf("%s\n", q * q - w * w - e * e == 0 ? "right" : "wrong");


	}


	return 0;
}