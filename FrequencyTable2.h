
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
 private:
  WordFreqList list[ALPHA];
  bool in(string word, WordFreqList runner);
  void insert(string word, WordFreqList runner);
  int frequency(string word, WordFreqList runner);
  int size(WordFreqList runner);
  void get(int n, string *p_word, int *p_frequency, WordFreqList runner);
};
#endif
