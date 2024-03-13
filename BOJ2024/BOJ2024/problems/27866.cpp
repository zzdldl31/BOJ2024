#include "common.h"

#include <stdio.h>

int P27866() {
	char str[1008];
	int i;

	scanf("%s", str);
	scanf("%d", &i);

	printf("%c", str[i - 1]);

	return 0;
}