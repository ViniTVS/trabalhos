#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "SistemasLineares.h"

int main ()
{
	// inicializa gerador de nr aleatoreos
	srand(20192);

	SistLinear_t *SL;
	SistLinear_t *SL2;
/*
	printf("Informe o tamanho da matriz: \n");
	unsigned int tam_sis, teste;
	scanf("%d", &tam_sis);

	tipoSistLinear_t tipo;
	printf("Informe o tipo de sistema: \n");
	scanf("%d", &teste);
	tipo = teste;

	SL = alocaSistLinear(tam_sis);
	inicializaSistLinear(SL, tipo, tam_sis);
*/



	// printf("Tamanho: ");
	// SL = lerSistLinear();	
	// 
	// printf("Tamanho: ");
	// SL2 = lerSistLinear();

	SL = lerSistLinear();
	SL2= lerSistLinear();

	printf("\nSistema1: \n");
	prnSistLinear(SL);
	printf("\nSistema2: \n");
	prnSistLinear(SL2);



	real_t *resp_sis = (float*) malloc(17 * sizeof(float));

	int a = eliminacaoGauss(SL, resp_sis, 0);

	printf("Vetor X: \n");
	prnVetor( resp_sis, 10);
	// prnSistLinear(SL);
	// prnSistLinear(SL2);
	real_t erro;
/*

	printf("Sistema2 final: \n")/*;
	prnSistLinear(SL2);

	// prnVetor( resp_sis, tam_sis);
	resp_sis[1] = 0.9;
	prnVetor(resp_sis, tam_sis);
	*/

	printf("\nSistema1 final: \n");
	prnSistLinear(SL);
	printf("\nSistema2 final: \n");
	prnSistLinear(SL2);


	erro = normaL2Residuo(SL2, resp_sis);
	printf("\nErro: %f \n", erro);

	return 0;
}

