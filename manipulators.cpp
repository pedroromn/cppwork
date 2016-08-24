// manipulators.cpp
// Example: setprecision, fixed, showpoint

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){

  double x, y, z;

  x = 15.674;
  y = 235.73;
  z = 9525.9864;

  cout << fixed << showpoint;

  cout << setprecision(2)
       << "Line 5: setprecision(2)" << endl;
  cout << "Line 6: x = " << x << endl;
  cout << "Line 7: y = " << y << endl;
  cout << "Line 8: z = " << z << endl;

  cout << setprecision(3)
       << "Line 9: setprecision(3)" << endl;
  cout << "Line 10: x = " << x << endl;
  cout << "Line 11: y = " << y << endl;
  cout << "Line 12: z = " << z << endl;

  cout << setprecision(4)
       << "Line 13: setprecision(4)" << endl;
  cout << "Line 14: x = " << x << endl;
  cout << "Line 15: y = " << y << endl;
  cout << "Line 16: z = " << z << endl;

  cout << "Line 17: "
       << setprecision(3) << x << " "
       << setprecision(2) << y << " "
       << setprecision(4) << z << endl;
  
  return 0;
}
