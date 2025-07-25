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
#include <filesystem>
#include "item.hpp"
#include "free_func.hpp"
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);

using namespace std;
namespace fs = std::filesystem;

void hero::move(location *loc, programm &bug)
{
    try
    {

        remove_hero(bug, this);
        loc->set_hero_list(this);
        this->loc = loc;
    }
    catch (logic_error &e)
    {
        cout << e.what();
        cout << "try again\n";
    }
}

void hero::guide(vector<vector<int>> &map, programm &p, sf::RenderWindow &window)
{
    int thisNumLoc = this->loc->get_loc_relation();
    showCenteredTextBox(window, "select the location to see witch villagers are there and you want to guide them ");
    try
    {
        int node_number;
        node_number = showLocationTextBox(window);
        bool is_connected = false;
        if (thisNumLoc == node_number)
        {
            showCenteredTextBox(window, "wich villager you want to guide");
            for (auto vill : p.list_of_location[thisNumLoc]->get_villager_list())
            {
                showAssetInBox(window, "../Horrified_Assets/Villager", vill->get_name() + ".png");
            }
            string name;
            name = showTextInputBox(window, "enter  the villager");
            for (auto vill : p.list_of_location[thisNumLoc]->get_villager_list())
            {
                if (name == vill->get_name())
                {
                    showCenteredTextBox(window, "enter the location want to guide the villager");
                    int no;
                    no = showLocationTextBox(window);
                    for (auto i : map[thisNumLoc])
                    {
                        if (i == no)
                        {
                            is_connected = true;
                        }
                    }
                    if (is_connected)
                    {
                        vill->set_current_location(p.list_of_location[no]);
                        remove_villager(p, vill);
                        p.list_of_location[no]->set_villager(vill);
                        showCenteredTextBox(window, "villager moved succesfully");
                        if (vill->get_currnet_location() == vill->get_safe_location())
                        {
                            showCenteredTextBox(window, "thanks for bringing me to my safe loc");
                            this->perk_have.push_back(vill->drop_the_perk());
                            remove_villager(p, vill);
                            delete vill;
                        }
                        return;
                    }
                }
            }
        }

        for (auto i : map[thisNumLoc])
        {
            if (i == node_number)
            {
                is_connected = true;
            }
        }

        if (is_connected == true && !p.list_of_location[node_number]->get_villager_list().empty())

        {
            for (auto v : p.list_of_location[node_number]->get_villager_list())
            {
                showAssetInBox(window, "../Horrified_Assets/Villager", v->get_name() + ".png");
            }
            string name1;
            name1 = showTextInputBox(window, "the name of the villager want to guide");
            for (auto villl : p.list_of_location[node_number]->get_villager_list())
            {
                if (name1 == villl->get_name())
                {
                    remove_villager(p, villl);
                    p.list_of_location[thisNumLoc]->set_villager(villl);
                    villl->set_current_location(p.list_of_location[thisNumLoc]);
                    showCenteredTextBox(window, "villager move succesfully");
                    if (villl->get_currnet_location() == villl->get_safe_location())
                    {
                        showCenteredTextBox(window, "thanks for bringing me to my safe loc");
                        this->perk_have.push_back(villl->drop_the_perk());
                        remove_villager(p, villl);
                        delete villl;
                    }
                }
            }
        }

        else
        {
            throw logic_error("the location that you selected is far away or it doesnt have any villager \n");
        }
    }
    catch (const std::exception &e)
    {
        showCenteredTextBox(window, "the location that you selected is far away or it doesnt have any villager");
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
                            if (this->name_of_hero == "scientist")
                            {
                                this->ability(name);
                            }

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
                                    break;
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

                    cout << "you need do destroy " << mon->get_hidden_item() << " more coffin to defeat Drakula" << endl;
                    if (this->get_loc()->get_loc_relation() == 1 || this->get_loc()->get_loc_relation() == 16 || this->get_loc()->get_loc_relation() == 17 || this->get_loc()->get_loc_relation() == 7)
                    {
                        if (bug.list_of_location[this->get_loc()->get_loc_relation()]->get_coffin_exist() == false)
                        {
                            cout << "coffin has been destroyed by who? find him/her" << endl;
                            return;
                        }
                        cout << "those are your item " << endl;
                        cin.get();
                        for (auto ite : this->get_items())
                        {
                            if (ite->get_Color() == rgb::Color::Red)
                            {
                                cout << " the item name is :" << ite->get_name() << " item color is" << "red :" << " item power is : " << to_string(ite->get_power()) << endl;
                            }
                            if (ite->get_Color() == rgb::Color::Yellow)
                            {
                                cout << " the item name is :" << ite->get_name() << " item color is " << "yellow :" << " item power is : " << to_string(ite->get_power()) << endl;
                            }
                            if (ite->get_Color() == rgb::Color::Blue)
                            {
                                cout << " the item name is :" << ite->get_name() << " item color is " << " blue : " << " item power is : " << to_string(ite->get_power()) << endl;
                            }
                        }

                        cout << "how many item want  to drop ? " << endl;
                        int number;
                        int powe_counter = 0;
                        cin >> number;
                        vector<item *> temp;
                        for (int l = 0; l < number; l++)
                        {
                            cout << " enter the name of the item " << endl;

                            string namer;
                            cin >> namer;
                            if (this->name_of_hero == "scientist")
                            {
                                this->ability(namer);
                            }

                            for (auto item : this->item_have)
                            {
                                if (item->get_name() == namer && item->get_Color() == rgb::Color::Red)
                                {
                                    temp.push_back(item);
                                    powe_counter += item->get_power();
                                    break;
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
                        else
                        {
                            cout << "the power is under 6 " << endl;
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

    char detect;
    cin >> detect;
    detect = tolower(detect);
    if (detect == 'd')
    {
        for (auto m : monsters)
        {
            if (m->get_loc() == this->get_loc() && typeid(*m).name() == typeid(Drakula).name())
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
                        if (this->name_of_hero == "scientist")
                        {
                            this->ability(namer);
                        }
                        for (auto item : this->item_have)
                        {
                            if (item->get_name() == namer && item->get_Color() == rgb::Color::Yellow)
                            {
                                temp.push_back(item);
                                powe_counter += item->get_power();
                                break;
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
                                delete monsters[i];
                                bug.monster_list.erase(bug.monster_list.begin() + i);
                                if (bug.monster_list.size() == 0)
                                {
                                    cout << "Heros succesfuly killed all the monsters \n";
                                    cin.get();
                                    bug.clearScreen();
                                    cout << "Victory !\n";
                                    exit(0);
                                }
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
            // cerr << "There is no monster here \n";
        }
    }
    if (detect == 'i')
    {
        for (auto m : monsters)
        {
            if (m->get_loc() == this->get_loc() && typeid(*m).name() == typeid(invisible_man).name())
            {
                {
                    if (m->get_hidden_item() <= 0)
                    {
                        cout << "for killing Invisible_man you need to put dowm Red card wichthem have overal  power of 9 " << endl;
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
                            if (this->name_of_hero == "scientist")
                            {
                                this->ability(namer);
                            }
                            for (auto item : this->item_have)
                            {
                                if (item->get_name() == namer && item->get_Color() == rgb::Color::Red)
                                {
                                    temp.push_back(item);
                                    powe_counter += item->get_power();
                                    break;
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
                                if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
                                {
                                    remove_monster(bug, monsters[i]);
                                    delete monsters[i];
                                    bug.monster_list.erase(bug.monster_list.begin() + i);
                                    if (bug.monster_list.size() == 0)
                                    {
                                        cout << "Heros succesfuly killed all the monsters \n";
                                        cin.get();
                                        bug.clearScreen();
                                        cout << "Victory !\n";
                                        exit(0);
                                    }

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

            cerr << "There is no monster here \n";
        }
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
vector<perk *> &hero::get_perks()
{
    return perk_have;
}
void hero::set_item(vector<item *> items)
{
    item_have = items;
}
vector<item *> &hero::get_items()
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

void hero::use_perk(programm &object1)
{
    cout << "you have this perk" << endl;
    for (auto p : this->perk_have)
    {
        cout << p->get_name() << " ";
    }
    cout << endl;
    cout << "wich perk want you use enter belwo : " << endl;
    string temp;
    cin >> temp;
    for (int i = 0; i < perk_have.size(); i++)
    {

        if (perk_have[i]->get_name() == temp)
        {

            if (typeid(*perk_have[i]).name() == typeid(late_into_night).name())
            {
                this->set_action(this->get_action() + 2);
            }
            perk_have[i]->play(object1);
            delete perk_have[i];
            this->perk_have.erase(perk_have.begin() + i);
        }
    }
}
hero::~hero()
{
    for (auto items : item_have)
    {
        delete items;
    }
    for (auto perks : perk_have)
    {
        delete perks;
    }

    item_have.clear();
    perk_have.clear();
    loc = nullptr;
}
void hero::save_game(const string file_name)
{

    ofstream data_saver(file_name, ios::app);
    if (!data_saver)
    {
        cerr << "hero file can not be opend" << endl;
    }

    data_saver << name_of_hero << endl;
    data_saver << loc->get_loc_relation() << endl;
    data_saver << action << endl;
    if (item_have.empty())
    {
        data_saver << "no_item" << " " << endl;
    }

    for (auto ite : item_have)
    {

        data_saver << ite->get_name() << " " << ite->get_power() << " " << endl;
    }
    data_saver << "end_of_item" << " " << endl;

    if (this->perk_have.empty())
    {
        data_saver << "no_perk" << " " << endl;
    }

    for (auto pe : perk_have)
    {
        data_saver << pe->get_name() << " " << endl;
    }
    data_saver << "end_of_perk" << " " << endl;
}
void hero::load_game(std::string file_name, programm &bug)
{
    for (auto l : bug.list_of_location)
    {
        if (!l->get_item_list().empty())
        {
            for (int i = 0; i < l->get_item_list().size(); i++)
            {
                bug.list_of_items.push_back(l->get_item_list()[i]);
            }
            l->get_item_list().clear();
        }
    }

    for (auto pe : this->perk_have)
    {
        bug.list_of_perks.push_back(pe);
    }
    this->perk_have.clear();
    fs::path dir = file_name;
    if (this->name_of_hero == "mayor")
    {
        file_name = dir / "mayor.txt";
    }
    else if (this->name_of_hero == "archaeologist.txt")
    {
        file_name = dir / "archaeologist.txt";
    }
    else if (this->name_of_hero == "scientist")
    {
        file_name = dir / "scientist";
    }
    else if (this->name_of_hero == "courier")
    {
        file_name = dir / "courier";
    }
    ifstream loader(file_name);
    if (!loader)
    {
        cerr << "hero file can not opend" << endl;
    }

    int loc_num;
    int act;
    string item_have;
    string perk_have;
    loader >> this->name_of_hero;
    loader >> loc_num;
    this->move(bug.list_of_location[loc_num], bug);
    loader >> act;
    this->set_action(act);
    while (loader >> item_have)
    {
        if (item_have != "no_item")
        {

            if (item_have == "end_of_item")
            {
                break;
            }
            for (int i = 0; i < bug.list_of_items.size(); i++)
            {
                if (item_have == bug.list_of_items[i]->get_name())
                {
                    this->item_have.push_back(bug.list_of_items[i]);
                    bug.list_of_items.erase(bug.list_of_items.begin() + i);
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }

    while (loader >> perk_have)
    {
        if (perk_have != "no_perk")
        {
            if (perk_have == "end_of_perk")
            {
                break;
            }

            for (int i = 0; i < bug.list_of_perks.size(); i++)
            {

                if (bug.list_of_perks[i]->get_name() == perk_have)
                {
                    this->perk_have.push_back(bug.list_of_perks[i]);
                    bug.list_of_perks.erase(bug.list_of_perks.begin() + i);

                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    loader.close();
}
void hero::ability(std::string name_of_item)
{
    cout << "do you want to use your ability" << endl;
    char a;
    cin >> a;
    if (a == 'y')
    {
        for (auto it : this->item_have)
        {
            if (it->get_name() == name_of_item)
            {
                it->set_power(it->get_power() + 1); // call this function every where you use item
            }
        }
    }
    else
    {
        return;
    }
}
