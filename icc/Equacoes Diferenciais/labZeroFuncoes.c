#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

typedef struct {
  Polinomio pol;
  double a, b, nx0, sx0, sx1;
  double eps, maxit;
} Caso;

/***************************
 * Variáveis globais e funcoes para poder testar zeros de qquer funcao
 */
Polinomio pol_global;

double func_1 (double x)
{
  double px, dpx;
  calcPolinomioEDerivada(pol_global, x, &px, &dpx);
  return px;
}

double dfunc_1 (double x)
{
  double px, dpx;
  calcPolinomioEDerivada(pol_global, x, &px, &dpx);
  return dpx;
}

/*****************
 * f(x) = x^100, df(x) = 100*x^99
 */
double func_2 (double x)
{
  return pow(x, 100);
}
double dfunc_2 (double x)
{
  return 100*pow(x, 99);
}
/***************************/

/*****************
 * f(x) = 3*x^1/3, df(x) = x^-2/3
 */
double func_3 (double x)
{
  if (x < 0.0)
    return (-3.0 *pow((-x), 1.0/3.0));
  else	
    return (3.0 *pow(x, 1.0/3.0));
}

double dfunc_3 (double x)
{
  return pow(x*x, -1.0/3.0);
}
/***************************/

int main ()
{
  
  Caso testes[] = {
    {{2, {-10, 0, 1}},             0, 5, 1,   0, 1}, // raiz = 3.1623 (sqrt(10))
    {{4, {-15, -10, 3, 4, 2}},     0, 3, 1,   0, 3}, // raízes = -1.3004 e 1.4929
    {{5, {-24, 4, 22, -9, -2, 1}}, 0, 5, 1.5, 0, 5}, // raízes = -3.0 e -1.0 e 2.0
    {{4, {-30, 25, 4, 2, 3}},      0, 1, 0.5, 0, 1}, // raízes = -2.3596 e 0.918
    {{3, {3, -1, -5, 2}},          0, 1, 0.5, 0, 1}  // raízes = -0.7594 e 0.8047 e 2.4548
  };

  pol_global = testes[0].pol;
  double teste = func_1(3.1623);
  printf("Valor do teste: %f \n", teste);
  teste = dfunc_1(3.1623);
  printf("Valor do teste: %f \n", teste);

/*
  double raiz, tempo;
  int it, erro;
  unsigned long i;

  double nx0, x0, x1, a, b;

  // Fazer cálculos e mostrar tabelas
  // Imprime cabeçalho da tabela
  printf("#=============================================================================\n");
  printf("# metodo      ,raiz     ,erro    ,it     tempo(ms)\n");
  printf("#=============================================================================\n");


  // Imprimir média real e calculada em vetor de valores reais
  printf("# ==============================================================================\n");
  printf("# Média       , calculada    , real         , diff         , tempo(ms)\n");
  printf("# ==============================================================================\n");
  double x, media_vec, media_real;
  unsigned long vec_size = 100000;

  media_real = 1.0;
  double *vector = (double *) malloc( sizeof(double) * vec_size);

  vector[0] = vector[vec_size-1] = vec_size-2;
  for (i=1, x=1.0/(vec_size-2); i<vec_size; ++i) {
    vector[i] = x;
  }
  tempo = timestamp();
  media_vec = media(vector, vec_size);
  tempo  = timestamp() - tempo;
  printf("                %+10.6e, %+10.6e, %+10.6e, %5.3e\n", media_vec, media_real, fabs(media_real-media_vec), tempo);

  printf("# ==============================================================================\n");
    

  free(vector);
*/

  return 0;
}

