#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   int ordem(const void *p1, const void *p2){
      int n1, n2;
      n1 = *((int*)p1);
      n2 = *((int*)p2);
      if(n1 < n2){
         return -1;
      }
      else if(n1 > n2){
         return 1;
      }
      return 0;
   }
   int n;
   char buff[200];
   char *putIntAbs(char *s, int n){
      if(n >= 10)
         s = putIntAbs(s, n / 10);
      *s = (n % 10) + '0';
      return s+1;
   }
   char* putint(char *s, int n){
      if(n < 0){
         *s = '-';
         ++s; n = -n;
      }
      if(n){
         s = putIntAbs(s, n);
      }
      else{
         *s = '0';
         ++s;
      }
      *s = ' ';;
      return s+1;
   }
   void faz(int *lista, int N, char *s){
      int mandados[N], i;
      if(N <= 1){
         *s = 0;
         printf("%s%i\n",buff, *lista);
         return;
      }
      for(i = 1; i < N; ++i){ 
         mandados[i - 1] = lista[i]; 
      }
      for(i = 0; i < N; ++i){
         faz(mandados, N-1, putint(s, lista[i]));
         mandados[i] = lista[i];
      }
   }
   int main(){
      int myInts[8];
      int i;
   // qsort(myInts, 20, 4, ordem);
      while(scanf("%i", &n)){
         if(!n)
            return 0;
         for(i = 0; i < n; ++i){
            scanf("%i", myInts + i);
         }
         qsort(myInts, n, 4, ordem);
         memset(buff, 0, 200);
         faz(myInts, n, buff);
      }
      return 0;
   } 
