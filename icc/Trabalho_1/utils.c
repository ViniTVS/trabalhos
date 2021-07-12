/**
*	@file 	utils.c
*	@brief	Funções auxliares para a execução do programa
*/
#include "Sistemas_Lineares.h"
#include "utils.h"

// Retorna tempo em milisegundos
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int busca_args(int argc, char *argv[], int *nx, int *ny, int *maxIter, char **arquivo_saida){
    if (argc < 7){
        fprintf(stderr, "Falta de parâmetros para execução\n");
        return (-1);
    }

    for (int i = 1; i < argc; ){

            if(strcmp(argv[i], "-nx") == 0){
                *nx = atoi(argv[i+1]);
                
                if(*nx < 1){
		            fprintf(stderr, "Valor de nx não aceitável para execução\n");
		            return (-1);
                }

                i = i + 2;
            }else

            if(strcmp(argv[i], "-ny") == 0){
                *ny = atoi(argv[i+1]);
                
                if(*ny < 1){
		            fprintf(stderr, "Valor de ny não aceitável para execução\n");
		            return (-1);
                }

               // printf("ny: %d\n", *ny);
                i = i + 2;
            }else

            if(strcmp(argv[i], "-i") == 0){
                *maxIter = atoi(argv[i+1]);
                
                if(*maxIter < 1){
		            fprintf(stderr, "Valor de iterações não aceitável para execução\n");
		            return (-1);
                }

                i = i + 2;
            }else

            if(strcmp(argv[i], "-o") == 0){
                *arquivo_saida = argv[i+1];
                //printf("arquivo_saida: %s\n", *arquivo_saida);
                i = i + 2;
            }
            else{	
	            fprintf(stderr, "Padrão de parâmetro não reconhecido\n");
	            return (-1);
            }

    }


    return 0;

}

int Imprime_Solucao(int nx, int ny, int maxiter, double tempo_medio, double *x , double *residuo, char *arquivo_saida)
{
	FILE *pont_arq;

	if(arquivo_saida != NULL)
	{
		pont_arq = fopen(arquivo_saida, "w");
		if(pont_arq == NULL)
		{
			fprintf(stderr, "Falha na criação do arquivo de saida\n");
			return(-1);
		}
	}
	else
		pont_arq = stdout;


	fprintf(pont_arq,"###########\n");
	fprintf(pont_arq,"# Tempo Método GS: %g ms\n#\n", tempo_medio);
	fprintf(pont_arq,"# Norma L2 do Residuo\n");
	
	for(int i = 0; i < maxiter; i++)
		fprintf( pont_arq, "#i = %d: %g\n" , i+1 , residuo[i]);
	fprintf(pont_arq,"###########\n");

	

	double hx = M_PI/(nx+1);
	double hy = M_PI/(ny+1);
	double xi,yj;

	int i,j,k;
	
	k = 0;

	for(j = 0; j <= ny+1; j++)
	{
		yj = j*hy;	
		for(i = 0; i <= nx+1 ; i++)
		{
			xi = i*hx;	
	
			fprintf(pont_arq,"%g %g ", xi, yj);
			
			if(i == 0 || i == nx+1)
				fprintf(pont_arq,"0\n");
			else
				if(j == 0)
				{
					double cont_x_0 = sin(2*M_PI*(M_PI - xi))*sinh(M_PI*M_PI);//U(x,0) = sin(2pi(pi-xi))*sinH(pi²)
					fprintf(pont_arq,"%g\n", cont_x_0);
				}	
				else
					if(j == nx+1)
					{
						double cont_x_pi = sin(2*M_PI*xi)*sinh(M_PI*M_PI); //U(x,pi) = sin(2piX)*sinH(pi²)
						fprintf(pont_arq,"%g\n", cont_x_pi);
					}
					else
					{	
						fprintf(pont_arq,"%g\n", x[k]);
						k++;
					}
	 	}
	}

	fclose(pont_arq);
	return 0;
}
