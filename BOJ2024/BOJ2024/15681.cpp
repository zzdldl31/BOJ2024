#include "common.h"

#include <stdio.h>
#include <vector>

std::vector<int> conn[100008];
int childs[100008] = { 0 };

int count_child(int U, int R, std::vector<int> conn[], int childs[]) {
	int cnt = 1;
	
	for (int i : conn[U]) {
		if (i == R) continue;
		childs[i]= count_child(i, U, conn, childs);
		cnt += childs[i];
	}
	return cnt;
}

int P15681() {
	int N, R, Q;
	scanf("%d %d %d", &N, &R, &Q);


	int U, V;

	for (int i = 1; i < N; i++) {
		scanf("%d %d", &U, &V);
		conn[U].push_back(V);
		conn[V].push_back(U);
	}

	childs[R] = count_child(R, -1, conn, childs);

	for (int i = 0; i < Q; i++) {
		scanf("%d", &U);
		printf("%d\n", childs[U]);
	}


	return 0;
}