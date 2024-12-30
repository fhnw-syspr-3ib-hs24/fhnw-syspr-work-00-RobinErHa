#include <stdio.h>
#include <unistd.h>
#include <assert.h>

int main(void)
{
	assert(isatty(STDIN_FILENO));
	int len =32;
	char buf[len];
	int r = read(STDIN_FILENO, buf, len);
	while (1) {
		write(STDOUT_FILENO, buf, r);
		r = read(STDIN_FILENO, buf, len);
		}
}
