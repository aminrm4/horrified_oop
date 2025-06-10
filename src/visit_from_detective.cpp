#include <iostream>
#include "visit_from_detective.hpp"
#include "map1.hpp"
using namespace std;
void visit_from_detective::play(hero *he, std::vector<hero *> her_list, monster *mon, location *loc, std::vector<item *> item_list, std::vector<monster *> mon_list, std::vector<std::vector<int>> map)
{

    cout << "enter the place for moving the invisible man :" << endl;
    int location_detect;
    cin >> location_detect;
    map1 router = static_cast<map1>(location_detect);
  
    switch (router)
    {   

    case map1::abbey:
        
        break;
    case map1::barn:
        break;
    case map1::cave:
        break;

    case map1::church:
        break;
    case map1::cryptt:
        break;
    case map1::docks:
        break;

    case map1::dungeon:
        break;
    case map1::grave_yard:
        break;
    case map1::hospital:
        break;

    case map1::inn:
        break;
    case map1::institute:
        break;

    case map1::laboratory:
        break;
    case map1::mansion:
        break;
    case map1::museum:
        break;
    case map1::precinct:
        break;
    case map1::shop:
        break;
    case map1::theatre:
        break;
    case map1 ::tower:
        break;
    case map1::camp:
        break;

    default:
        break;
    }
}
