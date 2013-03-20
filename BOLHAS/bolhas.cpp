#include <cstdio>
#include <list>
#include <set>
#include<string.h>
#include<stdio.h>
#include <iostream>
   using namespace std; 
   typedef 
      struct NoAbb{
         int valor, noDir, noEsq, numDir, numEsq;
      } NoAbb; 
   typedef 
      struct Abb{
         NoAbb **vet;
         int numNos;
         int tamanho;
      } Abb; 
   NoAbb node; 
   void populaAbb(Abb *abb, int inicio, int fim, int indice){
      NoAbb *no = (NoAbb*) malloc( sizeof( NoAbb ) ); 
      no->valor = (inicio + fim) / 2; 
      no->numEsq = no->valor - inicio - 1;
      if( fim - inicio != 2 ){
         no->noEsq = 2 * indice + 1;
         populaAbb( abb, inicio, no->valor, no->noEsq );
      } 
      else{
         no->noEsq = 0;
         no->noDir = 0;
         no->numDir = 0;
         abb->vet[indice] = no;
         return;
      } 
      if( no->valor < abb->numNos ){
         if( fim > abb->numNos ){
            no->numDir = abb->numNos - no->valor;
         } 
         else{
            no->numDir = fim - no->valor - 1;
         } 
         no->noDir = 2 * indice + 2;
         populaAbb( abb, no->valor, fim, no->noDir );
      } 
      else {
         no->noDir = 0;
         no->numDir = 0;
      } 
      abb->vet[indice] = no;
   } 
   Abb *criaAbb( int numNos){
      Abb *abb = (Abb*) malloc( sizeof( Abb ) );
      abb->numNos = numNos; 
      int raiz = 1; 
      while( numNos != 1 ){
         raiz <<= 1;
         numNos >>= 1;
      } 
      abb->vet = (NoAbb**) malloc( raiz * 2 * sizeof( NoAbb*) );
      abb->tamanho = 2 * raiz;
      memset( abb->vet, '\0', abb->tamanho * sizeof( NoAbb*) ); 
      if( raiz != 1 ){
         populaAbb( abb, 0, abb->tamanho, 0 );
      } 
      else{
         NoAbb *no = (NoAbb*) malloc( sizeof( NoAbb ) );
         no->valor = 1;
         no->numDir = 0;
         no->numEsq = 0;
         no->noEsq = 0;
         no->noDir = 0; 
         abb->vet[0] = no;
      } 
      return abb;
   } 
   int acessaElemento( Abb* abb, int elemento, int indice, int nos ){
      NoAbb *no = abb->vet[indice];
      int valor = (no->valor != 0) + no->numEsq + nos; 
      if( elemento == valor && no->valor && no->valor <= abb->numNos ){
         int oldValue = no->valor;
         no->valor = 0;
         return oldValue - 1;
      } 
      else if( elemento <= valor ){
         no->numEsq--;
         return acessaElemento( abb, elemento, 2*indice + 1, nos);
      } 
      else{
         no->numDir--;
         return acessaElemento( abb, elemento, 2*indice + 2, valor);
      }
   } 
   void destroiAbb( Abb **abb ){
      int i; 
      for( i = 0; i < (*abb)->tamanho; i++ ){
         free( (*abb)->vet[i] );
      } 
      free( *abb );
   } 
   int main(){
      int numeros, trocas; 
      while( scanf( "%d%d", &numeros, &trocas ) ){
         if( !numeros ){
            return 0;
         } 
         Abb *abb = criaAbb(numeros);
         int i = 0, j = 0, numero, v[numeros];
         memset( v, '\0', numeros * sizeof( int ) );
         for( ;i < trocas; i++ ){
            scanf( "%d", &numero );
            v[ acessaElemento(abb, numero + 1, 0, 0 ) ] = i + 1;
         } 
         for( ; j < numeros; j++ ){
            if( !v[j] ){
               v[j] = ++i;
            } 
            printf( "%d ", v[j] );
         } 
         printf( "\n" ); 
         destroiAbb( &abb );
      } 
      return 0;
   }
