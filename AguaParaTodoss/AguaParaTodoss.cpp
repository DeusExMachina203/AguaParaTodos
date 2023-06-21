#include "pch.h"
#include "niveles.h"

struct Juego {
    string titulo;
    int anio;
};

void mostrarPresentacion(Juego* juego) {
    color(9);
    cursor(0, 0);
    char a = 178;
    cout << a;
    cursor(20, 12);
    color(15);
    cout << "Bienvenido a nuestro juego " << juego->titulo << "!" << endl;
    cursor(20, 13);
    cout << "Año de lanzamiento: " << juego->anio << endl;
    cursor(20, 14);
    cout << "Disfruta de la experiencia de juego." << endl;
    cursor(20, 16);
    cout << "ESCOGE UNA DE LAS OPCIONES" << endl;
    cursor(20, 16);
    cout << "1.INSTRUCCIONES" << endl;
    cursor(20, 17);
    cout << "2.JUGAR" << endl;
    cursor(20, 18);
    cout << "3.PRESENTACION" << endl;
}

///MAIN
int main()
{
    Console::SetWindowSize(COLUMNAS, FILAS);
    Console::CursorVisible = false;
    Juego* miJuego = new Juego;


    miJuego->titulo = "Conectando agua";
    miJuego->anio = 2023;

    mostrarPresentacion(miJuego);
    while (true) {
        mostrarPresentacion(miJuego);
        int option = 0;
        cin >> option;
        if (option > 0 && option < 4) {
            if (option == 1) {
                system("cls");
                instrucciones();
            }
            if (option == 2) {
                system("cls");
                game_loop();
            }
            if (option == 3) {
                system("cls");
                presentacion();
            }
        }
        else cout << "INGRESA UN VALOR VALIDO";

    }



    return 0;
}
