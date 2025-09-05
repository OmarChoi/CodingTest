#include <iostream>
using namespace std;
 
int main(void) {
   int a =0, b = 0;
   while(true) {
       cin >> a >> b;
       if(cin.eof() == true) {
           break;
       }
       cout << a + b << endl;
   }
}
