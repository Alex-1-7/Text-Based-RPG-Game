#include <iostream>
#include <string>
#include <fstream>
#include "CharacterClass.cpp"

int main_menu(){
  int option = 0;
  std::string temp;
  std::cout << "\nMain Menu \n";
  std::cout << "1: New Character\n";
  std::cout << "2: Load Character\n";
  std::cout << "3: Quit Game\n\n";
  std::cout << "Enter 1, 2, or 3:\n";
  while ((option != 1) && (option != 2) && (option != 3)) {
    try{
      std::cin >> temp;
      if (!std::isdigit(temp[0])) {
        throw "Invalid Input";
      }
      option = std::stoi(temp);
    }
    catch(const char* e){
      std::cout << e <<"\n";
    }
  }
  return option;

}

Character create_character(){
  int classtype;
  int race;
  std::string name;
  std::cout << "Choose your class:\n";
  std::cout << "1: Warrior\n2: Mage\n3: Ranger\n";
  std::cin >> classtype;
  std::cout << "Choose your race:\n";
  std::cout << "1: Human\n2: Dwarf\n3: Elf\n";
  std::cin >> race;
  std::cout << "Enter a name:\n";
  std::cin >> name;

  Character my_character = Character(name, race, classtype);
  return my_character;
}

Character load_character(){
  std::string filename;
  std::string line;
  std::cout << "Enter character name: \n";
  std::cin >> filename;
  filename.append(".txt");
  std::ifstream loaded_file; //i for input, taking in data from file, o would be output, for writing, output data to file
  loaded_file.open(filename);
  if (loaded_file.is_open()){
      loaded_file >> line;
      //std::cout << line << "\n" << line.length();
      std::string temp;
      int counter = 0;
      std::string character_data[6]; //currently 6 element of character data
      for (int i = 0; i < line.length(); i++){
        if (line[i] == ','){
          character_data[counter] = temp;
          temp = "";
          counter++;
        }
        else {
          temp.push_back(line[i]); //append used for strings, push_back used for char
        }
      }
      //int arrSize = *(&character_data + 1) - character_data;
      //for (int i = 0; i < arrSize; i++) {
        //std::cout << character_data[i] << "\n";
      //}
      Character loaded_character = Character(character_data[0], std::stoi(character_data[1]), std::stoi(character_data[2]), std::stoi(character_data[3]), std::stoi(character_data[4]), std::stoi(character_data[5]));
      loaded_file.close();
      return loaded_character;
  }
  else{
    std::cout << "Unable to open file";
    Character not_found = Character();
    return not_found;
  }

}

void save_game(Character my_character){
  std::ofstream save_file;
  std::string filename = my_character.get_name();
  filename.append(".txt");
  save_file.open(filename);
  save_file << my_character.get_name() << "," << my_character.get_race() << "," << my_character.get_classtype() << "," << my_character.get_max_hp() << "," << my_character.get_current_hp() << "," << my_character.get_gold();
  save_file.close();
}
