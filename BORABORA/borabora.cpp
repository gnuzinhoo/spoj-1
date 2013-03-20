#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#define vc vector<Card> 
   using namespace std;
   struct Card {
      int rank;
      char suite;
   };
// Return true if card a is greater than card b, decreasing order
   bool cmp(Card a, Card b) {
      return (a.rank > b.rank || (a.rank == b.rank && a.suite > b.suite));
   }
   int main() {
      int P, M, N, i, j, r, s, dir, cur_player;
      char c;
      Card cd, d, top_card;
      while(cin >> P >> M >> N) {
         if(P + M + N == 0) 
            break;
         vector<vc> players(P);
         for(i=0; i<P; i++) {
            for(j=0; j<M; j++) {
               cin >> cd.rank >> cd.suite;
               players[i].push_back(cd);
            }
            sort(players[i].begin(), players[i].end(), cmp);
         }
      //The topmost Card 
         cin >> top_card.rank >> top_card.suite;
         list<Card> stock;
         for(i=1; i<(N-(P*M)); i++) {
            cin >> cd.rank >> cd.suite;
            stock.push_front(cd); 
         }
         int turno = 1;
         cur_player = P-1; 
         dir = 1;
         bool discarded = true;
         if(top_card.rank == 12) { 
            cur_player = 1;
            dir = -1;
         }
         while(true) { //begin game
            cur_player = cur_player + dir;
            if(cur_player == -1) cur_player = (P-1);
            if(cur_player == P) cur_player = 0;
            if(top_card.rank == 7 && discarded) {// draw two cards from the stock, misses his turn
               discarded = false;
               if(stock.size() > 0) {
                  d = stock.back(); 
                  stock.pop_back();
                  players[cur_player].push_back(d);
               }
               if(stock.size() > 0) {
                  d = stock.back(); 
                  stock.pop_back();
                  players[cur_player].push_back(d);
               }
               sort(players[cur_player].begin(), players[cur_player].end(), cmp);
               continue;
            } 
            if(top_card.rank == 1 && discarded) {// draw one card from the stock, misses his turn
               discarded = false;
               if(stock.size() > 0) {
                  d = stock.back(); 
                  stock.pop_back();
                  players[cur_player].push_back(d);
               }
               sort(players[cur_player].begin(), players[cur_player].end(), cmp);
               continue;
            } 
            if(top_card.rank == 11 && discarded) {// misses his turn
               discarded = false;
               continue;
            } 
            bool discard = false; 
         // Buscar una carta para votar
            vc::iterator it;
            for(it = players[cur_player].begin(); it != players[cur_player].end(); it++) {
               if((*it).rank == top_card.rank || (*it).suite == top_card.suite) { // ahora top_card sera esta
                  discarded = true;
                  top_card = (*it);
                  players[cur_player].erase(it);
                  discard = true;
                  break;
               }
            } 
            if(!discard) {
               if(stock.size() > 0) {
                  d = stock.back(); // Recuperar el ultimo elemento de stock
                  stock.pop_back();
                  if(d.rank == top_card.rank || d.suite == top_card.suite) {
                     discarded = true;
                     top_card = d;
                  } 
                  else {
                     players[cur_player].push_back(d);
                     sort(players[cur_player].begin(), players[cur_player].end(), cmp);
                  }
               }
            }
            if(top_card.rank == 12 && discarded) {
               discarded = false;
               dir = ((dir == 1)? -1:1);
            }
            if(players[cur_player].size() == 0) {
               cout << (cur_player + 1) << endl;
               break;
            }
         } 
      }
      return 0;
   }
