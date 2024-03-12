#include "common.h"

#include <stdio.h>


int P11723() {
	bool elements[40] = { 0 };

	int N;
	scanf("%d", &N);

	while (N-- > 0) {
		char str[20];
		int x;
		scanf("%s %d", &str, &x);

		if (str[0] == 'a' && str[1] == 'd' && str[2] == 'd')
			elements[x] = true;
		if (str[0] == 'r' && str[1] == 'e' && str[2] == 'm')
			elements[x] = false;
		if (str[0] == 't' && str[1] == 'o' && str[2] == 'g')
			elements[x] = !elements[x];
		if (str[0] == 'a' && str[1] == 'l' && str[2] == 'l') {
			for (int i = 1; i <= 20; i++)
				elements[i] = true;
		}
		if (str[0] == 'e' && str[1] == 'm' && str[2] == 'p') {
			for (int i = 1; i <= 20; i++)
				elements[i] = false;
		}

		if (str[0] == 'c' && str[1] == 'h' && str[2] == 'e')
			printf("%d\n", elements[x]);
	}



	return 0;
}