#include <stdio.h> 
#ifdef DEBUG 
#define PRINT(x...) printf(x) 
#else 
#define PRINT(x...) 
#endif 
   int main() 
   { 
      int v[10000], n, i, picos; 
      for (scanf("%d", &n); n != 0; scanf("%d", &n)) 
      { 
         picos = 0; 
         for (i = 0; i < n; ++i) 
            scanf("%d", &v[i]); 
      #ifdef DEBUG 
      printf("mags: "); 
      for (i = 0; i < n; ++i) 
      printf("%d ", v[i]); 
      printf("\n"); 
      #endif 
         if ((v[n-1] < v[0] && v[1] < v[0]) || (v[n-1] > v[0] && v[1] > v[0])) 
         { 
         PRINT("pico na 1a nota\n"); 
            picos++; 
         } 
         for (i = 1; i < n-1; ++i) 
            if ((v[i-1] < v[i] && v[i+1] < v[i]) || (v[i-1] > v[i] && v[i+1] > v[i])) 
            { 
            PRINT("pico na nota %d\n", v[i]); 
               picos++; 
            } 
         if ((v[n-2] < v[n-1] && v[0] < v[n-1]) || (v[n-2] > v[n-1] && v[0] > v[n-1])) 
         { 
         PRINT("pico na ultima nota\n"); 
            picos++; 
         } 
         printf("%d\n", picos); 
      } 
      return 0; 
   } 
