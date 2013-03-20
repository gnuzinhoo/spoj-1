#include <stdio.h>
#include <values.h>
#define NMAX 101 

   int main() {
   
      int w, i, j, x, y, teste=1, g[NMAX][NMAX], n, d[NMAX], fim, ini, fila[NMAX], v, a, md[NMAX], c;
      while (scanf("%d", &n)&&n) {
         for (i=1; i<=n; i++) {
            for (j=1; j<=n; j++) {
               g[i][j]=0;
            }
         }
      
         for (i=1; i<n; i++) {
            scanf("%d %d", &x, &y);
            g[x][y]=1;
            g[y][x]=1;
         }
      
         c=0;
         md[0]=MAXINT;
         for (v=1; v<=n; v++) {
            for (i=1; i<=n; i++) {
               d[i]=n;
            }
            md[v]=0;
            d[v]=0;
            ini=0;
            fim=0;
            fila[fim++]=v;
            while (ini!=fim) {
               a=fila[ini++];
               if (d[a]>md[v]) {
                  md[v]=d[a];
               }
               for (w=1; w<=n; w++) {
                  if (g[a][w]&&d[w]==n) {
                     d[w]=d[a]+1;
                     fila[fim++]=w;
                  }
               }
            }
            if (md[v]<md[c]) {
               c=v;
            }
         }
         printf("Teste %d\n%d\n\n", teste++, c);
      }
      return 0;
   } 
