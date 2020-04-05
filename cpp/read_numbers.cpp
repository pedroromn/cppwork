#include <iostream>

using namespace std;

int main(){

    int item[5];
    int sum, counter;

    cout << "Enter five numbers: ";
    sum = 0;

    for(counter = 0; counter < 5; counter++){
        cin >> item[counter];
        sum = sum + item[counter];
    }

    cout << "suma => " << sum;
    cout << endl;

    return 0;


}