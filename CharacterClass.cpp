
class Character {
  std::string name;
  int race, classtype, max_hp, current_hp, gold;

public:
  //no stats character
  Character(){
    name = "empty";
    race = 0;
    classtype = 0;
    gold = 0;
    max_hp = 0;
    current_hp = max_hp;
  }

  //making new character
  Character(std::string new_name, int new_race, int new_classtype) {
    name = new_name;
    race = new_race;
    classtype = new_classtype;
    gold = 0;
    max_hp = 10;
    current_hp = max_hp;
  }

  //loading character
  Character(std::string new_name, int new_race, int new_classtype, int new_max_hp, int new_current_hp, int new_gold) {
    name = new_name;
    race = new_race;
    classtype = new_classtype;
    gold = new_gold;
    max_hp = new_max_hp;
    current_hp = new_current_hp;
  }

  std::string get_name(){
    return name;
  }
  int get_race(){
    return race;
  }
  int get_classtype(){
    return classtype;
  }
  int get_max_hp(){
    return max_hp;
  }
  int get_current_hp(){
    return current_hp;
  }
  int get_gold(){
    return gold;
  }
};
