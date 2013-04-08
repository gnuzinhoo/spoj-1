#include <stdio.h> 
#include <stdlib.h> 
   using namespace std; 
#define abs(x) ((x) > 0 ? (x) : -(x)) 
   int n; 
   int tesouro[101]; 
#define MAX_SUM 10000 
   bool m[MAX_SUM];
   bool subSetSum(int M, int c) {
      for (int i = 0; i <= M; i++)
         m[i] = false; 
      m[0] = true;
      for(int i = 0; i < n; i++) {
         for(int j = M; j >= tesouro[i]; j--) {
            m[j] |= m[j - tesouro[i]];
         }
      }
      return m[c];
   } 
   int main() {
      int x, y, acum, v;
      int teste = 0;
      bool igual;
      while (1) {
         scanf("%d %d %d", &x, &y, &n);
         if (x == 0 && y == 0 && n == 0)
            break;
         acum = 0;
         for (int i = 0; i < n; i++) {
            scanf("%d", &tesouro[i]);
            acum += tesouro[i];
         } 
         v = acum - abs(x - y);
         if (v == 0)
            igual = true;
         else if (v % 2 == 0 && n > 1) { 
            igual = subSetSum(acum, v/2);
         } 
         else
            igual = false;
         if (igual)
            printf("Teste %d\nS\n\n", ++teste);
         else
            printf("Teste %d\nN\n\n", ++teste);
      }
      return 0;
   }
