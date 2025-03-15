#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    int arr[N][31];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 31; j++){
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == -1){
                break;
            }
        }
    }
    int mark = 0;
    for (int i = 0; i < 31; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < 31; k++){
                if (arr[j][k] == i){
                    mark = 1;
                    break;
                }
            }
            if (mark == 1){
                break;
            }
        }
        if (mark == 0){
            printf("no\n");
            return 0;
        }
        mark = 0;
    }
    printf("yes\n");
    return 0;
}
