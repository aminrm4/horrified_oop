#pragma once
#include <vector>
class location;
class hero;
#include <string>
class programm;
class monster
{
protected:
    bool is_freenzy;
    int freenzy_order;
    location *loc;
    std::string name_of_monster;
    int totla_hidden_item;
    bool did_attack = false;

public:
    virtual void ability(programm &bug) = 0;
    bool get_freenzy_status();
    void move_to_place(std::vector<int> &route, int number_route, programm &bug);
    void set_loc(location *);
    location *get_loc();
    bool get_is_frenzy();
    int get_frenzy_order();
    void set_is_frenzy(bool);
    void set_frenzy_order(int);
    std::string get_mons_name();
    int &get_hidden_item();
    bool get_did_attack();
    void set_did_attack(bool did_attack);
    void save_game(const std::string);
    void load_game(std::string, programm &);

    ~monster();
};