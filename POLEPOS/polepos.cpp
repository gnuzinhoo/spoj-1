    #include<iostream>
    #include<vector>
     
   using namespace std;
     
   int main() {
      int cars;
      cin >> cars;
      while(cars) {
         vector<int> pole(cars);
         bool no = false;
         for(int i=0; i<cars; ++i) {
            int c,p;
            cin >> c >> p;
            if(i+p>=0 && i+p<cars) {
               if(pole[i+p]==0) pole[i+p] = c;
               else no = true;
            }
            else no = true;
         }
         if(no) cout << "-1" << endl;
         else {
            cout << pole[0];
            for(int i=1; i<cars; ++i) {
               cout << " " << pole[i];
            }
            cout << endl;
         }
         cin >> cars;
      }
      return 0;
   }

