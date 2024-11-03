// ejercicio3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Círculos Rojos y Azules");

  
    Texture redCircleTexture, blueCircleTexture;
    if (!redCircleTexture.loadFromFile("rcircle.png") || !blueCircleTexture.loadFromFile("rcircleb.png")) {
        return -1; 
    }

    
    std::vector<Sprite> circles;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

           
            if (event.type == Event::MouseButtonPressed) {
                Sprite circleSprite;

                
                if (event.mouseButton.button == Mouse::Left) {
                    circleSprite.setTexture(redCircleTexture); 
                }
                else if (event.mouseButton.button == Mouse::Right) {
                    circleSprite.setTexture(blueCircleTexture); 
                }

            
                circleSprite.setPosition(Vector2f(event.mouseButton.x, event.mouseButton.y));

               
                circles.push_back(circleSprite);
            }
        }

        window.clear(Color::White); 

      
        for (const auto& circle : circles) {
            window.draw(circle);
        }

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
