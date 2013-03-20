#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <inttypes.h> 
#include <ctype.h> 
#include <algorithm> 
#include <utility> 
#include <iostream> 
#include <map> 
#include <set> 
#include <vector> 
#include <sstream> 
   using namespace std; 
   int fatorial[1000001]; 
   int mpow(int a, int b, int n = 10) 
   { 
      if(b == 0) 
         return 1; 
      else { 
         long long res = mpow(a, b/2, n); 
         res = (res*res) % n; 
         if(b%2 == 1) 
            res = (res*a) % n; 
         return (int) res; 
      } 
   } 
   int main() 
   { 
      int n, h = 1; 
      int x = 1; 
      int t = 0, f = 0; 
      std::cout.sync_with_stdio(false); 
      fatorial[0] = 1; 
      for (int i = 1; i <= 1000001; i++) 
      { 
         int k = i; 
         while (k % 2 == 0) { k /= 2; t++; } 
         while (k % 5 == 0) { k /= 5; f++; } 
         if (t > f) { 
            t-= f; 
            f = 0; 
         } 
         else { 
            f-= t; 
            t = 0; 
         } 
         x = (x*k)%10; 
         fatorial[i] = (x * mpow(2, t) * mpow(5, f))%10; 
      } 
      while (cin >> n) 
      { 
         cout << "Instancia " << h++ << endl; 
         cout << fatorial[n] << endl << endl; 
      } 
      return 0; 
   }
