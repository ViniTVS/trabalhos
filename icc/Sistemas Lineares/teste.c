#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n = 0;


int eliminacaoGauss( double **A, double *b, int n ){
	for( int k=0; k < n; ++k ) {
		for( int i=k+1; i < n; ++i ) {
			double m = A[i][k] / A[k][k];
			A[i][k] = 0.0;
			for( int j=k+1; j < n; ++j )
				A[i][j] -= A[k][j] * m;
			b[i] -= b[k] * m;
		}
	}
	return 0;
}

/*
int eliminacaoGauss_PivoteamentoParcial( double **A, double *b, int n ){
	for( int k=0; k < n; ++k ) {
		double pivo;
		for(int i = k + 1; i < n; i++){
			pivo = maximo(a[i][k], a[][]);
		}
		for( int i=k+1; i < n; ++i ) {
			double m = A[i][k] / A[k][k];	// multiplicador
			A[i][k] = 0.0;
			for( int j=k+1; j < n; ++j )
				A[i][j] -= A[k][j] * m;
			b[i] -= b[k] * m;
		}
	}
	return 0;
}
*/


void print_m(double **A,int tam){
	for (int i = 0; i < tam; i++){
		for (int j = 0; j < tam; j++){
			printf("%f ", A[i][j]);
		}
		printf("\n");
	}
}

void insere_matriz(double ***A, int tam){
	printf("%p \n", A);
	int w;
	for (int i = 0; i < tam; i++){
		w = i+1;
		printf("%dª linha: \n", w);
		for (int j = 0; j < tam; j++){
			double x;
			scanf("%lf", &x);
			(*A)[i][j] = x;
			// printf("x: %lf %lf", x, (*A)[i][j]);
		}
		printf("\n");
	}

}

void insere_b(double **b, int tam){
	for (int i = 0; i < tam; i++){
		double x;
		scanf("%lf", &x);
		*b[i] = x;
	}
}

void imprime_b(double **b, int tam){
	for (int i = 0; i < tam; i++){
		printf("%lf", *b[i]);
	}
}

void main(){
	printf("Tamanho de n da matriz: \n");
	scanf("%d", &n);
	// alocação da matriz:
	double **A;
	A = calloc(n,sizeof(double *));
	for (int i=0; i < n; ++i)
		A[i] = calloc(n,sizeof(double));

	double *b;
	printf("Tam: %d \n", n);

	insere_matriz(&A, n);
	print_m(A, n);

}