#include <stdio.h>
#include <cstdio>
#include <list>
#include <set>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
   int main(){
      int casos;
      scanf( "%d", &casos );
      while( casos-- ){
         char linha[4000], *p;
         int linhas, pos = 0, max = 1000, num, count, lidos, i;
         scanf( "%d", &linhas );
         scanf( "\n" );
         int lug[linhas];
         for( i = 0; i < linhas; i++ ){
            gets( linha );
            p = linha;
            count = 0;
            while( strtol( p, &p, 10 ) ){
               count++;
            }
            if( count < max ){
               lug[0] = i + 1;
               pos = 1;
               max = count;
            } 
            else if( count == max ){
               lug[pos++] = i + 1;
            }
         }
         for( i = 0; i < pos; i++ ){
            printf( "%d ", lug[i] );
         }
         puts("");
      }
      return(0);
   }
