//
// FrequencyTable1.cpp
//
//    use: includes definitions of all public and private
//         functions of the class FrequencyTable
//    notes: this file is for version 1 of project 3
//           in order to use functions recursively, many
//           of the public functions have private helper 
//           functions. these helper functions have an 
//           additional parameter of WordFreqList type
//           called runner. runner is used to modify and 
//           search lists without altering the private
//           member variable 'list' of the Frequency Table
//           class. 
//
//    by: Katya Malison
//    date: 11/26/14
//
#include "FrequencyTable1.h"
#include "WordFreqList.h"

using namespace std;

// function name: FrequencyTable
// arguments: none
// use: constructor for FrequencyTable class
// notes: n/a
FrequencyTable::FrequencyTable()
{
  list = empty();
}

// function name: in
// arguments: string
// use: call helper function
// notes: n/a
bool FrequencyTable::in(string word)
{
  return in(word, list);
}

// function name: in
// arguments: string, WordFreqList
// use: check if a given word is included in a given list
// notes: n/a
bool FrequencyTable::in(string word, WordFreqList runner)
{
  if (isEmpty(runner)) { // evaluates to true when a list is empty
    return false;        // or when every node has been checked 
  } else if (first(runner).word == word) {
    return true;
  } else {
    return in(word, rest(runner));
  }
}

// function name: insert
// arguments: string
// use: call helper function
// notes: n/a
void FrequencyTable::insert(string word)
{
  insert(word, list);
}

// function name: insert
// arguments: string, WordFreqList
// use: insert a given word into a given linked list in 
//      correct alphabetical order
// notes: if the given word is already stored in the linked list,
//        the frequency of the word will increase by one, and no
//        other nodes will be created.
void FrequencyTable::insert(string word, WordFreqList runner)
{
  if (isEmpty(runner) or first(runner).word > word) { // true if list is empty 
    list = prepend(word, 1, runner);      // or word is first alphabetically
  } else if (first(runner).word == word) {
    set_freq(first(runner).freq + 1, runner);
  } else if (isEmpty(rest(runner)) or first(rest(runner)).word > word) {
    insertAfter(word, 1, runner);  // true when last non-empty node or when next
  } else {                         // word is after the given word alphabetically
    insert(word, rest(runner));
  } 
}

// function name: frequency
// arguments: string
// use: return value returned by helper function
// notes: n/a
int FrequencyTable::frequency(string word)
{
  return frequency(word, list);
}

// function name: frequency
// arguments: string, WordFreqList
// use: return frequency of given word in a given list
// notes: n/a
int FrequencyTable::frequency(string word, WordFreqList runner)
{
  if (isEmpty(runner)) {
    return 0;
  } else if (first(runner).word == word) {
    return first(runner).freq;
  } else {
    return frequency(word, rest(runner));
  }
}

// function name: size
// arguments: none
// use: return value returned by helper function
// notes: n/a
int FrequencyTable::size()
{
  return size(list);
}

// function name: size
// arguments: WordFreqList
// use: return total number of words in a list
// notes: even if a word has a frequency greater than 1, it 
//        only counts as one word
int FrequencyTable::size(WordFreqList runner)
{
  if (isEmpty(runner)) {
      return 0;
    } else { 
      return 1 + size(rest(runner));
    }
}

// function name: get
// arguments: int, string*, int*
// use: call helper function
// notes: n/a
void FrequencyTable::get(int n, string *p_word, int *p_frequency)
{
  get(n, p_word, p_frequency, list);
}

// function name: get
// arguments: int, string*, int*, WordFreqList
// use: find the nth node in a given list and put the node's word and
//      frequency in the locations pointed to by the given pointers
// notes: 
void FrequencyTable::get(int n, string *p_word, int *p_frequency,
			 WordFreqList runner)
{
  if (n == 0) {
    WordFreq hold = first(runner);
    *p_word = hold.word;
    *p_frequency = hold.freq;
  } 
  else {  // begins at first node, and continues until nth node
    n--;
    get(n, p_word, p_frequency, rest(runner));
  }
}

// function name: destroy
// arguments: none
// use: empty FrequencyTable's linked list  and delete 
//      any associated storage
// notes: n/a
void FrequencyTable::destroy()
{
  if (!isEmpty(list)) {
    list = deleteFirst(list);
    destroy();
  }
}
