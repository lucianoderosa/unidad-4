// unidad 4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Graphics.hpp>

int main()
{

    const int windowWidth = 800;
    const int windowHeight = 600;


    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Crosshair Example");


    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("crosshair.png")) {
        return -1;  
    }


    sf::Sprite crosshairSprite(crosshairTexture);


    sf::FloatRect spriteBounds = crosshairSprite.getLocalBounds();

    crosshairSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
    crosshairSprite.setPosition(windowWidth / 2, windowHeight / 2);

  
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

     
        window.clear(sf::Color::Black);

    
        window.draw(crosshairSprite);

      
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
