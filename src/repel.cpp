#include<iostream>
#include"repel.hpp"
#include"Drakula.hpp"
#include"Invisible_man.hpp"
#include"programm.hpp"
using namespace std;
     void repel:: play(hero * he, std::vector<hero *> he_list, monster * mo,std:: vector<location *> loc, std::vector<item *>it_list, std::vector<monster *>mo_list, std::vector<std::vector<int>>road)
     {      
        programm help_obj1;
        
            for(size_t i=0;i<2;i++)
            {
                int direct=mo_list[i]->get_loc()->get_loc_relation();
              auto path=help_obj1.bfs(direct,direct+2);//aya in hamishe rah dare?
                mo_list[i]->move_to_place(path,path.size(),loc);
            
            }
        
        
        
        
     }
