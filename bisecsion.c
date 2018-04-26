// Lib imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Constants
#define EPSILON 0.00001;// Stopping constant ÉPSILON (ε)

// F(X)
double f(double x){
	double y = (x*x*x)/4 + (3*x)/4 - (3*x)/2 -2;

	return y;
}

// Stopping functions
int stop1(double x){ // |F(x)| < ε 
	double epsilon = EPSILON;

	if((fabs(f(x))) < epsilon){
		return 0;
	} else {
		return 1;
	}
}

int stop2(double A, double B){ // |A - B| < ε (Absolute Error), xC = x current, xP = x previous
	double epsilon = EPSILON;
	double aux = A - B;
	aux = fabs(aux);

	if(aux < epsilon){
		return 0;

	} else {
		return 1;
	}
}

int stop3(double xP, double xC){ // (|x(k) - x(k-i)|)/|x(k)| < ε (Relative Error)
	double epsilon = EPSILON;
	double aux = (fabs(xC-xP))/(fabs(xC));

	if(aux < epsilon){
		return 0;
	} else {
		return 1;
	}
}


void main(){
	double A;
	double B;
	double aux;
	double xC, xP;
	int iteracoes = 1;
	int flag = 0;

	printf("Digite o valor A do intervalo: ");
	scanf(" %lf", &A);
	printf("Digite o valor B do intervalo: ");
	scanf(" %lf", &B);

	if(B < A){
		aux = B;
		B = A;
		A = aux;
	} else if (A == B) {
		printf("Mesmo ponto digitado, erro ao informar o intervalo\n");
	}

	if((f(A) * f(B)) >= 0){
		printf("intervalo ruim(ou um dos pontos é raiz)\n");
		return;
	}

	do{
		xC = (A+B)/2;
		if(f(xC) == 0){
			flag = 1;
			break;
		}
		if ( ((f(A))	* (f(xC))) < 0){
			xP = B; 
			B =  xC;		 
		} else {
			xP = A;
			A = xC;
			
		}
		iteracoes++;
	} while(stop3(xP,xC));

	/*
	stop1(xC);
	stop2(A,B); <- root is on interval [A, xc] or [xc, B];
	stop3(xP,xC);
	*/

	if(flag){
		printf("\nENCONTROU RAIZ EXATA");
	}
	
	printf("\nMETODO DA BISSECCAO\n\n");

	printf("Raiz aproximada(X) = %lf\n", xC);
	printf("F(X) = %lf\n", f(xC));
	printf("%i iteracoes\n", iteracoes);

}