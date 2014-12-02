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
  if (isEmpty(copy) or first(copy).word > word) {
    prepend(word, 1, copy);
    list = copy;
    reset();
  } else if (first(copy).word == word) {
    set_freq(first(copy).freq + 1, copy);
    reset();
  } else if (isEmpty(rest(copy)) or first(rest(copy)).word > word) {
    insertAfter(word, 1, copy);
    reset();
  } else {
    copy = rest(copy);
    insert(word);
  }
}
void FrequencyTable::print()
{
  WordFreq hold;

  cout << "{";
  while (!isEmpty(copy)) {
    hold = first(copy);
    cout << hold.freq << " " << hold.word << ", ";
    copy = rest(copy);
  }
  cout << "}";

  reset();
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
//int FrequencyTable::size()
//{

//}
//void FrequencyTable::get(int n, string *p_word, int *p_frequency)
//{

//}
//void FrequencyTable::destroy()
//{

//}


