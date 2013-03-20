#include <cstdio>
#include <list>
#include <set>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#define LIM 1000001
   int primos[LIM];
   int main(){
      int i, j; 
      for( i = 1; i < LIM;i++ ){
         primos[i] = i% 2;
      }
      primos[1] = 0;
      primos[2] = 1; 
      for( i = 3; i < LIM; i+=2 ){
         if( primos[i] && i < (1 << 15 ) ){
            for( j = i*i; j < LIM; j += i ){
               primos[j] = 0;
            }
         }
      } 
      int num; 
      while( scanf( "%d", &num ) ){
         if( !num ){
            return 0;
         } 
         i = 2;
         int n = 0, numero = num, retido = 0; 
         while( i <= 1001 && i <= numero ){
            if( (numero % i == 0) && primos[i] ){
               numero /= i;
            //printf( "%d %d\n",numero, i );
               if( !retido ){
                  n++;
               }
               retido = 1;
            }
            else{
               retido = 0;
               i++;
            }
         } 
         if( primos[numero] ){
            n++;
         } 
         printf( "%d : %d\n", num, n );
      }
      return(0);
   }
