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
  void print();
  int frequency(string word);
  int size();
  void get(int n, string *p_word, int *p_frequency);
  void destroy();
 private:
  WordFreqList list;
  WordFreqList copy;
  WordFreqList reset();
  void insert(string word, WordFreqList runner);
  void print(WordFreqList runner);
  int size(WordFreqList runner);
  void get(int n, string *p_word, int *p_frequency, WordFreqList runner);
};
#endif
