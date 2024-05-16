// Delegation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World.h"
#include <vector>

std::vector<sf::CircleShape> ListOfShape;
World* world = nullptr;

void renderingThread(sf::RenderWindow* window/*, const World* world*/) {
    window->setActive(true);
    sf::Clock deltaClock;

    while (window->isOpen()) {
        sf::Time dt = deltaClock.restart();
        std::cout << "Delta time: " << dt.asMilliseconds() << std::endl;
        window->clear(sf::Color::Black);
        sf::CircleShape shape(50.f);
        shape.setPosition(10.f + dt.asMilliseconds(), 30.f+dt.asMilliseconds());

        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));
        for (auto& someShape : ListOfShape) {
            window->draw(someShape);
        }
        
        //shape.
        window->draw(shape);

        window->display();
    }
    window->setActive(false);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    std::cout << "Hello World!\n";

    // Init data
    sf::CircleShape a(20.0f);
    a.setPosition(100.0f, 200.0f);
    a.setFillColor(sf::Color(100, 250, 50));
    ListOfShape.push_back(a);
    window.setActive(false);

    sf::Thread thread(&renderingThread, &window);
    thread.launch();

    //sf::Clock deltaClock;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                thread.terminate();
                window.close();
            }
            //if ()
            // Click to spawn object on screen

        }
    }
    // Clean up 
    delete world;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
