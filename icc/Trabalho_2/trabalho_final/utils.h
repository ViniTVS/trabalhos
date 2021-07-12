/**
*	@file 	utils.h
*	@brief	Biblioteca de utils.c
*/
#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

/**
 * Função de cálculo de tempo disponibilizada pelos professores
 * 
 * @return	Tempo medido
 */
double timestamp(void);

/**
 * Grava em variáveis os valores passados por parâmetro na execução do programa
 * 
 * @param[in]	argc			Valor argc gerado pela execução do programa
 * @param[in]	argv			String argv gerado pela execução do programa
 * @param[out]	nx				Número de pontos a serem calculados na dimensão X
 * @param[out]	ny				Número de pontos a serem calculados na dimensão Y
 * @param[out]	maxiter 		Número de iterações a serem executadas
 * @param[out]	arquivo_saida 	Nome do arquivo em que será escrita a saída do programa (caso exista)
 * 
 * @retval 		0				Caso os parâmetros sejam lidos
 * @retval 		-1				Caso tenha problema com os parâmetros de execução
 */
int busca_args(int argc, char *argv[], int *nx, int *ny, int *maxIter, char **arquivo_saida);


/**
 * Grava em variáveis os valores passados pro parâmetro na execução do programa
 * 
 * @param nx 			Pontos calculados na dimensão X
 * @param ny 			Pontos calculados na dimensão Y
 * @param maxiter 		Número de iterações que foram executadas
 * @param tempo_medio	Tempo médio da execução de Gauss-Seidel
 * @param x 			Vetor que contém os valores da resolução do Sistema Linear
 * @param residuo		Vetor contendo os residuos normalizados de cada iteração feita
 * @param arquivo_saida Nome do arquivo de saída que será escrito (caso exista)
 * 
 * @retval	0		Caso consiga escrever a saida
 * @retval	-1		Caso não consiga criar o arquivo de impressão (caso exista)		
 */
int Imprime_Solucao(int nx, int ny, int maxiter, double tempo_medio, double *x, double *residuo, char *arquivo_saida);

#endif

