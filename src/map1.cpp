#include"map1.hpp"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 std::ostream & operator<<( std::ostream & output,map1 &obj1)
 {
    
    switch (obj1)
    {   

    case map1::abbey:
    output<<"abbey";
        break;
    case map1::barn:
    output<<"barn";
        break;
    case map1::cave:
    output<<"cave";
        break;

    case map1::church:
    output<<"church";
        break;
    case map1::cryptt:
    output<<"cryptt";
        break;
    case map1::docks:
    output<<"docks";
        break;

    case map1::dungeon:
    output<<"dungeopn";
        break;
    case map1::grave_yard:
    output<<"grave_yard";
        break;
    case map1::hospital:
    output<<"hospital";
        break;

    case map1::inn:
    output<<"inn";
        break;
    case map1::institute:
    output<<"institute";
        break;

    case map1::laboratory:
    output<<"laboratory";
        break;
    case map1::mansion:
    output<<"mansion";
        break;
    case map1::museum:
    output<<"museum";
        break;
    case map1::precinct:
    output<<"precinct";
        break;
    case map1::shop:
    output<<"shop";
        break;
    case map1::theatre:
    output<<"theatre";
        break;
    case map1 ::tower:
    output<<"tower";
        break;
    case map1::camp:
    output<<"camp";
        break;
        default:
        throw invalid_argument("the location does not exist \n");
        
    }
    return output;
    
 }
  