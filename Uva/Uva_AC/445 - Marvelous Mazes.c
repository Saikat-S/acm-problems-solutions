#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    int i,j,len,sum;

    while(gets(str)) {
        len = strlen(str);
        sum = 0;
        for(i = 0; i<len; i++) {
			if(str[i]-'0' >= 0 && str[i]-'0' <=9){
                sum = sum + (str[i] -'0');
            }
            else if(str[i] >= 'A' && str[i] <='Z') {
				for(j = 0;j<sum; j++){
					printf("%c",str[i]);
				}
				sum = 0;             
            }
            else if(str[i] == 'b'){
				for(j = 0;j<sum; j++){
					printf(" ");
				}
				sum = 0; 
			}
            else if(str[i] == '*') {
                for(j = 0;j<sum; j++){
					printf("*");
				}
				sum = 0; 
            }
            else if(str[i] == '!') {
                printf("\n");
            }
            else if(str[i] == ' '){
				printf("\n");
			}
        }
        printf("\n");
    }
    return 0;
}

