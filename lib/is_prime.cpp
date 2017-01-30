#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

long int get_time() {
  long int epoch = static_cast<long int> (time(NULL));
  struct tm * currentTime;

  currentTime = localtime(&epoch);
  cout << asctime(currentTime) << endl;
  return epoch;
}

int main(){
  long int startTime;
  long int endTime;
  int mod, num, count, e;

  cout << "Enter a number to check is prime:" << endl;
  cin >> num;

  cout << "Start time: " << endl;
  startTime = get_time();
  for (count = 2; count <= num - 1; count++) {
    mod = num % count;
    cout << num << " mod " << count << " = " << mod << endl;
    if (mod == 0 && num != count) {
      cout << "Sorry, " << num << " is not prime." << endl;
      break;
    }
  }
  if (num == count){
    cout << "Winner, Winner! Chicken Dinner!: " << num << endl;
  }
  cout << "End time: ";
  endTime = get_time();
  double totalTime = difftime(mktime(localtime(&endTime)),mktime(localtime(&startTime)));
  cout << "Operation time: " << totalTime << " seconds!" << endl;
  return 0;
}
