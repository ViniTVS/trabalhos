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
	
	p1 = sin(2*M_PI*x); // p1 = sin(2pi* x)

	p1 *= sinh(M_PI*y); // p1 = sin(2* pi* x) * sinh(pi* y)

	p2 = sin(2*M_PI*(M_PI - x)); //p2 = sin(2* pi* (pi - x))

	p2 *= sinh(M_PI*(M_PI - y));    //p2 = sin(2* pi* (pi - x)) * sinh(pi* (pi - y))

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

	int k = 0;//caminha no vetor b[k]
	int i = 1; //caminha pelo eixo x
	int j = 1;//caminha pelo eixo y

	double xi;// x0 = 0.0, Xnx+1 = pi 
	double yj;// y0 = 0.0, Yny+1 = pi

	//calcula vetor b e aplica condições de contorno
	for(j = 1; j <= ny; j++)
	{
		yj = j*hy;	
		for(i = 1; i <= nx ; i++)
		{
			xi = i*hx;	
			SL->b[k] = (2*hx_quad*hy_quad)*calc_f(xi,yj);
	 	
			//i == 1, dig_inf*Ui-1,j => dig_inf*U0,j, então b[k] = b[k] - dig_inf*(0.0), pois U(0,y) == 0.0
			//i == nx, dig_sup*Ui+1,j => dig_sup*Unx+1,j, então b[k] = b[k] - dig_sup*(0.0), pois U(pi,y) == 0.0

			if(j == 1)
				SL->b[k] -= (SL->dig_inf_af)*sin(2*M_PI*(M_PI - xi))*sinh(pi_quad);//U(x,0) = sin(2pi(pi-xi))*sinH(pi²)
			else
				if(j == ny)
					SL->b[k] -= (SL->dig_sup_af)*sin(2*M_PI*xi)*sinh(pi_quad); //U(x,pi) = sin(2piX)*sinH(pi²)
			k++;
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

  i = 1;
  j = 1;
  for(k = 0; k < SL->n; k++)
  {
	
	residuo = SL->b[k] - SL->dig_p*x[k];

	if(i != 1)
		residuo -= (SL->dig_inf)*x[k-1];
	if(j != 1)
		residuo -= (SL->dig_inf_af)*x[k-nx];
	if(i != nx)
		residuo -= (SL->dig_sup)*x[k+1];	
	if(j != ny)
		residuo -= (SL->dig_sup_af)*x[k+nx];
	
    r_soma += residuo*residuo;
  
	if(i == nx)
	{
		j++;
		i = 1;
	}
	else
		i++;
  }
  
  r_soma = sqrt(r_soma);
  return(r_soma);
}

// resolve um sistema linear gerado por uma equação diferencial parcial de segunda ordem por Gauss-Seidel
void Gauss_Seidel(int nx , int ny, int maxiter, SistLinear_t *SL , double *tempo_medio, double *x, double *residuo)
{

	double *x_ant = calloc(SL->n,sizeof(double));
	double time_ini, time_fim;
	*tempo_medio = 0.0;
	int i,j,k,it;

	for(it = 0; it < maxiter; it++)
	{			
		time_ini = timestamp();
		
		i = 1;
		j = 1;
		for(k = 0; k < SL->n; k++)
		{
			x[k] = SL->b[k];

			if(i != 1)
				x[k] -= (SL->dig_inf)*x[k-1];
			if(j != 1)
				x[k] -= (SL->dig_inf_af)*x[k-nx];
			if(i != nx)
				x[k] -= (SL->dig_sup)*x_ant[k+1];	
			if(j != ny)
				x[k] -= (SL->dig_sup_af)*x_ant[k+nx];

			x[k] = x[k]/(SL->dig_p);
			
			x_ant[k] = x[k];
		
			if(i == nx)
			{
				j++;
				i = 1;
			}
			else
				i++;
		}				

		time_fim = timestamp();
		*tempo_medio += (time_fim - time_ini);
		
		residuo[it] = normaL2Residuo(SL,nx,ny,x);

	}
	
	*tempo_medio = *tempo_medio/maxiter;
}