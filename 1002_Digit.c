#include <stdio.h>
#include <string.h>
int main(){
    char arr[1025];
    while (scanf("%s", arr)!= EOF){
        printf("%d\n", (int)strlen(arr));
    }
    return 0;
}