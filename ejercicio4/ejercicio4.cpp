// ejercicio4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Mover Cuadrado y Cambiar a Círculo");

  
    Texture squareTexture, circleTexture;
    if (!squareTexture.loadFromFile("cuad_yellow.png") || !circleTexture.loadFromFile("rcircleg.png")) {
        return -1; 
    }

   
    Sprite shapeSprite(squareTexture);
    shapeSprite.setPosition(400, 300); 

 
    bool isSquare = true;      
    float moveSpeed = 5.0f;    


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

         
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                if (isSquare) {
                    shapeSprite.setTexture(circleTexture);
                }
                else {
                    shapeSprite.setTexture(squareTexture);
                }
                isSquare = !isSquare; 
            }
        }

     
        Vector2f position = shapeSprite.getPosition();

        if (Keyboard::isKeyPressed(Keyboard::Left) && position.x > 0) {
            position.x -= moveSpeed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && position.x + shapeSprite.getGlobalBounds().width < window.getSize().x) {
            position.x += moveSpeed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && position.y > 0) {
            position.y -= moveSpeed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && position.y + shapeSprite.getGlobalBounds().height < window.getSize().y) {
            position.y += moveSpeed;
        }

     
        shapeSprite.setPosition(position);

      
        window.clear(Color::White); 
        window.draw(shapeSprite);   
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
