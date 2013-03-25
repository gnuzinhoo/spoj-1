#include<stdio.h>
#include<math.h>
   int main() {
      int n = 0;
      scanf("%d", &n);
      while (n != 0) {
         int par_m = 0;
         int i_j = 0;
         for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x % 2 == 0) 
               par_m++;
         } 
         for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x % 2 != 0) {
               i_j++; 
            }
         }
         int r = par_m - i_j;
         if (r < 0) {
            r = r * (-1);
         } 
         printf("%d\n", r); 
         scanf("%d", &n);
      } 
      return (0);
   }
