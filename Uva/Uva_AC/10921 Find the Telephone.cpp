#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 35
int num(char ch){
	if(ch == 'A' || ch == 'B' || ch == 'C')
	    return 2;
	else if(ch == 'D' || ch == 'E' || ch == 'F')
	    return 3;
	else if(ch == 'G' || ch == 'H' || ch == 'I')
	    return 4;
	else if(ch == 'J' || ch == 'K' || ch == 'L')
	    return 5;
	else if(ch == 'M' || ch == 'N' || ch == 'O')
	    return 6;
	else if(ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S')
	    return 7;
	else if(ch == 'T' || ch == 'U' || ch == 'V')
	    return 8;
	else if(ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z')
	    return 9;   
}
int main()
{
	char str[MAX];
	while(scanf("%s", str) == 1){
		int len = strlen(str);
		for(int i = 0; i<len ; i++){
			if(isalpha(str[i])){
				printf("%d",num(str[i]));
			}
			else{
				printf("%c",str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
