//
// wfltest.cpp
//
//   use: test functions in WordFreqList.cpp
//   notes: for submission one of project 3
//
//   by: Katya Malison
//   date: 11/23/14
//
#include <iostream>

#include "WordFreqList.h"

using namespace std;

void explain_commands();
void command_loop(WordFreqList list);
string get_command();
void insert_cmd();

int main()
{
  WordFreqList list = empty();

  explain_commands();

  command_loop(list);

  return 0;
}
// command_loop: run loop to execute functions
void command_loop(WordFreqList list)
{
  string cmd, word;
  int freq;

  while ((cmd = get_command()) != "quit") {
    if (cmd == "print") {
      print(list);
      cout << endl;
    } else if (cmd == "prepend") {
      cout << "Enter frequency, then word: ";
      cin >> freq >> word;
      list = prepend(word, freq, list);
    } else if (cmd == "delete") {
      list = deleteFirst(list);
    } else if (cmd == "insert") {
      cout << "Enter frequency, then word: ";
      cin >> freq >> word;
      insertAfter(word, freq, list);
    } else if (cmd == "change#") {
      cout << "Enter frequency: ";
      cin >> freq;
      set_freq(freq, list);
    }
  }
}
// get_command: get command from user
string get_command(void)
{
  string cmd;

  cout << "do what? ";
  cin >> cmd;

  return cmd;
}
// explain_commands: give user a guide of commands
void explain_commands()
{
  cout << "Command options:" << endl
       << "prepend" << endl
       << "insert" << endl
       << "delete" << endl
       << "change#" << endl
       << "print" << endl
       << "quit" << endl;
}
