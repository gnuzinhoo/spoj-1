#include <cstdio>
#include <list>
#include <set>
#include<string.h>
#include<stdio.h>
#include <iostream>
   using namespace std; 
   int main(){
      int num, i, *comandos, *vezes, soma, max = 0; 
      scanf( "%i", &num ); 
      while( num != 0 ){
         comandos = (int*) malloc( num * sizeof(int) );
         i = soma = 0; 
         while( i < num ){
            scanf( "%i", &comandos[i] ); 
            if( comandos[i] > max ){
               max = comandos[i];
            } 
            i++;
         } 
         vezes = (int*) malloc( max * sizeof(int) ); 
         for( i = 0; i < max; i++ ){
            vezes[i] = 0;
         } 
         for( i = 0; i < num; i++ ){
            if( vezes[ comandos[i] - 1 ] != 0 ){
               soma += (i + 1 ) - vezes[ comandos[i] - 1 ];
            }
            else{
               soma += comandos[i] + i;
            } 
            vezes[ comandos[i] - 1 ] = i + 1;
         } 
         printf( "%i\n", soma );
         scanf( "%i", &num );
      } 
      return 0;
   }
