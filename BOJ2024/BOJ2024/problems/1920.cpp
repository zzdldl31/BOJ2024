#include "common.h"

#include <stdio.h>
#include <set>

int P1920() {
	std::set<int> S;
	int N, M, i;
	scanf("%d", &N);
	while (N-- > 0) {
		scanf("%d", &i);
		S.insert(i);
	}
	scanf("%d", &M);
	while (M-- > 0) {
		scanf("%d", &i);
		std::set<int>::const_iterator NotExist = S.end();
		printf("%d ", S.find(i) != NotExist);
	}

	return 0;
}