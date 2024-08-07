#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <random>
using namespace std;

bool CheckIfnumber(string number) {
  bool isint;

  for (int i = 0; i < number.length(); i++)
  if (isdigit(number[i])) {
    isint = true;
  } else {
    isint = false;
  }

  return isint;
}


int main() {
  bool running = false;
  string picked_number_str;
  int picked_number_int;

  printf("Welcome to the guessing game!\n");
  sleep(1);
  
  while (true) {
    printf("pick a number: ");
    cin >> picked_number_str;

    if (CheckIfnumber(picked_number_str)) {
      picked_number_int = stoi(picked_number_str);
      running = true;
      break;
    } else {
      printf("Thats not a number!\n");
    }
  }

  random_device device;
  mt19937 gen(device());
  uniform_int_distribution<> rand(1, picked_number_int);

  int randin = rand(gen);

  while (running) {
    string strr;
    int num;
    
    printf("Guess from 1 to %d: ", picked_number_int);
    cin >> strr;

    if (CheckIfnumber(strr)) {
      num = stoi(strr);

      if (num == randin) {
        printf("You guessed it correctly!\n\n");
        running = false;
        break;
      } else if (num > randin) {
        printf("Less.\n");
      } else if (num < randin) {
        printf("More.\n");
      }
    } else {
      printf("Thats not a number!\n");
    }
  }

  system("pause");
  return 0;
}
