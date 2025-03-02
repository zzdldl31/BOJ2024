#include "common.h"

#include <stdio.h>

int P28702() {
	char str1[12];
	char str2[12];
	char str3[12];
	char* isN = str1;
	int n = 0;
	int piv = 0;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);

	if (str1[0] >= '0' && str1[0] <= '9') {
		piv = 3;
		isN = str1;
	}
	else if (str2[0] >= '0' && str2[0] <= '9') {
		piv = 2;
		isN = str2;
	}
	else if (str3[0] >= '0' && str3[0] <= '9') {
		piv = 1;
		isN = str3;
	}

	for (int i = 0; i <= 8; i++) {
		if (isN[i] == 0) break;
		n = 10 * n + (isN[i] - '0');
	}

	n += piv;
	if (n % 3 == 0 && n % 5 == 0) {
		printf("FizzBuzz");
	}
	else if (n % 3 == 0 && n % 5 != 0) {
		printf("Fizz");
	}
	else if (n % 3 != 0 && n % 5 == 0) {
		printf("Buzz");
	}
	else {
		printf("%d", n);
	}


	return 0;
}