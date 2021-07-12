#ifndef __ZEROFUNC01_H__
#define __ZEROFUNC01_H__


// Parâmetros para teste de convergência
#define MAXGRAU 20
#define MAXIT 500
#define EPS 1.0e-6

typedef struct {
  unsigned int grau;
  double p[MAXGRAU+1];
} Polinomio;

// Métodos de zero de Função

int bisseccao (double (*f)(const double x), double a, double b,
               double eps, int *it, double *raiz);

int newton (double (*f)(const double x), double (*df)(const double x), double x0, 
            double eps, int *it, double *raiz);

int secante (double (*f)(const double x), double x0, double x1, 
             double eps, int *it, double *raiz);

// Cálculo de Polinômios
int calcPolinomioEDerivada(Polinomio p, double x, double *px, double *dpx );

// Cálculo de Média
double media(double *valores, unsigned long n);

#endif // __ZEROFUNC01_H__

