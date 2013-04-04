#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
   int main(){
      int soma, grau, i;
      char c, num[1000], a;
      scanf( "%c", &c );
      while( c != '0' ){
         soma = grau = i = 0;
         soma += c - '0';
         num[i++] = c;
         scanf( "%c", &c );
         while( isdigit( c ) ){
            soma += c - '0';
            num[i++] = c;
            scanf( "%c", &c );
         }
         num[i] = '\0';
         if( soma % 9 == 0 ){
            grau++;
            while( soma != 9 ){
               soma = soma % 10 + soma % 100 / 10 + soma % 1000 / 100 + soma / 1000;
               grau++;
            };
            printf( "%s is a multiple of 9 and has 9-degree %i.\n", num, grau );
         }
         else{
            printf( "%s is not a multiple of 9.\n", num);
         }
         scanf( "%c", &c );
      };
      return 0;
   } 
