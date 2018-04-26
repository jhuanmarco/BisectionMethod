// Lib imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Constants
#define EPSILON 0.01;// Stopping constant ÉPSILON (ε)

// F(X)
double f(double x){
	double y = (x*x*x) -(9*x) +5;
	printf("\nf = %lf\n", y);

	return y;
}

double fi(double x){
	double y =  ((x*x*x)+5)/9;
	
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


int stop2(double fi0, double fi1){ // |A - B| < ε (Absolute Error), xC = x current, xP = x previous
	double epsilon = EPSILON;
	double aux = fi1 - fi0;
	aux = fabs(aux);

	if(aux < epsilon){
		return 0;

	} else {
		return 1;
	}
}

int stop3(double fi0, double fi1){ // (|x(k) - x(k-i)|)/|x(k)| < ε (Relative Error)
	double epsilon = EPSILON;
	double aux = (fabs(fi1-fi0))/(fabs(fi1));

	if(aux < epsilon){
		return 0;
	} else {
		return 1;
	}
}


void main(){
	double chuteI = 0.75;
	double fi0, fi1; // f1 = xk e f0 = fk-1
	int iteracoes = 1;

	fi1 = chuteI;
	fi0 = chuteI - 100;

	while(stop2(fi0,fi1)){
		fi0 = fi1;
		fi1 = fi(fi0);
		iteracoes++;
	}

	/*
	stop1(f(fi1));
	stop2(fi0,fi1);
	stop3(fi0,fi1);
	*/
	
	printf("\nMETODO DO PONTO FIXO\n\n");
	printf("Raiz aproximada(X) = %lf\n", fi1);
	printf("F(X) = %lf\n", f(fi1));
	printf("%i iteracoes\n", iteracoes);

}