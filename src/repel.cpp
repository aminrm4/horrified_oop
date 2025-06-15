#include <iostream>
#include "repel.hpp"
#include "Drakula.hpp"
#include "Invisible_man.hpp"
#include "programm.hpp"
#include  "map1.hpp"
using namespace std;
void repel::play(hero *he, std::vector<hero *> & he_list, monster *mo, std::vector<location *> & loc, std::vector<item *> & it_list, std::vector<monster *> & mo_list, programm & help_obj1)
{

  for (size_t i = 0; i < 2; i++)
  {
    cout << "enter the place want to move:" << endl;
    int id;
    cin>>id;
    if (id<0 || id>18)
    {
      throw invalid_argument("the location does not exist\n");
    }    
    int direct = mo_list[i]->get_loc()->get_loc_relation();
    auto path = help_obj1.bfs(direct, id);
    mo_list[i]->move_to_place(path, 2, loc);
    mo_list[i]->set_loc(loc[id]);//wich one?;
  }
}
