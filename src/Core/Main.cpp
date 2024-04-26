#include "Game.hpp"
#include "../States/Editor.hpp"
#include "../States/MainMenu.hpp"
#include "../States/OptionsMenu.hpp"
#include "../States/Wallbreaker.hpp"
#include <filesystem>
#include <iostream>



int main(int /*argc*/, char* argv[])
{

	std::cout << "Current path = " << std::filesystem::current_path() << std::endl;
   
    Game& game = Game::getInstance();
    game.init(std::filesystem::current_path().string());
    // Register game states
    game.addState("Editor",      new Editor);
    game.addState("MainMenu",    new MainMenu);
    game.addState("OptionsMenu", new OptionsMenu);
    game.addState("Wallbreaker", new Wallbreaker);

    game.setCurrentState("MainMenu");
    game.run();
    return 0;
}
