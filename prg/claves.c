#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int aleatorio(int m)
{
   int a;
   a=rand()%m;
   return a;        
}

int main(int argc, char *argv[])
{
  int i,j,k,n,Ok;
  int cantidad, letras, numeros; 
  int seleccion[15];
  if (argc<4)
  {
    printf("Uso: claves cantidad, letras, numeros\n");
  }
  else
  {
   srand(time(NULL)%1000); 
   
   cantidad=atoi(*++argv);
   letras=atoi(*++argv);  
   numeros=atoi(*++argv);

   for (k=0;k<cantidad;k++)
   {
     for (i=0;i<15;i++)
     {
       seleccion[i]= -1; 
     }
     for (i=0;i<letras;i++)
     {
       Ok=0;
       while (!Ok)
       {
         n=aleatorio(25);
         if ( (n==0) || (n==4) || (n==8) || (n==14) || (n==20) ) n++;
         Ok=1;
         for (j=0;j<letras;j++)
         { 
           if (seleccion[j]==n) 
           {
             Ok=0;
             exit;
           }
         }
       }
       seleccion[i]=n;
       printf("%c",n+97);
     }
     for (i=0;i<15;i++)
     {
       seleccion[i]= -1; 
     }    
     for (i=0;i<numeros;i++)
     {
       Ok=0;
       while (!Ok)
       {
         n=aleatorio(10);
         Ok=1;
         for (j=0;j<numeros;j++)
         { 
           if (seleccion[j]==n) 
           {
             Ok=0;
             exit;
           }
         }
       }
       seleccion[i]=n;
       printf("%d",n);
     }
     printf("\n");
   }  
  }
}
