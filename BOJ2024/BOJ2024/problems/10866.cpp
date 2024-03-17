#include "common.h"

#include <stdio.h>
#include <deque>


int P10866() {
	std::deque<int> DQ;

	int N;
	scanf("%d", &N);

	while (N-- > 0) {
		char str[20];
		int x;
		scanf("%s", &str);

		if (str[0] == 'p' && str[1] == 'u' && str[5] == 'f') {
			scanf("%d", &x);
			DQ.push_front(x);
		}
		if (str[0] == 'p' && str[1] == 'u' && str[5] == 'b') {
			scanf("%d", &x);
			DQ.push_back(x);
		}
		if (str[0] == 'p' && str[1] == 'o' && str[4] == 'f') {
			if (DQ.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", DQ.front());
				DQ.pop_front();
			}
		}
		if (str[0] == 'p' && str[1] == 'o' && str[4] == 'b') {
			if (DQ.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", DQ.back());
				DQ.pop_back();
			}
		}
		if (str[0] == 's' && str[1] == 'i' && str[2] == 'z') {
			printf("%d\n", DQ.size());
		}
		if (str[0] == 'e' && str[1] == 'm' && str[2] == 'p') {
			printf("%d\n", DQ.empty());
		}
		if (str[0] == 'f' && str[1] == 'r' && str[2] == 'o') {
			if (DQ.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", DQ.front());
			}
		}
		if (str[0] == 'b' && str[1] == 'a' && str[2] == 'c') {
			if (DQ.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", DQ.back());
			}
		}

	}

	return 0;
}