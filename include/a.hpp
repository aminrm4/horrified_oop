      int rand = 0;
            rand = random_number(0, monster_card_list.size());
            monster_card_list[rand]->item_handler(*this);
            monster_card_list[rand]->event(my_map, list_of_location, *this);
            monster_card_list[rand]->monster_strike(*this, monster_list);
            monster_card_list.erase(monster_card_list.begin() + rand);
            delete monster_card_list[rand];
            if (monster_card_list.empty())
            {
              cout << "you lose the game " << endl;
              exit(0);
            }
          }
        }

        for (auto hero : hero_list)
        {
          if (hero->get_hero_name() == player_two)
          {
          }
        }

        while (!monster_card_list.empty())
        {
          int rand = 0;
          rand = random_number(0, monster_card_list.size());
          monster_card_list[rand]->item_handler(*this);
          monster_card_list[rand]->event(my_map, list_of_location, *this);
          monster_card_list[rand]->monster_strike(*this, monster_list);
          monster_card_list.erase(monster_card_list.begin() + rand);
          delete monster_card_list[rand];
        }