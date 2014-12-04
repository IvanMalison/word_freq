//
// wordfreq.cpp
//
//    use: parse and print the words from standard input
//    notes: for submission 1 of project 3
//
//    by: Katya Malison
//    date: 11/23/14
//
#include <iostream>

#include "FrequencyTable.h"

FrequencyTable insert_word(FrequencyTable mytable, string holder);
void print_words(FrequencyTable mytable);
void test_destroy(FrequencyTable mytable);
void test_frequency(FrequencyTable mytable);
void test_in(FrequencyTable mytable);

using namespace std;

int main()
{
  string holder;
  FrequencyTable mytable;

  while (cin >> holder) {
    mytable = insert_word(mytable, holder);
  }

  print_words(mytable);
  
  mytable.destroy();

  return 0;
}

FrequencyTable insert_word(FrequencyTable mytable, string holder)
{
  if (isalpha(holder[0])) {
    for (int i = 0; i < (int) holder.length(); i++) {
      holder[i] =  tolower(holder[i]);
    }
    mytable.insert(holder);
  }
  return mytable;
}

void print_words(FrequencyTable mytable)
{
  for (int n = 0; n < mytable.size(); n++) {
    int *p_freq = new int;
    string *p_word = new string;
    mytable.get(n, p_word, p_freq);
    cout << *p_freq << " " << *p_word << endl;
    delete p_freq;
    delete p_word;
  }
}

void test_destroy(FrequencyTable mytable)
{
  cout << mytable.size() << endl;

  mytable.destroy();

  cout << mytable.size() << endl;
}

void test_frequency(FrequencyTable mytable)
{
  cout << mytable.frequency("the") << endl;
}

void test_in(FrequencyTable mytable)
{
  if ( mytable.in("the")) {
    cout << "Word is in the table" << endl;
  } else {
    cout << "Word is not in the table" << endl;
  }
}
