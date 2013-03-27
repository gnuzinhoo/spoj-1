    #include <stdio.h>
   int main(){
      unsigned int par, num, temp;
      while( scanf( "%d", &num ) ){
         if( !num ){
            return 0;
         }
         temp = 1, par = 0;
         char rep[32], *c = &rep[30];
         while( temp <= num ){
            if( temp & num ){
               *c = '1';
               par++;
            } 
            else{
               *c = '0';
            }
            c--, temp <<= 1;
         }
         printf( "The parity of %s is %d (mod 2).\n", ++c, par );
      }
   } 

