#include "common.h"

#include <stdio.h>

int N, M;

int graph[120][120];

int P1389() {
	scanf("%d %d", &N, &M);
	int q,w;
	for (int q = 1; q <= N; q++) {
		for (int w = 1; w <= N; w++) {
			graph[q][w] = 120;
		}
		graph[q][q] = 0;
	}

	while (M-- > 0) {
		scanf("%d %d", &q, &w);
		graph[q][w] = 1;
		graph[w][q] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (k == i)
				continue;
			for (int j = i + 1; j <= N; j++) {
				if (k == j)
					continue;
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[j][i] = graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	int minKB = 20000;
	int minKBi = -1;
	for (q = 1; q <= N; q++) {
		int KB = 0;
		for (w = 1; w <= N; w++) {
			KB += graph[q][w];
		}
		if (minKB > KB) {
			minKB = KB;
			minKBi = q;
		}
	}
	printf("%d", minKBi);

	return 0;
}