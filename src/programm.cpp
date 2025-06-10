#include"programm.hpp"
using namespace std;
#include<bits/stdc++.h>
set<int> programm::random_generator(int start,int end,int count)
{
  set<int>my_random;
  srand(time(nullptr));
  if (start-end +1<count)
  {
      throw logic_error("cant generate the random numbers \n");
  }
  
  while (count!=my_random.size())
  {
    int random1=start+rand()%(end-start +1);
    my_random.insert(random1);

  }
  return my_random;
}
 programm::programm()
{
  
}