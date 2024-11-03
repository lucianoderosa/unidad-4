// ejercicio5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {

    RenderWindow window(VideoMode(800, 600), "Ventana Redimensionable", Style::Default);

  
    const unsigned int minWidth = 100;
    const unsigned int minHeight = 100;
    const unsigned int maxWidth = 1000;
    const unsigned int maxHeight = 1000;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

          
            if (event.type == Event::Resized) {
             
                unsigned int newWidth = event.size.width;
                unsigned int newHeight = event.size.height;

             
                if (newWidth < minWidth) newWidth = minWidth;
                if (newHeight < minHeight) newHeight = minHeight;
                if (newWidth > maxWidth) newWidth = maxWidth;
                if (newHeight > maxHeight) newHeight = maxHeight;

             
                window.setSize(Vector2u(newWidth, newHeight));
            }
        }

      
        window.clear(Color::Black);  
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
