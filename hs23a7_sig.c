//#include <stdio.h>
//#include <signal.h>
//#include <unistd.h>
//#include <string.h>
//
//void handle (int signal) {
//}
//
//int main(void)
//{
//	for (int i = 1;i <= 32;i++) {
//		//signal(i, handle);
//		strsignal(signal(i, handle));
//	}
//	pause();
//}

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int received_signal = 0;

void handler(int sig) {
    received_signal = sig;
}

int main() {
    for (int i = 1; i <= 32; i++) {
        signal(i, handler); //handler: eine funktion, i: Argument fuer die Funktion (also in diesem fall sig) Funktion wird in diesem Fall aufgerufen, wenn signal eintrifft.
    }
    pause();
    printf("%d, %s\n", received_signal, strsignal(received_signal));
    return 0;
}

