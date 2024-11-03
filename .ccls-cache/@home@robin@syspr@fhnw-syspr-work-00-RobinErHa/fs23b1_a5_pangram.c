#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{	
	int arr[('z'-'a') + 1]={0};
	int i = 1;
	while(i < argc){
		char* curr = argv[i];
		int length = strlen(curr);
		for (int j = 0; j < length;j++){
					if (curr[j] <= 'z' && curr[j] >= 'a'){
					arr[curr[j]-'a']++;	
					}
				}
		i++;
	}
	
	for (int k = 0; k < ('z' - 'a'+1); k++){
		if (arr[k] == 0 ){
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
	return 0;
}
