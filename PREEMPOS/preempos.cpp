


#include <cstdio>

#include <iostream>

#include <string>
 

   using namespace std;
 

   string analisar( string pre, string pos ){
   
      int antes = 0, depois = 0, tam = pre.length();
   
   
      for( antes = 0; pos[antes] != pre[0]; antes++ );
   
      depois = tam - antes - 1;
   
   
      return ( ( antes == 0 ) ? "" : analisar( pre.substr( 1, antes ), pos.substr( 0, antes ) ) ) +
         
         ( ( depois == 0 ) ? "" : 
         
            analisar( pre.substr( 1 + antes, depois ), pos.substr( 1 + antes, depois ) ) ) +
         
            pre.substr(0,1) ;
   
   }
 

   int main(){
   
      int casos, tamanho;
   
      string str1, str2;
   
      scanf( "%d", &casos );
   
   
      while( casos-- ){
      
         scanf( "%d", tamanho );
      
      
         cin >> str1 >> str2;
      
         cout << analisar( str1, str2 )<< endl;
      
      
      }
   
   
      return 0;
   
   }