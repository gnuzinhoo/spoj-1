#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   int div1500( char *c, int tam ){
      int num = 0, i;
      for( i = 0; i < tam; i++, c++ ){
         num = (num * 10 + *c - '0') %1500; 
      }
      return num;
   }
   int main(){
      int casos, n;
      char *c = (char*) malloc( 1000001 );
      scanf( "%d", &casos );
      short fib[1501];
      short a = 0, b = 1, i = 0;
      short temp;
      for(; i < 1501; i++ ){
         fib[i] = b;
         temp = b;
         b = (b + a) % 1000;
         a = temp;
      }
      while( casos-- ){
         scanf( "%s", c );
         temp = div1500( c, strlen(c) );
         printf( "%03d\n", fib[temp - 1] );
      }
      return 0;
   } 
