#include <cstdio>
#include <list>
#include <set>
#include<string.h>
#include<stdio.h>
#include <iostream>
   using namespace std;
   int main(){
      int votos;
      while( scanf( "%d", &votos ) ){
         if( !votos ){
            return 0;
         }
         int v[votos], *pv;
         memset( v, '\0', votos * sizeof( int ) );
         int i, j, voto, max = 0;
         for( i = 0; i< votos; i++ ){
            pv = v;
            for( j = 0; j < votos; j++, pv++ ){
               scanf( "%d", &voto );
               *pv += voto;
            }
         }
         pv = v;
         for( i = 0; i < votos; i++, pv++ ){
            if( *pv > max ){
               max = *pv;
            }
         }
         printf( "%d\n", max );
      }
   }
