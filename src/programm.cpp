#include "programm.hpp"
using namespace std;
#include <bits/stdc++.h>
set<int> programm::random_generator(int start, int end, int count)
{
  set<int> my_random;
  srand(time(nullptr));
  if (start - end + 1 < count)
  {
    throw logic_error("cant generate the random numbers \n");
  }

  while (count != my_random.size())
  {
    int random1 = start + rand() % (end - start + 1);
    my_random.insert(random1);
  }
  return my_random;
}
programm::programm()
{
  my_map[0].push_back(2); // hospital to church
  my_map[2].push_back(0);
  my_map[2].push_back(9); // church to manschen
  my_map[9].push_back(2);
  my_map[2].push_back(1); // church to graveyard
  my_map[1].push_back(2);
  my_map[2].push_back(6); // church to museum
  my_map[6].push_back(2);
  my_map[2].push_back(5); // church to shop
  my_map[5].push_back(2);
  my_map[3].push_back(4); // lab to ins
  my_map[4].push_back(3);
  my_map[6].push_back(5); // shop to museum
  my_map[5].push_back(6);
  my_map[6].push_back(9); // man to mus
  my_map[9].push_back(6);
  my_map[4].push_back(5); // lab to shop
  my_map[5].push_back(4);
  my_map[9].push_back(5); // man to shop
  my_map[5].push_back(9);
  my_map[9].push_back(8); // man to abbey
  my_map[8].push_back(9);
  my_map[7].push_back(8); // crypt to abbey
  my_map[8].push_back(7);
  my_map[5].push_back(10); // shop to theater
  my_map[10].push_back(5);
  my_map[9].push_back(10); // man to the
  my_map[10].push_back(9);
  my_map[9].push_back(18); // man to camp
  my_map[18].push_back(9);
  my_map[9].push_back(14); // man to pric
  my_map[14].push_back(9);
  my_map[9].push_back(13); // man to inn
  my_map[13].push_back(9);
  my_map[10].push_back(11); // theat to tower
  my_map[11].push_back(10);
  my_map[10].push_back(15); // theater to barn
  my_map[15].push_back(10);
  my_map[10].push_back(13); // ther to inn
  my_map[13].push_back(10);
  my_map[10].push_back(14); // ther to price
  my_map[14].push_back(10);
  my_map[10].push_back(18); // ther to camp
  my_map[18].push_back(10);
  my_map[11].push_back(16); // tower to dunjen
  my_map[16].push_back(11);
  my_map[11].push_back(12); // tower to duck
  my_map[12].push_back(11);
  my_map[18].push_back(17); // camp to cave
  my_map[17].push_back(18);
}
std::vector<int> programm::bfs(int s, int t)
{
  bool vis[maxn];
  int par[maxn];
  int dis[maxn];
  fill(dis, dis + 20, -1);
  fill(vis, vis + 20, false);
  fill(par, par + 20, -1);
  queue<int> q;
  q.push(s);
  vis[s] = true;
  dis[s] = 0;
  bool found = false;
  while (!q.empty() && !found)
  {
    int u = q.front();
    q.pop();
    for (int v : my_map[u])
    {
      if (!vis[v])
      {
        vis[v] = true;
        par[v] = u;
        dis[v] = dis[u] + 1;
        if (v == t)
        {
          found = true;
          break;
        }
        q.push(v);
      }
    }
  }

  if (!vis[t])
  {
    throw invalid_argument("the path does not exist\n");
  }
  else
  {
    vector<int> path;
    for (int v = t; v != -1; v = par[v])
      path.push_back(v);
    reverse(path.begin(), path.end());

    return path;
  }
}
