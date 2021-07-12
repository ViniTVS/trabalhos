/**
*	@file 	pdeSolver.c
*	@brief	Contém a função main do programa
*/
#include <stdio.h>
#include <stdlib.h>
#include "Sistemas_Lineares.h"
#include "utils.h"
//Equação:
//(-2hy² + hxhy²)(Ui+1,j) + (-2hy² - hxhy²)(Ui-1,j) + (-2hx² + hx²hy)(Ui,j+1) + (-2hx² - hx²hy)(Ui,j-1) +(4hy² + 4hx² + 8pi²hx²hy²)Uij = f(x,y)*2hx²hy²
//f(x,y) = 4pi²*[sin(2piX)*sinH(piY) + sin(2pi(pi - x))*sinH(pi(pi - y))]
 
//Dom: [0,pi]x[0,pi]

//Condições de Contorno:
//U(x,0) = sin(2pi(pi-x))*sinH(pi²)
//U(x,pi) = sin(2piX)*sinH(pi²)
//U(0,y) = U(pi,y) = 0



/**
* Função chamada pelo Sistema Operacional para execução do programa
*
* @param	argc	Número de argumentos da execução do programa
* @param	argv	Vetor de strings dos argumentos de execução do programa
*
* @retval	0		Caso o programa seja executado corretamente
* @retval	-1		Caso seja encontrado um erro durante a execução do programa
*/
int main(int argc, char *argv[])
{
	int nx = 0, ny = 0 , maxiter = 0;
	char *arquivo_saida = NULL;

	int teste = busca_args(argc,argv,&nx,&ny, &maxiter, &arquivo_saida);

	if(teste != 0)
		return teste;

	SistLinear_t *SL = InicializaSistLinear(nx*ny); 		//n = nx*ny
	double *x = malloc(SL->n*sizeof(double));
	double tempo_medio;
	double *residuo = malloc(maxiter*sizeof(double));		//guarda o residuo de cada iteração
	
	SL = GeraSistLinear(SL,nx,ny);

	Gauss_Seidel(nx,ny,maxiter,SL,&tempo_medio,x,residuo);

	teste = Imprime_Solucao(nx ,ny , maxiter, tempo_medio, x , residuo, arquivo_saida);
	
	if(teste != 0)
		return teste;

	return 0;
}