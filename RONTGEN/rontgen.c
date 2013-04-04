#include <stdio.h>
#include<string.h>
   int main(){
      int casos;
      scanf( "%d", &casos );
      int vezes, n;
      char *p, *p2, *q;
      while( casos-- ){
         char *t = (char*) malloc( 2000001 );
         char *v = (char*) malloc( 2000001 );
         scanf( "%s%d", t, &vezes );
         printf( "%s\n", t );
         while( vezes-- ){
            q = v - 1;
            p = p2 = t;
            n = 0;
            while( *p2 ){
               if( *p != *p2){
                  *++q = n + '0';
                  *++q = *p;
                  p = p2;
                  n = 0;
               }
               n++;
               p2++;
            }
            *++q = n + '0';
            *++q = *p;
            *++q = 0;
            printf( "%s\n", v );
            strcpy( t, v);
         }
         printf( "\n" );
      }
      return 0;
   } 
