#include <cstdio>
#include <list>
#include <set>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 3000
   int n, t = 0;
   int cont, numcomp;
   int id[MAX], pre[MAX], low[MAX];
   int pilha[MAX], topo;
   int grafo[MAX][MAX];
   int nviz[MAX];
   int mat[MAX][MAX];
   void empilha( int v) {
      pilha[topo++] = v;
   }
   int desempilha(void) {
      return pilha[--topo];
   }
   void busca(int v) {
      int i, aux, min = low[v] = pre[v] = cont++;
      empilha(v);
      for (i = 0; i < nviz[v]; i++) {
         aux = grafo[v][i];
         if (pre[aux] == -1)
            busca(aux);
         if (low[aux] < min)
            min = low[aux];
      }
      if (min < low[v]) {
         low[v] = min;
         return;
      }
      do {
         id[i = desempilha()] = numcomp;
         low[i] = n;
      } while (i != v);
      numcomp++;
   }
   int main(int argc, char **argv) {
      int i, j, m;
      while (scanf("%d %d", &n, &m), n || m) {
         for (i = 0; i < n; i++) {
            pre[i] = low[i] = id[i] = -1;
         }
         memset(nviz, 0, n * sizeof(int));
         numcomp = cont = 0;
         while (m--) {
            scanf("%d %d", &i, &j);
            i--;
            j--;
            grafo[i][nviz[i]++] = j;
         }
         for (i = n - 1; i >= 0; i--)
            if (pre[i] == -1)
               busca(i);
         printf("Teste %d\n", ++t);
         if (numcomp == 1)
            puts("S");
         else
            puts("N");
         puts("");
      }
      return 0;
   }
