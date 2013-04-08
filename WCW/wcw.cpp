#include <iostream>
#include <vector>
   using namespace std;
   int main()
   {
      int T, N, i, n, aux;
      vector<int> vetor;
      vetor.reserve(10001);
      for (cin >> T; T; T--)
      {
         cin >> N;
         for(i=1; i<=N; i++)
            cin >> vetor[i];
         n = 0;
         i = 1;
         while(i<N)
         {
            if (vetor[i] != i)
            {
               n++;
               aux = vetor[vetor[i]];
               vetor[vetor[i]] = vetor[i];
               vetor[i] = aux;
            }
            else
               i++;
         }
         cout << n << endl;
      }
      return 0;
   }
