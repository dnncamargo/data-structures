#include <stdio.h>

/* struct estático para 1 aluno */
typedef struct student {
    char name[100];
    int rtest;
    float t1, t2, t3, average;
} Student;

int main(){
    Student s;
    printf ("Nome");
    scanf ("%[^\n]", s.name);
    printf ("A1");
    scanf ("%f", s.t1);
    printf ("A2");
    scanf ("%f", s.t2);
    printf ("A3");
    scanf ("%f", s.t3);

    float *p1, *p2;

    if(s.t1 < s.t2){
        if(s.t1 < s.t3){
            *p1 = &s.t3;
        }
    } else {
        if(s.t2 < s.t3){
            *p2 = &s.t3;
        }
    }
}
