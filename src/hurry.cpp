#include<iostream>
#include"hurry.hpp"
#include"programm.hpp"
    void hurry:: play (hero *he, std::vector<hero *> he_list, monster *mo, std::vector<location *> loc, std::vector<item *> it_list, std::vector<monster *> mo_list, programm help_obj1)
    {
        programm help_obj1;
        for (size_t i = 0; i <2; i++)
        {
             int direct=he_list[i]->get_loc()->get_loc_relation();
             help_obj1.bfs(direct,direct+2);//aya hamvare hast?

                //he_list[i]->move()
        }
        
    }
