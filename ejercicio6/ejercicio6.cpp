// ejercicio6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Enemy {
public:
    sf::Sprite sprite;

    Enemy(const sf::Texture& texture, sf::RenderWindow& window) {
        sprite.setTexture(texture);
        sprite.setScale(0.1f, 0.1f); 
        respawn(window);
    }

    void respawn(sf::RenderWindow& window) {
        int x = rand() % (window.getSize().x - static_cast<int>(sprite.getGlobalBounds().width));
        int y = rand() % (window.getSize().y - static_cast<int>(sprite.getGlobalBounds().height));
        sprite.setPosition(x, y);
    }

    bool checkClick(const sf::Vector2i& mousePos) {
        return sprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
};

class Crosshair {
public:
    sf::Sprite sprite;

    Crosshair(const sf::Texture& texture) {
        sprite.setTexture(texture);
        sprite.setScale(0.5f, 0.5f); 
    }

    void updatePosition(const sf::Vector2i& mousePos) {
        sprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego de Crosshair");
    window.setFramerateLimit(60);

   
    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("et.png")) {
        std::cerr << "Error al cargar et.png" << std::endl;
        return -1;
    }

    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("crosshair.png")) {
        std::cerr << "Error al cargar crosshair.png" << std::endl;
        return -1;
    }

   
    Crosshair crosshair(crosshairTexture);

  
    std::vector<Enemy> enemies;
    for (int i = 0; i < 5; ++i) {
        enemies.emplace_back(enemyTexture, window);
    }

    int defeatedEnemies = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (size_t i = 0; i < enemies.size(); ++i) {
                    if (enemies[i].checkClick(mousePos)) {
                        defeatedEnemies++;
                        enemies.erase(enemies.begin() + i); 
                        break; 
                    }
                }
            }
        }

        if (defeatedEnemies >= 5) {
            std::cout << "¡Has ganado! Has derrotado a 5 enemigos." << std::endl;
            window.close();
        }

        crosshair.updatePosition(sf::Mouse::getPosition(window));

        window.clear();
        for (const auto& enemy : enemies) {
            window.draw(enemy.sprite); 
        }
        window.draw(crosshair.sprite);
        window.display();
    }

    return 0;
}






// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
