#include "common.h"

#include <stdio.h>
#include <algorithm>
#include <vector>

bool dfs(int x, int fixed, int N, int* evens, int* odds, bool* isPrime, int* matches, bool* traveled) {
	for (int i = 1; i <= N / 2; i++) {
		if (i == fixed)
			continue;
		if (!isPrime[evens[x] + odds[i]])
			continue;
		if (traveled[i]) continue;
		traveled[i] = true;
		if (matches[i] != 1 && (matches[i] == 0 || dfs(matches[i], fixed, N, evens, odds, isPrime, matches, traveled))) {
			matches[i] = x;
			return true;
		}
	}
	return false;
}

int P1017() {

	bool isPrime[2048];
	std::fill(isPrime, isPrime + 2048, true);
	{
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i <= 2000; i++) {
			if (!isPrime[i])
				continue;
			for (int j = i * i; j <= 2000; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int N, k;
	int evens[32];
	int odds[32];
	int evenCnt = 0, oddCnt = 0;
	int first = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &k);
		if (k % 2 == 0) {
			evenCnt++;
			evens[evenCnt] = k;
		}
		else {
			oddCnt++;
			odds[oddCnt] = k;
		}
		if (i == 0)
			first = k;
	}
	if (oddCnt != evenCnt) {
		printf("-1");
		return 0;
	}
	if (first % 2 == 1) {
		for (int i = 1; i <= N / 2; i++) {
			int temp = evens[i];
			evens[i] = odds[i];
			odds[i] = temp;
		}
	}

	std::vector<int> candidates;

	for (int fixNum = 1; fixNum <= N / 2; fixNum++) {
		if (!isPrime[evens[1] + odds[fixNum]])
			continue;

		int matches[32] = { 0 };
		bool traveled[32];
		int matchCnt = 0;

		matches[fixNum] = 1;
		matchCnt = 1;

		for (int i = 2; i <= N / 2; i++) {
			std::fill(traveled, traveled + 32, false);
			traveled[fixNum] = true;
			if (dfs(i, 0, N, evens, odds, isPrime, matches, traveled))
				matchCnt++;
		}
		if (matchCnt == N / 2) {
			candidates.push_back(odds[fixNum]);
		}
	}
	if (candidates.size() == 0) {
		printf("-1");
		return 0;
	}
	else {
		std::sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); i++) {
			printf("%d ", candidates[i]);
		}
	}

	return 0;
}