#include "common.h"

#include <stdio.h>

int cards[20000001];

int P10816() {
	int N, M;
	int card;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &card);
		cards[card + 10000000]++;
	}

	scanf("%d", &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &card);
		printf("%d ", cards[card + 10000000]);
	}

	return 0;
}