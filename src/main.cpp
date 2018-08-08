#include "GESFML/Game.h"
#include "IntroState.h"
#include "EntityComponent.h"
#include <memory>

#include <iostream>

using namespace std;

struct CTest : GESFML::EntityComponent
{   void Update(sf::Time elapsedTime) override { cout << entity->GetId() << " Updated" << endl; }
    void Init() override { cout << entity->GetId() << " Initialized" << endl; }
};
 

int main()
{
    GESFML::Game game;
    game.Initialize(std::shared_ptr<GESFML::State>(new IntroState()));
    game.Start();

    return 0;
}
