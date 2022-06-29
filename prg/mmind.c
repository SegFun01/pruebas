#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* función que genera entero al azar entre 0 y 9 */
int digito_azar()
{
  /* VARIABLES */
  double r;	/* valor random entre [0,1) */
  long int M;	/* limite superior */
  double x;	/* valor random entre [0,M) */
  int y;	/* valor random discreto entre [0,M) */
  int i;        /* contador */

  /* CODIGO */
  M = 10;	/* Limitar el random a 10m dígitos */
  r = (   (double)rand() / ((double)(RAND_MAX)+(double)(1)) );
  x = (r * M);
  y = (int) x;
  return(y);
}

/* función que crea la cadena de 4 enteros diferentes de 0 a 9 */
int genera_num(int s[6])
{
  int i,j;  /* contadores */
  int c;
  int r;

  c= digito_azar();
  s[0]=c;    
  
  for (i=1;i<4;i++)
  {
    r = 0;
    while (r==0)
    { 
     c= digito_azar();   
     for(j=0;j<i;j++)
      {
        if(s[j]!=c)
         {
           r=1;
         } 
        else 
         {
           r=0;  /* digito repetido */
           j=i;  /* para salir del for y recalcular el digito */
         }
      }
    }
    s[i]=c; 
  }
  return(0);
}

/* funcion que lee los 4 dígitos desde teclado */
int lee(int s[6])
{
  int i;
  int c;
  i=0;
  printf(" ? > ");
  while ( ( ( c=getchar() )!= '\n') && (i<4) )
  {
    s[i++]=c-'0';
  }
  return(i);
}

/* funcion imprime cadena de 4 enteros */
int impr(int s[6])
{
  int i; 
  for(i=0; i<4; i++)
  {
    printf("%1d", s[i]);
  }
  printf("\n");
  return(i);
}


/* funcion que compara las 2 cadenas */
int comprueba(int s[6], int r[6])
{ 
  int resultado;
  int i,j;
  int p,f;
  
  p=f=0;
  resultado=1;
 
  for(i=0; i<4 ;i++)
  {
    for(j=0; j<4; j++)
    {
      if(s[i]==r[j])
      {
        if(i==j)
         {
          f=f+1;
         }
         else
         {
          p=p+1;
         }
      }
    }
  }
  if(f==4)
  {
   resultado=0;
  }
  printf("-----------> %5d      %5d\n",p,f);
  return(resultado);
}

/* PROGRAMA PRINCIPAL */
int main()
{
  /* VARIABLES */
  int seed, sec;	/* semilla del random */
  int i;        /* contador */
  int n;
  int s[6];
  int r[6];
  int ok;
  int intentos;

  /* CODIGO */
  sec = time(NULL);
  seed = (int)sec;		/* valor para seed */
  srand(seed);		/* inicializa random */
  
  n = genera_num(s);
   
  ok=1;
  intentos=0;
  printf("--- Mente maestra ---\n");
  printf("Incognita   Puntos  Famas\n");
  printf("--------------------------\n");
  
 /* n = impr(s);  esta instruccion es para imprimir la incognita para comprobar el funcionamiento del juego */

  while (ok==1 && intentos<20)
  {
    n = lee(r);
    ok = comprueba(s,r);  
    intentos++;
  }
    if (ok==0)
    {
      printf("Acertaste en %2d intentos!!!\n", intentos);
    }
    if (intentos==20)
    {
     printf("Demasiados intentos... otra vez será...\n");
    }
} 
