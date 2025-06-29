#include "hero.hpp"
#include <stdexcept>
#include <typeinfo>
#include <algorithm>
#include "Drakula.hpp"
#include "Invisible_man.hpp"
#include "programm.hpp"
#include <iterator>
#include "location.hpp"
#include "Color.hpp"
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);

using namespace std;

void hero::move(location *loc, programm &bug, const vector<villager *> &villagers) // used to delete the initializer cause of the pass by refrence
{

    cout << "Do you want to move villagers with you ? \n [Y]es \n [N]o \n Enter a character \n";
    try
    {

        char status;
        cin >> status;
        status = tolower(status);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (status != 'y' && status != 'n')
            throw logic_error("invalid Character \n");

        if (status == 'y')
        {
            for (auto v : villagers)
            {
                remove_villager(bug, v);
                loc->set_villager(v);
                v->set_current_location(loc);
            }

            for (int i = 0; i < villagers.size(); i++)
            {
                if (villagers[i]->get_currnet_location() == villagers[i]->get_safe_location())
                {
                    cout << "thank you hero you bring me to my safe location";
                    this->perk_have.push_back(villagers[i]->drop_the_perk());
                    remove_villager(bug, villagers[i]);
                    delete villagers[i];
                }
            }
            remove_hero(bug, this);
            loc->set_hero_list(this);
            this->loc = loc;
        }

        if (status == 'n')
        {
            this->get_loc()->get_villager_list().insert(
                this->get_loc()->get_villager_list().end(),
                this->get_villagers().begin(),
                this->get_villagers().end());
            this->get_villagers().clear();
            remove_hero(bug, this);
            loc->set_hero_list(this);
            this->loc = loc;
        }
    }
    catch (logic_error &e)
    {
        cout << e.what();
        cout << "try again\n";
        hero::move(loc, bug, villagers);
    }
}

void hero::guide(vector<vector<int>> &map, programm &p)
{
    int thisNumLoc = this->loc->get_loc_relation();
    for (auto related_node : map[thisNumLoc])
        cout << related_node << ' ';
    cout << "\n select the location to see witch villagers are there and you want to guide them\n";
    try
    {
        int node_number;
        cin >> node_number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bool is_connected = false;
        for (auto i : map[thisNumLoc])
        {
            if (i == node_number)
            {
                is_connected = true;
            }
        }

        if (is_connected == true && !p.list_of_location[node_number]->get_villager_list().empty())

        {
            p.list_of_location[thisNumLoc]->set_villager(p.list_of_location[node_number]->get_villager_list()[0]); // حونه قهرمان این محلی روی شما اومده  .. این: محلی که در خانه قبلی بوده))کاربر زده(())
            remove_villager(p, p.list_of_location[node_number]->get_villager_list()[0]);

            for (int i = 0; i < villagers.size(); i++)
            {
                if (villagers[i]->get_currnet_location() == villagers[i]->get_safe_location())
                {
                    cout << "thank you hero you bring me to my safe location";
                    this->perk_have.push_back(villagers[i]->drop_the_perk());
                    remove_villager(p, villagers[i]);
                    delete villagers[i];
                }
            }

            // p.list_of_location[node_number]->get_villager_list()[0]->set_current_location(nullptr);    // خونه قبی محلی  کاربر زده شما کل ویلیچر هاتو بده موقغیت به نال بده . الان دیگه نو این خونه نیست
        }
        /*
          if ((p.list_of_location[node_number]->get_villager_list().empty()))
          {   cout<<"kir"<<endl;
               p.list_of_location[thisNumLoc]->get_villager_list().push_back(p.list_of_location[node_number]->get_villager_list()[0]);
               cout<<"moein"<<endl;

             cout<<"bahrami"<<endl;

          }
             */
        else
        {
            throw logic_error("the location that you selected is far away or it doesnt have any villager \n");
            guide(map, p);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        guide(map, p);
    }
}
void hero::advance(vector<monster *> &monsters, programm &bug)
{
    cout << "pls select a monster \n [D]rakula \n [I]nvisible man \n";
    try
    {
        char state;
        cin >> state;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        state = tolower(state);
        if (state != 'd' && state != 'i')
        {
            throw logic_error("Worng character \n");
            advance(monsters, bug);
        }
        switch (state)
        {
        case 'i':
        {
            cout << "For defeating this monster you must find 5 evidence and put them in precinct\n";

            bool is_invisible_alive = false;
            for (auto im : monsters)
            {
                if (typeid(*im).name() == typeid(invisible_man).name())
                {
                    is_invisible_alive = true;
                    if (this->get_loc()->get_loc_relation() == 14)
                    {

                        if (im->get_hidden_item() <= 0)
                        {
                            cout << "all evidence finded now go and defeat the invisible men \n";
                            return;
                        }
                        cout << "you need  " << im->get_hidden_item() << " more item\n enter how many item u want to put here\n";
                        int number;
                        cin >> number;
                        for (int i = 0; i < number; i++)
                        {
                            cout << "enter the name of your item" << endl;
                            string name;
                            cin >> name;

                            for (int item = 0; item < item_have.size(); item++)
                            {
                                if (item_have[item]->get_name() == name &&
                                    (item_have[item]->get_loc()->get_loc_relation() == 13 ||
                                     item_have[item]->get_loc()->get_loc_relation() == 15 ||
                                     item_have[item]->get_loc()->get_loc_relation() == 3 ||
                                     item_have[item]->get_loc()->get_loc_relation() == 4 ||
                                     item_have[item]->get_loc()->get_loc_relation() == 9))
                                {
                                    cout << "this item has been puted by you " << name << endl;
                                    for (auto m : monsters)
                                    {
                                        if (typeid(*m) == typeid(invisible_man))
                                        {
                                            m->get_hidden_item()--;
                                        }
                                    }
                                    delete item_have[item];
                                    item_have.erase(item_have.begin() + item);
                                    break; // ← بسیار مهم!
                                }
                            }
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        return;
                    }
                    else
                    {
                        cout << "you cant put down any item";
                    }
                }
            }
            if (!is_invisible_alive)
            {
                cout << "ohhh invisible man is dead " << endl;
                return;
            }

            break;
        }

        case 'd':
            cout << "For deafeting Drakula you must destroy his coffin's \n";

            bool is_drakula_alive = false;
            for (auto mon : monsters)
            {
                if (typeid(*mon).name() == typeid(Drakula).name())
                {
                    is_drakula_alive = true;

                    cout << "you need do destroy" << mon->get_hidden_item() << "more coffin to defeat Drakula" << endl;
                    if (this->get_loc()->get_loc_relation() == 1 || this->get_loc()->get_loc_relation() == 16 || this->get_loc()->get_loc_relation() == 17 || this->get_loc()->get_loc_relation() == 7)
                    {
                        if (bug.list_of_location[this->get_loc()->get_loc_relation()]->get_coffin_exist() == false)
                        {
                            cout << "coffin has been destroyed by who? find him/her" << endl;
                            return;
                        }

                        cout << "who many item want  to drop ? " << endl;
                        int number;
                        int powe_counter = 0;
                        cin >> number;
                        vector<item *> temp;
                        for (int l = 0; l < number; l++)
                        {
                            cout << " enter the name of the item " << endl;

                            string namer;
                            cin >> namer;
                            for (auto item : this->item_have)
                            {
                                if (item->get_name() == namer && item->get_Color() == rgb::Color::Red)
                                {
                                    temp.push_back(item);
                                    powe_counter += item->get_power();
                                }
                            }
                        }

                        if (powe_counter >= 6)
                        {
                            cout << "succesfully  destroyed a  coffin " << endl;
                            bug.list_of_location[this->get_loc()->get_loc_relation()]->set_coffin_exist(false);
                            for (int p = item_have.size() - 1; p >= 0; --p)
                            {
                                for (int b = temp.size() - 1; b >= 0; --b)
                                {
                                    if (item_have[p]->get_name() == temp[b]->get_name())
                                    {
                                        delete item_have[p];
                                        item_have.erase(item_have.begin() + p);
                                        temp.erase(temp.begin() + b);
                                        break;
                                    }
                                }
                            }
                            mon->get_hidden_item()--;
                            return;
                        }
                    }
                    else
                    {
                        cout << "ohhhhhhhhh ! sorry ! no coffin exist there " << endl;
                        return;
                    }
                }
                else
                {
                    cout << "congratulation man ! Drakula is dead " << endl;
                    return;
                }
            }

            /*
            {
                int temp = this->get_loc()->get_loc_relation();

                if ((temp == 1 || temp == 16 || temp == 17 || temp == 7))
                {
                    if (!this->get_loc()->get_coffin_exist())
                    {
                        cout << "here is a coffin if you want to destroy it u must remove some item from your inventory\n";
                        cout << "fo destroying a coffin all the items you remove from your inventory must be yellow and sum of they power must be 6 or higher\n";
                        cout << "Do you want to destroy it ? [Y]es  , [N]o  ";
                        try
                        {
                            char status;
                            cin >> status;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            status = tolower(status);
                            if (status == 'y')
                            {
                                cout << "enter how many item you want to put down";
                                vector<item *> items = this->item_have;
                                try
                                {
                                    int item_count;
                                    cin >> item_count;

                                    if (item_count > item_have.size())
                                        throw logic_error("you dont have this much item \n");

                                    int sum_power(0);
                                    cout << "enter the index of each item , each item must be yellow\n";
                                    vector<int> indexes;
                                    for (int i = 0; i < item_count; i++)
                                    {
                                        int index;
                                        cin >> index;
                                        indexes.push_back(index);
                                        if (item_have[index]->get_Color() == rgb::Color::Yellow)
                                            sum_power += item_have[index]->get_power();
                                        else
                                        {
                                            throw logic_error("the item you selected must be yellow \n");
                                        }
                                    }
                                    sort(indexes.begin(), indexes.end(), greater());
                                    if (sum_power >= 6)
                                    {
                                        for (auto items : indexes)
                                        {
                                            this->item_have.erase(item_have.begin() + items);
                                        }
                                        cout << "you destroyed one of drakula coffins \n";
                                        this->get_loc()->set_coffin_exist(false);
                                        D.set_loc(D.get_loc() - 1);
                                    }
                                    else
                                    {
                                        throw logic_error("sum of your item power must be 6 or higher\n");
                                    }
                                }
                                catch (const logic_error &e)
                                {
                                    std::cerr << e.what() << '\n';
                                    advance(D, I);
                                }

                                return;
                            }
                            if (status == 'n')
                            {
                                return;
                            }

                            throw logic_error("invalid character\n");
                        }
                        catch (const logic_error &e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    }
                    else
                    {
                        cout << "here is not any coffin or it destroyed \n";
                    }
                }
                else
                {
                    cout << "There is not any coffin here \n";
                }
                break;
            }
                */
        }
    }

    catch (const logic_error &e)
    {
        std::cerr << e.what() << '\n';
        advance(monsters, bug);
    }
}
int hero::get_action()
{
    return action;
}
void hero::defeat(vector<monster *> &monsters, programm &bug)
{
    cout << "my lord wich monster gunna be kill" << endl;
    cout << "D [Drakula] / I [Invisible_man]" << endl;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char detect;
    cin >> detect;
    detect = tolower(detect);
    if (detect == 'd')
    {

        for (auto m : monsters)
        {
            if (m->get_loc() == this->get_loc())
            {
                if (typeid(*m).name() == typeid(Drakula).name())
                {
                    if (m->get_hidden_item() <= 0)
                    {
                        cout << "for killing drakulla you need to put dowm yellow card wich them have overal  power of 6 " << endl;
                        cin.get();
                        cout << "who many item want  to drop ? " << endl;
                        int number;
                        int powe_counter = 0;
                        cin >> number;
                        vector<item *> temp;
                        for (int l = 0; l < number; l++)
                        {
                            cout << " enter the name of the item " << endl;

                            string namer;
                            cin >> namer;
                            for (auto item : this->item_have)
                            {
                                if (item->get_name() == namer && item->get_Color() == rgb::Color::Yellow)
                                {
                                    temp.push_back(item);
                                    powe_counter += item->get_power();
                                }
                            }
                        }
                        if (powe_counter >= 6)
                        {
                            message_drakula(false);
                            for (int p = item_have.size() - 1; p >= 0; --p)
                            {
                                for (int b = temp.size() - 1; b >= 0; --b)
                                {
                                    if (item_have[p]->get_name() == temp[b]->get_name())
                                    {
                                        delete item_have[p];
                                        item_have.erase(item_have.begin() + p);
                                        temp.erase(temp.begin() + b);
                                        break;
                                    }
                                }
                            }
                            for (int i = 0; i < monsters.size(); i++)
                            {
                                if (typeid(*monsters[i]).name() == typeid(Drakula).name())
                                {
                                    remove_monster(bug, monsters[i]);
                                    // monsters.erase(monsters.begin() + i);
                                    bug.next_frenzy();

                                    return;
                                }
                            }
                        }
                        else
                        {
                            cout << " ohhhhhhhhhh! the power is low  you made Drakula happy  " << endl;
                            message_drakula(true);
                            return;
                        }
                    }
                    else
                    {
                        cout << "Oh noo Drakula is still strong run Away before he capture you !!! \n";
                        message_drakula(true);
                        return;
                    }
                }
            }
            else
            {

                if (typeid(*m).name() == typeid(invisible_man).name())
                {
                    if (m->get_hidden_item() <= 0)
                    {
                        cout << "for killing Invisible_man you need to put dowm Red card wich them have overal  power of 9 " << endl;
                        cin.get();
                        cout << "who many item want  to drop ? " << endl;
                        int number;
                        int powe_counter = 0;
                        cin >> number;
                        vector<item *> temp;
                        for (int l = 0; l < number; l++)
                        {
                            cout << " enter the name of the item " << endl;

                            string namer;
                            cin >> namer;
                            for (auto item : this->item_have)
                            {
                                if (item->get_name() == namer && item->get_Color() == rgb::Color::Red)
                                {
                                    temp.push_back(item);
                                    powe_counter += item->get_power();
                                }
                            }
                        }
                        if (powe_counter >= 9)
                        {
                            message_invisible_man(false);
                            for (int p = item_have.size() - 1; p >= 0; --p)
                            {
                                for (int b = temp.size() - 1; b >= 0; --b)
                                {
                                    if (item_have[p]->get_name() == temp[b]->get_name())
                                    {
                                        delete item_have[p];
                                        item_have.erase(item_have.begin() + p);
                                        temp.erase(temp.begin() + b);
                                        break;
                                    }
                                }
                            }

                            for (int i = 0; i < monsters.size(); i++)
                            {
                                if (typeid(*monsters[i]).name() == typeid(Drakula).name())
                                {
                                    remove_monster(bug, monsters[i]);
                                    // monsters.erase(monsters.begin() + i);
                                    bug.next_frenzy();

                                    return;
                                }
                            }
                        }
                        else
                        {
                            cout << " ohhhhhhhhhh! the power is low  you made Invisible_man happy  " << endl;
                            message_invisible_man(true);
                            return;
                        }
                    }
                    else
                    {
                        cout << "Oh noo invisible man is still strong run Away before he capture you !!! \n";
                        message_invisible_man(true);

                        return;
                    }
                }
            }
        }

        cerr << "There is no monster here \n";
    }
}
void hero::pickup()
{

    cout << "OH look there is something hidden under this big rock move it using enter \n";
    cin.get();
    if (!this->loc->get_item_list().empty())
    {
        cout << "WOW look what you just found " << endl;
        for (int i = 0; i < this->loc->get_item_list().size(); i++)
        {
            cout << this->loc->get_item_list()[i]->get_name() << endl;
        }
        this->item_have.insert(item_have.end(), this->loc->get_item_list().begin(), this->loc->get_item_list().end());
        this->loc->delete_item();
    }
    else
    {
        cout << "may bad it seems noting is under this rock \n";
    }
}

void hero::set_action(int set)
{
    action = set;
}
void hero::set_perks(vector<perk *> perks)
{
    perk_have = perks;
}
vector<perk *> hero::get_perks()
{
    return perk_have;
}
void hero::set_item(vector<item *> items)
{
    item_have = items;
}
vector<item *> &hero::get_items() // has been refreced
{
    return item_have;
}
string hero::get_hero_name()
{
    return name_of_hero;
}
location *hero::get_loc()
{
    return loc;
}
hero::hero(std::vector<perk *> &perks)
{
    int random;
    srand(time(0));
    random = rand() % perks.size();
    perk_have.push_back(perks[random]);
    perks.erase(perks.begin() + random);
}

void message_drakula(bool alive)
{
    if (!alive)
    {
        cout << R"(Foolish mortal...
You have not slain evil...
You have merely unshackled it.

I was a prison, not the prisoner.
The darkness you feared was held at bay by me.

Now?
Now it walks free.
And it wears your face...
)";
    }
    else
    {
        cout << R"(Four coffins... four hearts...
And yet here you are, thinking a blade alone can end me.
I do not die by steel.
I die by wisdom... patience... sacrifice.
Qualities you sorely lack.

You see only me—but you should fear what sustains me.
Each coffin is a pact, each soul within a seal.
Until they are undone, I am inevitable.

Go now, little hero.
Burn the world to find my weakness—
And when you return...
I’ll be waiting.
Hungrier.
)";
    }
}
void message_invisible_man(bool alive)
{
    if (alive)
    {
        cout << R"(You can’t kill what you can’t see.
You swing at shadows… I carve through souls.

I’ve worn your friend’s voice.
I’ve slept in your camp.
You prayed last night—and I listened.

You're not hunting me, hero.
You're hosting me.
)";
    }
    else
    {
        cout << R"(Clever.
Painful... but clever.

They’ll sing of you, yes.
A hero who saw the unseen.
Who caged the wind.

But know this—
I was never alone.
Shadows don’t die.
They wait.

So sleep light, hero.
The next whisper…
may still be me.
)";
    }
}
std::vector<villager *> &hero::get_villagers()
{
    return villagers;
}

void hero::use_perk(programm &object1)
{
    cout << "you have this perk" << endl;
    for (auto p : this->perk_have)
    {
        cout << p->get_name() << " ";
    }

    cout << "wich perk want you use enter belwo : " << endl;
    string temp;
    cin >> temp;
    for (int i = 0; i < perk_have.size(); i++)
    {
        if (perk_have[i]->get_name() == temp)
        {
            vector<hero *> shit;
            vector<location *> shit2;
            vector<item *> shit3;
            vector<monster *> shi4;
            perk_have[i]->play(nullptr, shit, nullptr, shit2, shit3, shi4, object1);
            delete perk_have[i];
            this->perk_have.erase(perk_have.begin() + i);
        }
    }
}
