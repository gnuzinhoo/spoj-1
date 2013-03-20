#include <stdio.h> 
#include <math.h> 
   int calcCentro(int n) 
   { 
      if (n == 0) 
         return 0; 
      int c = calcCentro(n-1); 
      return 4 * (c + (int)sqrt(c)) + 1; 
   } 
   int numPapeis(int n) 
   { 
      int c = calcCentro(n); 
      return c + 4*(int)sqrt(c) + 4; 
   } 
   int main() 
   { 
      int n; 
      int t = 1; 
      int lixo; 
      for (scanf("%d", &n); n != -1; scanf("%d", &n)) 
         printf("Teste %d\n%d\n\n", t++, numPapeis(n)); 
      return 0; 
   } 
