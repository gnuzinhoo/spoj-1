#include <stdio.h> 
#define MODULO(x) (x < 0 ? x * -1 : x) 
#define DIFFMODULO(x, y) (x > y ? MODULO(x) - MODULO(y) : MODULO(y) - MODULO(x)) 
   int main() 
   { 
      int x, y, u, v; 
      for (scanf("%d%d%d%d", &x, &y, &u, &v); !(x == 0 && y == 0 && u == 0 && v == 0) ; scanf("%d%d%d%d", &x, &y, &u, &v)) 
      { 
         if ((x == u) && (y == v)) 
            printf("0\n"); 
         else if ((x == u) || (y == v) || (DIFFMODULO(x, u) == DIFFMODULO(y, v))) 
            printf("1\n"); 
         else 
            printf("2\n"); 
      } 
      return 0; 
   } 
