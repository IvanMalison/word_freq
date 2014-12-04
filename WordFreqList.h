//
// WordFreqList.h
//
//    use: header file for WordFreqList struct and
//         functions
//    notes: for submission 1 of project 3
//
//    by: Katya Malison
//    date: 11/23/14
//
#ifndef __WORDFREQLIST_H__
#define __WORDFREQLIST_H__

#include <iostream>

using namespace std;
// WordFreq: representation of a word and frequency pair
struct WordFreq {
  int freq;
  string word;
};
// WordFreqListNode: representation of a WordFreqList 
struct WordFreqListNode {
  WordFreq data;
  WordFreqListNode *next;
};

typedef WordFreqListNode *WordFreqList;

WordFreqList empty();
bool isEmpty(WordFreqList list);
WordFreqList prepend(string new_word, int new_freq, WordFreqList list);
WordFreq first(WordFreqList list);
WordFreqList rest(WordFreqList list);
WordFreqList deleteFirst(WordFreqList list);
void insertAfter(string new_word, int new_freq, WordFreqList list);
void set_freq(int new_freq, WordFreqList list);

#endif

