/**
*	@file 	Sistemas_Lineares.c
*	@brief	Funções relacionadas ao tratamento do Sistema Linear
*/
#include "Sistemas_Lineares.h"
#include "utils.h"

const double pi_quad = M_PI*M_PI; /**< Variável para armazenar o valor de π² */

//aloca e atribui o tamanho a uma estrtura do tipo SistLinear_t
SistLinear_t *InicializaSistLinear(int n)
{
	SistLinear_t *SL = malloc(sizeof(SistLinear_t));
	SL->n = n;
	SL->b = malloc(SL->n*sizeof(double));
	return(SL);
}

//calcula a função f(x,y) definida por f(x,y) = 4pi²*[sin(2piX)*sinH(piY) + sin(2pi(pi - x))*sinH(pi(pi - y))]
double calc_f (double x, double y) 
{
	double p1, p2, res;

	res = 4*pi_quad;    //res = 4 pi^2
	
	p1  = sin(2*M_PI*x)				// p1 = sin(2pi* x)

		* sinh(M_PI*y); 			// p1 = sin(2* pi* x) * sinh(pi* y)

	p2  = sin(2*M_PI*(M_PI - x)) 	//p2 = sin(2* pi* (pi - x))

		* sinh(M_PI*(M_PI - y));    //p2 = sin(2* pi* (pi - x)) * sinh(pi* (pi - y))

	res *= (p1 + p2);   // res = 4* pi^2 (p1 + p2)
	return res;
}

//gera o sistema linear de uma equação diferencial parcial de segunda ordem discretizada pelo método das diferenças finitas
SistLinear_t *GeraSistLinear(SistLinear_t *SL, int nx, int ny) 
{

	double hx = M_PI/(nx+1);
	double hy = M_PI/(ny+1);	
	
	double hy_quad = hy*hy;
	double hx_quad = hx*hx;

	SL->dig_p = 4*hy_quad + 4*hx_quad + 8*M_PI*M_PI*hx_quad*hy_quad; //(4hy² + 4hx²+ 8pi²hx²hy²)Uij
	SL->dig_sup = -2*hy_quad + hx*hy_quad; //(-2hy² + hxhy²)(Ui+1,j)
	SL->dig_inf = -2*hy_quad - hx*hy_quad; //(-2hy² - hxhy²)(Ui-1,j)
	SL->dig_sup_af = -2*hx_quad + hx_quad*hy; //(-2hx² + hx²hy)(Ui,j+1)
	SL->dig_inf_af = -2*hx_quad - hx_quad*hy; //(-2hx² - hx²hy)(Ui,j-1)

	int k = 0;		//caminha no vetor b[k]
	int i; 			//caminha pelo eixo x
	int j;			//caminha pelo eixo y

	double xi;		// x0 = 0.0, Xnx+1 = pi 
	double yj;		// y0 = 0.0, Yny+1 = pi
	double hxq_hyq_2 = 2*hx_quad*hy_quad;

	//calcula vetor b
	for(j = 0; j <= ny + 1; j++)
	{
		yj = j*hy;	
		for(i = 0; i <= nx + 1 ; i++)
		{
			k = i + j*(nx+2);
			xi = i*hx;	
			SL->b[k] = (hxq_hyq_2)*calc_f(xi,yj);
	 	}
	}
	return(SL);
}

//calcula o residuo de uma solução de um sistema linear gerado por uma equação diferencial parcial de segunda ordem
double normaL2Residuo(SistLinear_t *SL, int nx, int ny, double *x) 
{
  	double residuo;
  	double r_soma = 0.0;
  	int i,j,k;
  	k = 0;

	// for (i = 1; i <= nx; i++)
	// {
	// 	for (j = 1; j <= ny; j++)
	// 	{
	// 		k = j + i*(nx+2);
	// 		residuo = SL->b[k] - (SL->dig_p)*x[k] - (SL->dig_inf)*x[k-1] - (SL->dig_inf_af)*x[k-(nx+2)] - (SL->dig_sup)*x[k+1] - (SL->dig_sup_af)*x[k+(nx+2)];
	// 		r_soma += residuo*residuo;
	// 	}
	// }

	for (i = 1; i <= nx; i++)
	{
		for (j = 1; j <= ny - ny%2; j+=2)
		{
			
			k = j + i*(nx+2);
			residuo = SL->b[k] - (SL->dig_p)*x[k] - (SL->dig_inf)*x[k-1] - (SL->dig_inf_af)*x[k-(nx+2)] - (SL->dig_sup)*x[k+1] - (SL->dig_sup_af)*x[k+(nx+2)];
			r_soma += residuo*residuo;


		 	// residuo = 0.0f;
			residuo = SL->b[k+1] - (SL->dig_p)*x[k+1] - (SL->dig_inf)*x[k] - (SL->dig_inf_af)*x[k-(nx+1)] - (SL->dig_sup)*x[k+2] - (SL->dig_sup_af)*x[k+(nx+3)];
			r_soma += residuo*residuo;
			
		 	// residuo = 0.0f;
			// residuo = SL->b[k+2] - (SL->dig_p)*x[k+2] - (SL->dig_inf)*x[k+1] - (SL->dig_inf_af)*x[k-nx] - (SL->dig_sup)*x[k+2] - (SL->dig_sup_af)*x[k+(nx+4)];
			// r_soma += residuo*residuo;

			// residuo = SL->b[k+3] - (SL->dig_p)*x[k+4] - (SL->dig_inf)*x[k+2] - (SL->dig_inf_af)*x[k+1-nx] - (SL->dig_sup)*x[k+3] - (SL->dig_sup_af)*x[k+(nx+5)];
			// r_soma += residuo*residuo;
			
		}

		// resto do unroll & jam
		for (int t = 1; t <= ny%2; t++){
		 	// residuo = 0.0f;
			// x[k+2+t] = x[k+2+t]/(SL->dig_p);
			residuo = SL->b[k+1+t] - (SL->dig_p)*x[k+1+t] - (SL->dig_inf)*x[k+t] - (SL->dig_inf_af)*x[k+t-(nx+1)] - (SL->dig_sup)*x[k+2+t] - (SL->dig_sup_af)*x[k+t+(nx+3)];
			// r_soma += residuo*residuo;
			// printf("k + 2 + t: %d\n", k + 2 + t);
		}
	}
 	r_soma = sqrt(r_soma);
  	return(r_soma);
}


int Contorno_X (double *x, int nx, int ny){

	double hx = M_PI/(nx+1);
	double pi_2 = 2*M_PI;
	//double hy = M_PI/(ny+1);

	for (int i = 1; i <= nx + 1; i++){
		x[i] = sin(pi_2*(M_PI-(i*hx)))*sinh(pi_quad); //U(x,0) = sin(2pi(pi-x))*sinH(pi²)
	}

	for (int j = 1; j <= ny; j++){
		x[j + (ny + 1)*(nx + 2)] = sin(pi_2*(j*hx))*sinh(pi_quad); //U(x,pi) = sin(2piX)*sinH(pi²) 
	}

	return 0;
}

// resolve um sistema linear gerado por uma equação diferencial parcial de segunda ordem por Gauss-Seidel
void Gauss_Seidel(int nx , int ny, int maxiter, SistLinear_t *SL , double *tempo_medio, double *x, double *residuo)
{

	
	double time_ini, time_fim;
	*tempo_medio = 0.0;
	int i,j,k,it;
	k = 0;
	for(it = 0; it < maxiter; it++)
	{			
		time_ini = timestamp();

		for (i = 1; i <= nx; i++)
		{
			// unroll
			for (j = 1; j <= ny - ny%6; j+=6)
			{
				
				k = j + i*(nx+2);
				x[k] = SL->b[k] - (SL->dig_inf)*x[k-1] - (SL->dig_inf_af)*x[k-(nx+2)] - (SL->dig_sup)*x[k+1] - (SL->dig_sup_af)*x[k+(nx+2)];		
				x[k] = x[k]/(SL->dig_p);

				x[k+1] = SL->b[k+1] - (SL->dig_inf)*x[k] - (SL->dig_inf_af)*x[k-(nx+1)] - (SL->dig_sup)*x[k+2] - (SL->dig_sup_af)*x[k+(nx+3)];		
				x[k+1] = x[k+1]/(SL->dig_p);

				x[k+2] = SL->b[k+2] - (SL->dig_inf)*x[k+1] - (SL->dig_inf_af)*x[k-nx] - (SL->dig_sup)*x[k+3] - (SL->dig_sup_af)*x[k+(nx+4)];		
				x[k+2] = x[k+2]/(SL->dig_p);

				x[k+3] = SL->b[k+3] - (SL->dig_inf)*x[k+2] - (SL->dig_inf_af)*x[k-nx+1] - (SL->dig_sup)*x[k+4] - (SL->dig_sup_af)*x[k+(nx+5)];		
				x[k+3] = x[k+3]/(SL->dig_p);

				x[k+4] = SL->b[k+4] - (SL->dig_inf)*x[k+3] - (SL->dig_inf_af)*x[k-nx+2] - (SL->dig_sup)*x[k+5] - (SL->dig_sup_af)*x[k+(nx+6)];		
				x[k+4] = x[k+4]/(SL->dig_p);


				x[k+5] = SL->b[k+5] - (SL->dig_inf)*x[k+4] - (SL->dig_inf_af)*x[k-nx+3] - (SL->dig_sup)*x[k+6] - (SL->dig_sup_af)*x[k+(nx+7)];		
				x[k+5] = x[k+5]/(SL->dig_p);

			}

			//  jam
			for (int t = 1; t <= ny%6; t++){
				x[k+5+t] = SL->b[k+5+t] - (SL->dig_inf)*x[k+4+t] - (SL->dig_inf_af)*x[k+t-nx+3] - (SL->dig_sup)*x[k+6+t] - (SL->dig_sup_af)*x[k+t+(nx+7)];
				x[k+5+t] = x[k+5+t]/(SL->dig_p);
				// printf("k + 2 + t: %d\n", k + 2 + t);
			}
		}
		time_fim = timestamp();
		*tempo_medio += (time_fim - time_ini);
		
		residuo[it] = normaL2Residuo(SL,nx,ny,x);

	}
	
	*tempo_medio = *tempo_medio/maxiter;
}