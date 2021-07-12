/**
*	@file 	Sistemas_Lineares.h
*	@brief	Biblioteca de Sistemas_Lineares.c
*/
#ifndef __SIST_LINEAR_H__
#define __SIST_LINEAR_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct SistLinear /** Estrutura de dados com variáveis equivalentes ao Sistmea Linear formado*/
{
	double dig_p; 		/**< Variável da diagonal principal */
	double dig_sup;		/**< Variável da diagonal superior */
	double dig_inf;		/**< Variável da diagonal inferior */
	double dig_sup_af;	/**< Variável da diagonal superior afastada */
	double dig_inf_af;	/**< Variável da diagonal inferior afastada */
	double *b;			/**< Vetor de termos independentes */
	int n;				/**< Tamanho do vetor solução */
}SistLinear_t; 

/**
 *	Aloca em memória o vetor solução e atribui o tamanho a uma estrtura do tipo SistLinear_t
 *
 *	@param 	n Valor do tamanho do vetor solução
 *
 *	@return Sistema Linear alocado em memória
 */
SistLinear_t *InicializaSistLinear(int n);

/**
*	Calcula o valor de f(x,y) especificado no trabalho.
*	
*	@param 	x Valor de x
*	@param	y Valor de y
*
*	@return Valor calculado por f(x,y)
*/
double calc_f (double x, double y);

/**
 *	Gera o Sistema linear de uma equação diferencial parcial de segunda ordem, discretizado pelo método das diferenças finitas com a forma central.
 * 	
 * @param 	SL 	Sistema Linear a ser feito
 * @param	nx	Número de pontos calculados na dimensão X
 * @param	ny	Número de pontos calculados na dimensão Y
 * 
 * @return 	Sistema Linear com o vetor b agora calculado com as condições de contorno do Sistema
 */
SistLinear_t *GeraSistLinear(SistLinear_t *SL, int nx, int ny);

/**
 * Resolve o Sistema linear de segunda ordem por meio do método de Gauss-Seidel
 *
 * @param[in]	nx			Número de pontos calculados na dimensão X
 * @param[in]	ny			Número de pontos calculados na dimensão Y
 * @param[in]	maxiter		Número de iterações a serem feitas
 * @param[in] 	SL 			Sistema Linear para cálculo do método
 * @param[out]	tempo_medio	Tempo médio para calcular as iterações do método
 * @param[out]	x			Vetor contendo a solução do Sistema Linear
 * @param[out]	residuo		Vetor contendo os valores normalizados do resíduo de cada iteração
 */
void Gauss_Seidel(int nx , int ny, int maxiter, SistLinear_t *SL , double *tempo_medio, double *x, double *residuo);

/**
 * Calcula o residuo de uma solução de um Sistema linear
 * 
 * @param	SL 	Sistema Linear 
 * @param	nx	Valor de nx passado na chamada do programa
 * @param	ny	Valor de ny passado na chamada do programa
 * @param	x	Vetor de resposta da iteração de Gauss-Seidel
 * 
 * @return	Valor do residuo normalizado
 */
double normaL2Residuo(SistLinear_t *SL, int nx, int ny, double *x);

#endif //__SIST_LINEAR_H__