#include "hero.hpp"
#include <stdexcept>
#include <typeinfo>
#include <algorithm>
#include "Drakula.hpp"
#include "Invisible_man.hpp"
using namespace std;

void hero::move(location *loc,  const vector<villager *> &villagers={})//used to delete the initializer cause of the pass by refrence
{
    this->loc = loc;
    if (!villagers.empty())
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
                        v->set_current_location(this->loc);

                    for (int i = 0; i < villagers.size(); i++)
                    {
                       if(villagers[i]->get_currnet_location() == villagers[i]->get_safe_location())
                        {
                            cout << "thank you hero you bring me to my safe location";
                            this->perk_have.push_back(villagers[i]->drop_the_perk());
                        }
                    }
                    
                }
        }
        catch (logic_error &e)
        {
            cout << e.what();
            cout << "try again\n";
            hero::move(loc, villagers);
        }
    }
}
void hero::guide(vector<vector<int>>& map)
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

        bool is_connected{};

        for (auto node : map[node_number])
            if (node == thisNumLoc)
                is_connected = true;

        if (is_connected)
        {
        }
        else
        {
            throw logic_error("the location that you selected is far away \n");
            guide(map);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        guide(map);
    }
}
void hero::advance(Drakula &D, invisible_man &I)
{
    cout << "pls select a monster \n [D]rakula \n [I]nvisible man \n";
    try
    {
        char m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        m = tolower(m);
        if (m != 'd' || m != 'i')
        {
            throw logic_error("Worng character \n");
            advance(D, I);
        }
        switch (m)
        {
        case 'i':
            cout << "For defeating this monster you must find 5 evidence and put them in precinct\n";
            if (this->get_loc()->get_loc_relation() == 14)
            {
                vector<item *> droped = this->get_loc()->get_item_list();
                int counter(0);

                for (auto items : droped)
                {
                    int temp = items->get_loc()->get_loc_relation();
                    switch (temp)
                    {
                    case 13:
                        counter++;
                        break;

                    case 15:
                        counter++;
                        break;

                    case 3:
                        counter++;
                        break;

                    case 4:
                        counter++;
                        break;

                    case 9:
                        counter++;
                        break;

                    default:
                        break;
                    }
                }
                if (counter >= 5)
                {
                    cout << "all evidence finded now go and defeat the invisible men \n";
                }
                cout << "you need " << 5 - counter << " more item\n enter how many item u want to put here\n";
                try
                {
                    vector<int> ind;
                    int number;
                    cin >> number;
                    cout << "Enter the index of your items";

                    for (int i = 0; i < number; i++)
                    {
                        int index;
                        cin >> index;
                        int it = this->item_have.at(index)->get_loc()->get_loc_relation();

                        if (it == 13 || it == 15 || it == 3 || it == 4 || it == 9)
                        {
                            counter++;
                            ind.push_back(index);
                        }
                    }
                    if (counter >= 5)
                    {
                        cout << "now you can defeat invisible men \n";
                        I.set_remain_hidden_item(0);
                    }
                    sort(ind.begin(), ind.end(), greater());
                    for (int i = 0; i < ind.size(); i++)
                    {
                        this->item_have.erase(item_have.begin() + ind[i]);
                    }
                    I.set_remain_hidden_item(5 - counter);
                }
                catch (logic_error &e)
                {
                    cerr << e.what();
                }
            }
            else
            {
                cout << "you cant put down any item";
            }

            break;

        case 'd':
            cout << "For deafeting Drakula you must destroy his coffin's \n";
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
                                    if (item_have[index]->get_Color() == Color::Yellow)
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

        default:
            break;
        }
    }
    catch (const logic_error &e)
    {
        std::cerr << e.what() << '\n';
        advance(D, I);
    }
    catch (invalid_argument &e)
    {
        cerr << e.what();
        advance(D, I);
    }
}
int hero::get_action()
{
    return action;
}
void hero::defeat(Drakula *D, invisible_man *I, vector<monster *> &monsters)
{
    if (D->get_loc() == this->get_loc())
    {
        if (D->get_remaining_coffin() <= 0)
        {
            cout << "There is no more coffin left you can defeat him using enter button!!";
            cin.get();
            cout << "oh look he left a massage for you \n";
            cin.get();
            cout << R"(Foolish mortal...
You have not slain evil...
You have merely unshackled it.

I was a prison, not the prisoner.
The darkness you feared was held at bay by me.

Now?
Now it walks free.
And it wears your face...)";

            for (int i = 0; i < monsters.size(); i++)
            {
                if (typeid(*monsters[i]).name() == typeid(Drakula).name())
                {
                    monsters.erase(monsters.begin() + i);
                    return;
                }
            }
        }
        else
        {
            cout << "Oh noo Drakula is still strong run Away before he capture you !!! \n";
            cin.get();
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
Hungrier.)";
            return;
        }
    }
    if (I->get_loc() == this->get_loc())
    {
        if (I->get_remain_hidden_item() <= 0)
        {
            cout << "There is no more item that are hidden you can defeat him using enter button!!";
            cin.get();
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
may still be me.)";
            for (int i = 0; i < monsters.size(); i++)
            {
                if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
                {
                    monsters.erase(monsters.begin() + i);
                    return;
                }
            }
        }
        else
        {
            cout << R"(You can’t kill what you can’t see.
You swing at shadows… I carve through souls.

I’ve worn your friend’s voice.
I’ve slept in your camp.
You prayed last night—and I listened.

You're not hunting me, hero.
You're hosting me.)";
            return;
        }
    }
    cerr << "There is no monster here \n";
}
void hero::pickup()
{
    vector<item*> items = this->loc->get_item_list();
    cout << "OH look there is something hidden under this big rock move it using enter \n";
    cin.get();
    if(!items.empty())
    {
        cout << "WOW look what you just found";
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << endl;
        }
        this->item_have.insert(items.begin() , items.end() , item_have.end());
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
void hero::set_perks(vector<perk*> perks)
{
    perk_have = perks;
}
vector<perk*> hero::get_perks()
{
    return perk_have;
}
void hero::set_item(vector<item*> items)
{
    item_have = items;
}
vector<item*> hero::get_items()
{
    return item_have;
}
    string  hero::get_hero_name()
    {
        return name_of_hero;
    }
