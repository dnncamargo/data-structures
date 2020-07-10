#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265



double x, y, val; // ponto x e y inicial. val é a constante PI para conversão entre graus e radianos
int angle; // angulo expresso em graus
double magnitude; // distancia do vetor
double* newPoint(double, double); // novo ponto



int main(int argc, char *argv[]) {

    /* getting arguments */
    if(argc != 3) {
        printf("Specify the arguments in call program: magnitude and angle\n");
        return -1;
    }
    char *ptr;
    double num0 = strtol(argv[1], &ptr, 10);
    double num1 = strtol(argv[2], &ptr, 10);

    // em um dado ponto x,y é aplicado uma ângulo e uma força, calcule o novo x,y
    x = 0;
    y = 0;
    magnitude = num0;
    angle = num1;
    val = PI / 180;

    double * p = newPoint(x, y);
    printf("Output vector position: %f %f\n", p[0], p[1]);
}






double* newPoint(double x, double y){
    double* n = (double *) malloc(2 *sizeof(double));
    n[0] = x + magnitude * cos(angle * val);
    n[1] = y + magnitude * sin(angle * val);

    printf("Angle: %d\n", angle);
    printf("Cos: %f\n", cos(angle * val) );
    printf("Sin: %f\n", sin(angle * val) );

    return n;
}


void move(float speed) {
    while(true){

    }
}
