
#ifndef __FREQUENCYTABLE2_H__
#define __FREQUENCYTABLE2_H__

#include <iostream>

#include "WordFreqList.h"

const int ALPHA = 26;

using namespace std;

class FrequencyTable {
 public:
  FrequencyTable();
  bool in(string word);
  void insert(string word);
  int frequency(string word);
  int size();
  void get(int n, string *p_word, int *p_frequency);
  void destroy();
  void all_sizes();
 private:
  WordFreqList list[ALPHA];
  WordFreqList get_list_for_word(string word);
  bool in(string word, WordFreqList runner);
  void insert(string word, WordFreqList runner, int i);
  int frequency(string word, WordFreqList runner);
  int size(WordFreqList runner);
  void get(int n, string *p_word, int *p_frequency, WordFreqList runner);
};
#endif
