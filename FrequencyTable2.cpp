//
// FrequencyTable2.cpp
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
#include "FrequencyTable2.h"
#include "WordFreqList.h"

using namespace std;

// function name: FrequencyTable
// arguments: none
// use: constructor for FrequencyTable class
// notes: n/a
FrequencyTable::FrequencyTable()
{
  for (int n = 0; n < ALPHA; n++) list[n] = empty();
}

WordFreqList FrequencyTable::get_list_for_word(string word)
{
  return list[((int) word[0]) - 97];
}

// function name: in
// arguments: string
// use: call helper function
// notes: n/a
bool FrequencyTable::in(string word)
{
  return in(word, get_list_for_word(word));
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
  insert(word, get_list_for_word(word), ((int) word[0]) - 97);
}

// function name: insert
// arguments: string, WordFreqList
// use: insert a given word into a given linked list in 
//      correct alphabetical order
// notes: if the given word is already stored in the linked list,
//        the frequency of the word will increase by one, and no
//        other nodes will be created.
void FrequencyTable::insert(string word, WordFreqList runner, int i)
{
  if (isEmpty(runner) or first(runner).word > word) { // true if list is empty 
    list[i] = prepend(word, 1, runner);      // or word is first alphabetically
  } else if (first(runner).word == word) {
    set_freq(first(runner).freq + 1, runner);
  } else if (isEmpty(rest(runner)) or first(rest(runner)).word > word) {
    insertAfter(word, 1, runner);  // true when last non-empty node or when next
  } else {                         // word is after the given word alphabetically
    insert(word, rest(runner), i);
  } 
}

// function name: frequency
// arguments: string
// use: return value returned by helper function
// notes: n/a
int FrequencyTable::frequency(string word)
{
  return frequency(word, get_list_for_word(word));
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
  int sum = 0;
  
  for (int n = 0; n < ALPHA; n++) {
    sum += size(list[n]);
  }
  return sum;
}

void FrequencyTable::all_sizes()
{
  
  for (int n = 0; n < ALPHA; n++) {
    cout << size(list[n]) << endl;
  }
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
  int sum_thus_far = 0;
  int list_start = 0;
  int i = 0;

  while (sum_thus_far <= n) {
    list_start = sum_thus_far;
    sum_thus_far += size(list[i]);
    i++;
  }

  get(n - list_start, p_word, p_frequency, list[i-1]);
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
  for (int n = 0; n < ALPHA; n++) {
    while (!isEmpty(list[n])) {
      list[n] = deleteFirst(list[n]);
    }
  }
}
