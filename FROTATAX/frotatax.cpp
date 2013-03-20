#include <stdio.h>
   int main(){
      float a, g, ra, rg;
      while( scanf( "%f%f%f%f", &a, &g, &ra, &rg ) != EOF ){
         printf( (ra / a) > (rg/g) ? "A\n" : "G\n" );
      }
      return 0;
   } 
