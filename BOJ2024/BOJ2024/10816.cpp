#include "common.h"

#include <stdio.h>

int cards[20000001];

int P10816() {
	int N, M;
	int card;

	scanf("%d", &N);
	while(N-->0) {
		scanf("%d", &card);
		cards[card + 10000000]++;
	}

	scanf("%d", &M);

	while(M-->0) {
		scanf("%d", &card);
		printf("%d ", cards[card + 10000000]);
	}

	return 0;
}