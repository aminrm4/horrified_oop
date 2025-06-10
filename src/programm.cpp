#include"programm.hpp"
using namespace std;
pair<int,int> programm::random_generator(int start,int end)
{
  srand(time(nullptr));
  int random1=start+rand()%(end-start +1);
  int random2;
  do
  {
    random2=start+rand()%(end-start +1);
  }
   while (random1==random2);
   {
    return{random1,random2};
   }
  
}