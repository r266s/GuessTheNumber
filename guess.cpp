#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <random>
using namespace std;

int main() {
  bool running = true;
  int picked_number;

  printf("Welcome to the guessing game!\n");
  sleep(1);
  printf("pick a number: ");
  cin >> picked_number;

  random_device device;
  mt19937 gen(device());
  uniform_int_distribution<> rand(1, picked_number);

  int randin = rand(gen);

  while (running) {
    int num;
    printf("Guess from 1 to %d: ", picked_number);
    cin >> num;

    if (num == randin) {
      printf("You guessed it correctly!\n\n");
      running = false;
      break;
    } else if (num > randin) {
      printf("Less.\n");
    } else if (num < randin) {
      printf("More.\n");
    }
  }

  system("pause");
  return 0;
}