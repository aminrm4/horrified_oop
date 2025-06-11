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
      my_map.resize(maxn);
    // بیمارستان ⇄ کلیسا
    my_map[0].push_back(2);
    my_map[2].push_back(0);

    // کلیسا ⇄ منشن (manschen)
    my_map[2].push_back(9);
    my_map[9].push_back(2);

    // کلیسا ⇄ قبرستان
    my_map[2].push_back(1);
    my_map[1].push_back(2);

    // کلیسا ⇄ موزه
    my_map[2].push_back(6);
    my_map[6].push_back(2);

    // کلیسا ⇄ فروشگاه
    my_map[2].push_back(5);
    my_map[5].push_back(2);

    // آزمایشگاه ⇄ موسسه (ins)
    my_map[3].push_back(4);
    my_map[4].push_back(3);

    // فروشگاه ⇄ موزه
    my_map[6].push_back(5);
    my_map[5].push_back(6);

    // منشن ⇄ موزه
    my_map[6].push_back(9);
    my_map[9].push_back(6);

    // آزمایشگاه ⇄ فروشگاه
    my_map[4].push_back(5);
    my_map[5].push_back(4);

    // منشن ⇄ فروشگاه
    my_map[9].push_back(5);
    my_map[5].push_back(9);

    // منشن ⇄ صومعه (abbey)
    my_map[9].push_back(8);
    my_map[8].push_back(9);

    // قبرستان زیرزمینی (crypt) ⇄ صومعه
    my_map[7].push_back(8);
    my_map[8].push_back(7);

    // فروشگاه ⇄ تئاتر
    my_map[5].push_back(10);
    my_map[10].push_back(5);

    // منشن ⇄ تئاتر
    my_map[9].push_back(10);
    my_map[10].push_back(9);

    // منشن ⇄ اردوگاه (camp)
    my_map[9].push_back(18);
    my_map[18].push_back(9);

    // منشن ⇄ کارگاه (pric)
    my_map[9].push_back(14);
    my_map[14].push_back(9);

    // منشن ⇄ مهمان‌خانه (inn)
    my_map[9].push_back(13);
    my_map[13].push_back(9);

    // تئاتر ⇄ برج
    my_map[10].push_back(11);
    my_map[11].push_back(10);

    // تئاتر ⇄ انبار (barn)
    my_map[10].push_back(15);
    my_map[15].push_back(10);

    // تئاتر ⇄ مهمان‌خانه
    my_map[10].push_back(13);
    my_map[13].push_back(10);

    // تئاتر ⇄ کارگاه
    my_map[10].push_back(14);
    my_map[14].push_back(10);

    // تئاتر ⇄ اردوگاه
    my_map[10].push_back(18);
    my_map[18].push_back(10);

    // برج ⇄ زندان (dunjen)
    my_map[11].push_back(16);
    my_map[16].push_back(11);

    // برج ⇄ پل (duck)
    my_map[11].push_back(12);
    my_map[12].push_back(11);

    // اردوگاه ⇄ غار (cave)
    my_map[18].push_back(17);
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
