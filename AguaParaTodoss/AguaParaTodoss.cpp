#include "pch.h"
#include "niveles.h"

struct Juego {
    string titulo;
    int anio;
};

vector<string> imagen_principal = {
"    .??.",
"   :JGJJGJ:",
"  :JPJ:..:JGJ:",
" :JGJ:......:JGJ:",
".JGJ:..........^YBJ.",
"7GY^..............~5B7",
"                           ^GP~.................:!GP^",
"                          JB?...................:::?BJ",
"                        :GP^....................:^::~GG:",
"                       ~#J......................:^^^:^5#~",
"                      !#7.. ....................:^^^^:^Y#!",
"                     ~&?.. ......::..........::::^^^^:^~J&~",
"                    .BY:: .....7GG?J!......!PB?J?::^^^:~~5B.",
"                   !G#^:. :...:#&#JGB......B&#JP#^:^^::~!!#G~",
"                  ?#&5::  ^^:::P&&&&Y....::5&&&&P^:^^:^!!~5##?",
"                 ~&J#J::  :^^^:^7JJ7^:~77~:^7JJ7^:^^::~!!~Y#J&~",
"                 PG~BP^:  .^^^^::::::!5JJ5!::::::^^::~!!!~PB~GP",
"                :&J~G#!~:  :^^^^^^^^:75??57:^^^^^::^~!!!!!#G~J&:",
"                .GGPYBP~~:  :^^^^^^^:^JYYJ^:^::::^~!!!!!~PBYPGG.",
"                 .^: ^B5!!^. .:^:::::::^^::::^^^~!!!!!!!5B^ :^.",
"                      :GG7~~^. :^^^^^^^^^^^~~~!!!!!!!~7GP:",
"                        ?G57!~^:::^~!!!!!!!!!!!!!!~~75G?",
"                         .?PPJ7!~~^^^~!!!!!!!~~~~7JPP?.",
"                            ^?GG5J?7!!!!!!!!7?J5GGJ^",
"                              Y#?Y5BG555555GB5Y?#Y",
"                              ~&?~7&7 .... 7&7~?&~",
"                            ..:5B7BG^^^^^^^^GB?BP:..",
"                          .^^^^^JPY~^^^^^^^^~YPY~^^^^.",
};

vector<string> imagen_mundo = {
"          ._..::__:  ,-\"-\"._ | 7       ,     _,.__             ",
"       _.___ _ _<_>`!(._`.`-.    /         _._     `_ ,_/  '  '-._.---.-.__",
"    >.{     \" \" `-==,',._\{  \  / {)      / _ \" > _,-' `                mt-2_",
"      \\_.:--.       `._ )`^-. \"'       , [_/(                       __,/-'",
"     '\"'     \\         \"    _L        oD_,--'                ) / . (| ",
"              |           ,'          _)_.\\._<> 6              _,' /  '   ",
"              `.         /           [_/_'` `\"(                <'}  )      ",
"               \\\\    .-. )           /   `-'\"..' `:._          _)  '      ",
"        `        \  (  `(           /         `:\  > \  ,-^.  /' '         ",
"                  `._,   ""         |           \`'   \|   ?_)  {\         ",
"                     `=.---.        `._._       ,'     \"` | ' ,- '.        ",
"                       |    `-._         |     /          `:`<_|h--._      ",
"                       (        >        .     | ,          `=.__.`-'\     ",
"                        `.     /         |     |{|              ,-.,\     .",
"                         |   ,'           \\   / `'            ,\"     \\     ",
"                         |  /              |_'                |  __  /     ",
"                         | |                                  '-'  `-'   \\.",
"                         |/                                         \" / \\",
"                         \\.                                             '  ",
};

void mostrarPresentacion(Juego* juego) {

    
    color(10);
    cursor(0+centro, 0);
    for (int i = 0; i< imagen_mundo.size(); i++) {
        
        cursor(0 + centro, i + 1);
        cout << imagen_mundo[i] << endl;
        
	}
    color(9);

    for (int i = 0; i < imagen_principal.size(); i++) {
        if (i < 6) {
            cursor(0 + centro + (34 - i), i + 15);
            cout << imagen_principal[i] << endl;

        }
        else {
            cursor(0 + centro, i + 15);
            cout << imagen_principal[i] << endl;
        }
    }
    int x = 35;
    cursor(20+centro, x);
    color(15);
    std::cout << "Bienvenido a nuestro juego Agua Para Todos!" << endl;
    cursor(20+centro, x+3);
    std::cout << "Disfruta de la experiencia de juego." << endl;
    cursor(20+centro, x+2);
    std::cout << "ESCOGE UNA DE LAS OPCIONES" << endl;
    cursor(20+centro, x+5);
    std::cout << "1.INSTRUCCIONES" << endl;
    cursor(20+centro, x+6);
    std::cout << "2.JUGAR" << endl;
    cursor(20+centro, x+7);
    std::cout << "3.PRESENTACION" << endl;
}

///MAIN
int main()
{
    Console::SetWindowSize(COLUMNAS, FILAS);
    Console::CursorVisible = false;
    Juego* miJuego = new Juego;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;


    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

    GetConsoleScreenBufferInfoEx(hConsole, &info);

    info.ColorTable[0] = RGB(150, 75, 30);
    

    SetConsoleScreenBufferInfoEx(hConsole, &info);
    /* Set new attributes */
    SetConsoleTextAttribute(hConsole, 0);
    Console::Clear();


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
