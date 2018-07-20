#include<stdio.h>
#include<string.h>
int main()
{
    char str[55];
    int tc,i,check,t,len;

    scanf("%d", &tc);
    for(t = 1; t<=tc; t++) {
        scanf("%s", str);
        len = strlen(str);
        check = 0;
        for(i = 0; i<len; i++) {
            if(str[i] == '-') {
                if(str[i+1] !='B' && str[i+2] != 'B' && str[i-1] != 'S' && str[i+1] != 'S') {
                    check++;
                }
            }
        }

        printf("Case %d: %d\n",t,check);
    }
    return 0;
}

