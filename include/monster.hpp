#pragma once
#include <vector>
class location;
class hero;
#include<string>
class monster
{
    protected:
    bool is_freenzy;
    int freenzy_order;
    location* loc;
    std::string name_of_monster;

    public:
    virtual void ability(std::vector <int> & route, std::vector<location*> & locations , hero* h) = 0;
    bool get_freenzy_status();
    void move_to_place(std::vector <int> & route , int number_route , std::vector<location*> & locations);
    void set_loc(location* );
    location* get_loc();
    bool get_is_frenzy();
    int get_frenzy_order();
    void set_is_frenzy(bool);
    void set_frenzy_order(int);
    std::string get_mons_name();
    
};