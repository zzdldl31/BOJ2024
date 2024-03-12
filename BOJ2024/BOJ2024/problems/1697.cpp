#include "common.h"

#include <stdio.h>
#include <queue>
//#include <utility>


int P1697() {
	int N, K;
	scanf("%d %d", &N, &K);

	if (N >= K) {
		printf("%d", N - K);
		return 0;
	}

	std::queue<std::pair<int, int> > Q;
	bool visited[200008] = { 0 };
	int result = 0;


	Q.push(std::make_pair(K, 0));
	while (Q.size() > 0) {
		std::pair<int, int> p = Q.front();
		Q.pop();

		if (p.first == N) {
			result = p.second;
			break;
		}
		if (p.first >= 200000 || p.first < 0)
			continue;

		if (visited[p.first])
			continue;

		visited[p.first] = true;
		if (p.first % 2 == 0)
			Q.push(std::make_pair(p.first / 2, p.second + 1));
		Q.push(std::make_pair(p.first - 1, p.second + 1));
		Q.push(std::make_pair(p.first + 1, p.second + 1));
	}

	printf("%d", result);

	return 0;
}