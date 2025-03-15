#include <stdio.h>

int main() {
    typedef struct student {
        long long id;
        int score;
    } student;

    student students[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %d", &students[i].id, &students[i].score);
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].score == students[j].score)
            {
                if (students[i].id > students[j].id) {
                    student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (students[i].score >= 60) {
            printf("%lld %d\n", students[i].id, students[i].score);
        }
    }
    return 0;
}