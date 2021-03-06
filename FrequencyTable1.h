//
// FrequencyTable1.h
//
//
//    by: Katya Malison
//    date: 11/26/14
//
#ifndef __FREQUENCYTABLE1_H__
#define __FREQUENCYTABLE1_H__

#include <iostream>

#include "WordFreqList.h"

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
  WordFreqList list;
  bool in(string word, WordFreqList runner);
  void insert(string word, WordFreqList runner);
  int frequency(string word, WordFreqList runner);
  int size(WordFreqList runner);
  void get(int n, string *p_word, int *p_frequency, WordFreqList runner);
};
#endif
