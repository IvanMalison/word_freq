//
// FrequencyTable1.cpp
//
//    by: Katya Malison
//    date: 11/26/14
//
#include "FrequencyTable1.h"
#include "WordFreqList.h"

using namespace std;

FrequencyTable::FrequencyTable()
{
  list = empty();
  copy = list;
}
bool FrequencyTable::in(string word)
{
  if (isEmpty(copy)) {
    return false;
  } else if (first(copy).word == word) {
    reset();
    return true;
  } else {
    copy = rest(copy);
    return in(word);
  }
}
void FrequencyTable::insert(string word)
{
  insert(word, list);
}
void FrequencyTable::insert(string word, WordFreqList runner)
{
  //  list = prepend(word, 1, list);
  if (isEmpty(runner) or first(runner).word > word) {
    list = prepend(word, 1, runner);
  } else if (first(runner).word == word) {
    set_freq(first(runner).freq + 1, runner);
  } else if (isEmpty(rest(runner)) or first(rest(runner)).word > word) {
    insertAfter(word, 1, runner);
  } else {
    insert(word, rest(runner));
  }
 
}

void FrequencyTable::print()
{
  cout << "{"<< " ";
  print(list);
  cout << "}" << endl;
}

void FrequencyTable::print(WordFreqList runner)
{
  if (!isEmpty(runner)) {
    WordFreq hold = first(runner);
    cout << hold.freq << " " << hold.word << ", ";
    print(rest(runner));
  }
}
WordFreqList FrequencyTable::reset()
{
  WordFreqList temp = copy;
  copy = list;
  return temp;
}

//int FrequencyTable::frequency(string word)
//{

//}
int FrequencyTable::size()
{
  return size(list);
}
int FrequencyTable::size(WordFreqList runner)
{
  return isEmpty(runner) ? 0 : 1 + size(rest(runner));
}

void FrequencyTable::get(int n, string *p_word, int *p_frequency)
{
  get(n, p_word, p_frequency, list);
}

void FrequencyTable::get(int n, string *p_word, int *p_frequency,
			 WordFreqList runner)
{
  if (n == 0) {
    WordFreq hold = first(runner);
    *p_word = hold.word;
    *p_frequency = hold.freq;
  }
}

void FrequencyTable::destroy()
{

}
