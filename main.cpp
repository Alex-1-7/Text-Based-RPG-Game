#include <iostream>
#include "function.hpp"

int main(){
  int option;
  option = main_menu();
  std::cout << option << "\n";
  switch(option) {
    case 1:{
      Character new_character = create_character();
      save_game(new_character);
      break;
    }
    case 2:{
      Character loaded_character = load_character();
      std::cout << "character name: " << loaded_character.get_name() << "\n";
      break;
    }
    case 3:{
      break;
    }
  }

  std::cout << std::flush;


}
