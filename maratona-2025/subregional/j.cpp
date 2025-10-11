#include <iostream>
using namespace std;
#include <vector>
int main()
{
   bool existe[4] = {false, false, false, false};
   int d;
   
   for(int i = 0; i < 10; i++){
       cin >> d;
       existe[d - 1] = true;
   }
   
   int distintos = 0;
   for(int i = 0; i < 4; i++){
       if(existe[i]) distintos++;
   }
   cout << 4 - distintos;

    return 0;
}