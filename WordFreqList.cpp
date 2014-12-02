//
// WordFreqList.cpp
//
//   use: contains functions to manipulate WordFreqList 
//        linked lists.
//   notes: for submission one of project 3. contains 
//          temporaru function print()
//
//   by: Katya Malison
//   date: 11/23/14
//
#include <iostream>

#include "WordFreqList.h"

using namespace std;

// empty: return an empty list
WordFreqList empty()
{
  return NULL;
}
// isEmpty: return true if a list is empty. false if not empty
bool isEmpty(WordFreqList list)
{
  return list == NULL;
}
// prepend: return one new list node whose freq is
// new_freq, word is new_word and whose rest is list
WordFreqList prepend(string new_word, int new_freq, WordFreqList list)
{
  WordFreqListNode *p_node = new WordFreqListNode;

  p_node->data.freq = new_freq;
  p_node->data.word = new_word;
  p_node->next = list;

  return p_node;
}
// first: return first freq and word of given list
// it is an error to call first() on an empty list
WordFreq first(WordFreqList list)
{
  return list->data;
}
// rest: return the list of elements after the first node in a list
WordFreqList rest(WordFreqList list)
{
  return list->next;
}
// deleteFirst: delete first node in a list and return the rest
WordFreqList deleteFirst(WordFreqList list)
{
  WordFreqListNode *firstNode = list;
  WordFreqList theRest = rest(list);

  firstNode->next = NULL;

  delete firstNode;
  return theRest;
}
// print: print WordFreqList nodes. For testing use only
void print(WordFreqList list)
{
  WordFreq hold;

  cout << "{";
  while (! isEmpty(list)) {
    hold = first(list);
    cout << hold.freq << " " << hold.word << ", ";
    list = rest(list);
  }
  cout << "}";
}
// insertAfter: insert a new WordFreqList node with given word and 
// frequency after the first node of the given list
void insertAfter(string new_word, int new_freq, WordFreqList list)
{
  list->next = prepend(new_word, new_freq, rest(list));
}
// set_freq: update the frequency of the given node to the given integer
void set_freq(int new_freq, WordFreqList list)
{
  list->data.freq = new_freq;
}
  
