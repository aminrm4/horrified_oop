#include"programm.hpp"
#include<iostream>
using namespace std;
int main()
{
    programm obj1;
    auto it =obj1.bfs(10,6);
    for (auto i : it)
    {
        cout<<i<<" ";
    }
    
}