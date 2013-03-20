#include <stdio.h>
   int main(){
      int n;
      do{
         scanf( "%d", &n );
         if( n ){
            printf( "f91(%i) = %i\n", n, (n < 101 ) ? 91 : n - 10 );
         }
      } while( n );
   } 
