// Lib imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Constants
#define EPSILON 0.01;// Stopping constant ÉPSILON (ε)

// F(X)
double f(double x){
	//double y = (x*x) - 4;
	double y = 3*x + 4;
	return y;
}

double df(double x){
	//double y = 2*x;
	double y = 3;
	return y;
}

double proxX(double x0){
	double y = x0 - (f(x0)/df(x0));
	return y;
}

// Stopping functions
int stop1(double x){ // f(x) < ε 
	double epsilon = EPSILON;
	if((fabs(x)) < epsilon){
		return 0;
	} else {
		return 1;
	}
}


int stop2(double x0, double x1){ // |xo - x1| < ε (Absolute Error)
	double epsilon = EPSILON;
	double aux = x1 - x0;
	aux = fabs(aux);

	if(aux < epsilon){
		return 0;

	} else {
		return 1;
	}
}

int stop3(double x0, double x1){ // (|x(k) - x(k-i)|)/|x(k)| < ε (Relative Error)
	double epsilon = EPSILON;
	double aux = (fabs(x1-x0))/(fabs(x1));

	if(aux < epsilon){
		return 0;
	} else {
		return 1;
	}
}


void main(){
	double chuteI = 1;
	double x0, x1; // f1 = xk e f0 = fk-1
	int iteracoes = 0;

	printf("Digite o chute inicial: ");
	scanf("%lf",  &chuteI);

	x1 = chuteI;

	do{
		x0 = x1;
		x1 = proxX(x0);
		iteracoes++;
	} while(stop2(x0,x1));

	/*
	stop1(f(x1));
	stop2(x0,x1);
	stop3(x0,x1);
	*/
	
	printf("\nMETODO DE NEWTON\n\n");
	printf("Raiz aproximada(X) = %.15lf\n", x1);
	printf("F(X) = %.15lf\n", f(x1));
	printf("%i iteracoes\n\n", iteracoes);

}