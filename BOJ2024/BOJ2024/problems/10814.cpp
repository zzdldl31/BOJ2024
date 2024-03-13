#include "common.h"

#include <stdio.h>
#include <vector>
#include <algorithm>

int P10814() {
	//name: move to global variable
	char name[100000][120];
	//int age[100000];
	int a;
	int N;


	scanf("%d", &N);

	std::vector<std::pair<int, int> > users;
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &a, name[i]);
		users.push_back(std::make_pair(a, i));
	}
	std::sort(users.begin(), users.end());

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", users[i].first, name[users[i].second]);
	}
	
	return 0;
}