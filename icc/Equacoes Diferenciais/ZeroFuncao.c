#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"


int bisseccao (double (*f)(const double x), double a, double b,
							 double eps, int *it, double *raiz)
{
	double erro, fa, fr, fb, raiz_ant;
	double media;
	
	for (int i = 0; i < *it; i++){
		media = (a + b)/2;
		fa = f(a);
		
	}

#ifdef __DEBUG__
	fprintf(stderr, "\n\n****** Iterações Bissecção *******\n");
	fprintf(stderr, "=================================================================================================\n");
	fprintf(stderr, "  it            a            b           xs        f(xs)        |a-b|         f(a)         f(b)\n");
	fprintf(stderr, "=================================================================================================\n");
#endif  
	
	
#ifdef __DEBUG__
	fprintf(stderr, "%4d %12.8g %12.8g %12.8g ", *it, a, b, *raiz);
	fprintf(stderr, "%12.4e %12.4e %12.4e %12.4e\n", fr, fabs(a-b), fa, fb);
#endif  
	
	return 0;
}


/**
 *
 */
int newton (double (*f)(const double x), double (*df)(const double x), double x0, 
						double eps, int *it, double *raiz)
{
	double fx, dfx, erro;

#ifdef __DEBUG__
	fprintf(stderr, "\n\n****** Iterações Newton-Raphson *******\n");
	fprintf(stderr, "=================================================================================================\n");
	fprintf(stderr, "  it           x0           x0         raiz       f(raiz)   |raiz-x0|        f(x0)       df(x0)\n");
	fprintf(stderr, "=================================================================================================\n");
#endif  

#ifdef __DEBUG__
	fprintf(stderr, "%4d %12.8g %12.8g %12.8g ", *it, x0, x0, *raiz);
	fprintf(stderr, "%12.4e %12.4e %12.4e %12.4e\n", f(*raiz), fabs(*raiz-x0), fx, dfx);
#endif  
		
		
	return 0;
}


/**
 *
 */
int secante (double (*f)(const double x), double x0, double x1, 
						 double eps, int *it, double *raiz)
{
	double fx0, fx1, erro;

#ifdef __DEBUG__
	fprintf(stderr, "\n\n****** Iterações Secante *******\n");
	fprintf(stderr, "=================================================================================================\n");
	fprintf(stderr, "  it           x0           x1         raiz      f(raiz)    |raiz-x1|        f(x0)        f(x1)\n");
	fprintf(stderr, "=================================================================================================\n");
#endif  
		
		
#ifdef __DEBUG__
		fprintf(stderr, "%4d %12.8g %12.8g %12.8g ", *it, x0, x1, *raiz);
		fprintf(stderr, "%12.4e %12.4e %12.4e %12.4e\n", f(*raiz), fabs(*raiz-x0), fx0, fx1);
#endif  
		
	return 0;
}

/**
 * Cálculo de Polinômios
 */
int calcPolinomioEDerivada(Polinomio pol, double x, double *px, double *dpx )
{
	unsigned int tam = pol.grau;
	double *b;
	b = malloc(sizeof(double) * tam);

	b[tam] = pol.p[tam];
	// px = 
	for (int i = tam - 1; i >= 0; i--){
		b[i] = b[i+1]*x + pol.p[i];
		
	}
	*px = b[0];

	*dpx = b[tam] * x;

	for (int i = tam; i < 0; i--){
		*dpx = (*dpx + b[i]) * x;
	}

	return 0;
}

/**
 * Cálculo de Média
 */
double media(double *valores, unsigned long n)
{
	double soma = 0.0;

	return soma / n;
}


