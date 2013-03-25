#include <iostream>
#include <map>
#include <queue>
   using namespace std;
   map <string, int>visitados;
   int main(){
      int animais, numRel;
      while( cin >> animais >> numRel ){
         if( !animais ){
            break;
         }
         string animal;
         for( int i = 0; i < animais; i++ ){
            cin >> animal;
            visitados.insert( pair<string, int>(animal, 0) );
         }
         multimap<string, string> sistema;
         pair<multimap<string,string>::iterator, multimap<string,string>::iterator> res;
      // multimap<string,string>::iterator fst;
         string predador;
         for( int i = 0; i < numRel; i++ ){
            cin >> animal >> predador;
            sistema.insert( pair<string, string>( animal, predador ) );
            sistema.insert( pair<string, string>( predador, animal ) );
         }
         int maior=0;
         queue<string> fila;
         map<string, int>::iterator it2;
         for( map<string, int>::iterator it = visitados.begin(); it != visitados.end(); it++ ){
            int num=0;
            if( !it->second ){
               num=1;
               fila.push(it->first);
               it->second=1;
               while( !fila.empty() ){
                  animal = fila.front();
                  res = sistema.equal_range( animal );
                  for( ; res.first != res.second; res.first++ ){
                     it2 = visitados.find(res.first->second);
                     if( !it2->second ){
                        it2->second = 1;
                        fila.push(it2->first);
                        num++;
                     }
                  }
                  fila.pop();
               }
            }
            if( num > maior ){
               maior = num;
            }
         }
         cout << maior << endl;
         visitados.clear();
      }
      return 0;
   } 
