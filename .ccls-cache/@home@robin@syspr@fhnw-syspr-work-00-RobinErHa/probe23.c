#include <stdio.h>
int main(int argc, char *argv[])
{
	int a[2]; int *p = a + 1; *p = 2; int *q = p++; *q = 3;
	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
}
