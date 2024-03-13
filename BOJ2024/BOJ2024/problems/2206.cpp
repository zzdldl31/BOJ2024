#include "common.h"

#include <stdio.h>
#include <queue>



int P2206() {
	//move memory to global
	int N, M;
	bool board[1000][1000];
	bool traveled[2][1000][1000];


	scanf("%d %d", &N, &M);

	char str[1024];
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (int j = 0; j < M; j++) {
			board[i][j] = (str[j] == '1');
		}
	}
	std::queue<std::pair<std::pair<int, int>, std::pair<bool,int> > > Q;
	Q.push(std::make_pair(std::make_pair(0, 0), std::make_pair(false, 1)));

	while (Q.size() > 0) {
		std::pair<std::pair<int, int>, std::pair<bool, int>> element = Q.front();
		Q.pop();

		if (element.first.first < 0 || element.first.first >= N || element.first.second < 0 || element.first.second >= M) {
			continue;
		}
		if (element.first.first == N - 1 && element.first.second == M - 1) {
			printf("%d", element.second.second);
			return 0;
		}
		if (traveled[element.second.first][element.first.first][element.first.second])
			continue;

		traveled[element.second.first][element.first.first][element.first.second] = true;

		if (element.second.first) {
			if (element.first.first != N - 1 && !board[element.first.first + 1][element.first.second])
				Q.push(std::make_pair(std::make_pair(element.first.first + 1, element.first.second), std::make_pair(true, element.second.second + 1)));
			if (element.first.first != 0 && !board[element.first.first - 1][element.first.second])
				Q.push(std::make_pair(std::make_pair(element.first.first - 1, element.first.second), std::make_pair(true, element.second.second + 1)));
			if (element.first.second != M - 1 && !board[element.first.first][element.first.second + 1])
				Q.push(std::make_pair(std::make_pair(element.first.first, element.first.second + 1), std::make_pair(true, element.second.second + 1)));
			if (element.first.second != 0 && !board[element.first.first][element.first.second - 1])
				Q.push(std::make_pair(std::make_pair(element.first.first, element.first.second - 1), std::make_pair(true, element.second.second + 1)));
		}
		else {
			if (element.first.first != N - 1)
				Q.push(std::make_pair(std::make_pair(element.first.first + 1, element.first.second), std::make_pair(board[element.first.first + 1][element.first.second], element.second.second + 1)));
			if (element.first.first != 0)
				Q.push(std::make_pair(std::make_pair(element.first.first - 1, element.first.second), std::make_pair(board[element.first.first - 1][element.first.second], element.second.second + 1)));
			if (element.first.second != M - 1)
				Q.push(std::make_pair(std::make_pair(element.first.first, element.first.second + 1), std::make_pair(board[element.first.first][element.first.second + 1], element.second.second + 1)));
			if (element.first.second != 0)
				Q.push(std::make_pair(std::make_pair(element.first.first, element.first.second - 1), std::make_pair(board[element.first.first][element.first.second - 1], element.second.second + 1)));
		}

	}
	printf("-1");

	return 0;
}