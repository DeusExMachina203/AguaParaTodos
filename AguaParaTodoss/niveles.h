#pragma once
#include "Header.h"
int vidas = 5;

void primer_nivel(personaje* principal, int& nivel) {
    vidas = 5;
    int lineas = 20;
    int linea_actual = 1;
    int siguiente = 0;
    int compañeros = 0;
    vector<proyectil> recamara;
    vector<int> posiciones_rastro = { principal->x, principal->x };
    rastro_agua rastro1;
    rastro_agua rastro2;
    rastro_agua rastro3;
    rastro_agua rastro4;
    rastro_agua rastro5;
    rastro_agua rastro6;
    rastro_agua rastro7;
	rastro_agua rastro8;
    rastro_agua rastro9;
    rastro_agua rastro10;
	rastro_agua rastro11;
    rastro_agua rastro12;
	rastro_agua rastro13;
    vector<rastro_agua> rastro = { rastro1, rastro2, rastro3, rastro4, rastro5, rastro6, rastro8, rastro9, rastro10, rastro11, rastro12, rastro13 };
    for (int i = 0; i < rastro.size(); i++) {
        rastro[i].y = principal->y + 4 + i;
        rastro[i].x = principal->x;
    }
    //columnas
    int uno = 1+centro;
    int dos = 6+centro;
    int tres = 11 + centro;
    int cuatro = 16 + centro;
    int cinco = 21 + centro;
    int seis = 26 + centro;
    int siete = 31 + centro;
    int ocho = 36 + centro;
    int nueve = 41 + centro;
    int diez = 46 + centro;
    int once = 51 + centro;
    int doce = 56 + centro;
    int trece = 61 + centro;
    int catorce = 66 + centro;
    int quince = 71 + centro;
    int dieciseis = 76 + centro;
    int diecisiete = 81 + centro;
    int dieciocho = 86 + centro;
	int diecinueve = 91 + centro;
    int veinte = 96 + centro;
    int veintiuno = 101 + centro;
    int veintidos = 106 + centro;
	int veintitres = 111 + centro;
    int veinticuatro = 116 + centro;
	int veinticinco = 121 + centro;
    //primera
    vector<bloque*> bloques1(8);
    for (int i = 0; i < bloques1.size(); i++) {
        bloques1[i] = new bloque();
        bloques1[i]->y = 1;
    }
    bloques1[0]->x = uno;
    bloques1[1]->x = tres;
    bloques1[2]->x = cinco;
    bloques1[3]->x = siete;
    bloques1[3]->debil = true;
    bloques1[4]->x = ocho;
    bloques1[5]->x = diez;
    bloques1[6]->x = once;
    bloques1[7]->x = trece;

    //segunda
    vector<bloque*> bloques2(10);
    for (int i = 0; i < bloques2.size(); i++) {
        bloques2[i] = new bloque();
        bloques2[i]->y = 1;
    }
    bloques2[0]->x = cuatro;
    bloques2[1]->x = cinco;
    bloques2[2]->x = seis;
    bloques2[3]->x = siete;
    bloques2[4]->x = siete;
    bloques2[5]->x = ocho;
    bloques2[6]->x = nueve;
    bloques2[7]->x = diez;
    bloques2[8]->x = once;
    bloques2[9]->x = doce;

    //tercera
    vector<bloque*> bloques3(10);
    for (int i = 0; i < bloques3.size(); i++) {
        bloques3[i] = new bloque();
        bloques3[i]->y = 1;
    }
    bloques3[0]->x = siete;
    bloques3[1]->x = ocho;
    bloques3[2]->x = nueve;
    bloques3[3]->x = diez;
    bloques3[4]->x = once;
    bloques3[5]->x = doce;
    bloques3[6]->x = trece;
    bloques3[7]->x = catorce;
    bloques3[8]->x = quince;
    bloques3[9]->x = dieciseis;



    //cuarta
    vector<bloque*> bloques4(10);
    for (int i = 0; i < bloques4.size(); i++) {
        bloques4[i] = new bloque();
        bloques4[i]->y = 1;
    }
    bloques4[0]->x = uno;
    bloques4[1]->x = dos;
    bloques4[2]->x = tres;
    bloques4[3]->x = cuatro;
    bloques4[4]->x = cinco;
    bloques4[5]->x = seis;
    bloques4[6]->x = siete;
    bloques4[7]->x = ocho;
    bloques4[8]->x = nueve;
    bloques4[9]->x = diez;

    vector<aliado*> amigos4(1);
    for (int i = 0; i < amigos4.size(); i++) {
        amigos4[i] = new aliado();
        amigos4[i]->y = 1;
    }
    amigos4[0]->x = trece + 1;

    //quinta
    vector<bloque*> bloques5(14);
    for (int i = 0; i < bloques5.size(); i++) {
        bloques5[i] = new bloque();
        bloques5[i]->y = 1;
    }
    bloques5[0]->x = uno;
    bloques5[1]->x = dos;
    bloques5[2]->x = tres;
    bloques5[3]->x = cuatro;
    bloques5[4]->x = cinco;
    bloques5[5]->x = seis;
    bloques5[6]->x = siete;
    bloques5[7]->x = diez;
    bloques5[8]->x = once;
    bloques5[9]->x = doce;
    bloques5[10]->x = trece;
    bloques5[11]->x = catorce;
    bloques5[12]->x = quince;
    bloques5[13]->x = dieciseis;


    vector<agente*> enemigos5(2);

    //final del nivel
    vector<casa*> casas(2);

    for (int i = 0; i < casas.size(); i++) {
		casas[i] = new casa();
		casas[i]->y = 1;
	}
    casas[0]->x = uno;
    casas[1]->x = nueve;

    vector<casa*> casas2(2);
    for (int i = 0; i < casas2.size(); i++) {
        casas2[i] = new casa();
        casas2[i]->y = 1;
    }

    casas2[0]->x =cinco;
    casas2[1]->x = doce;


    for (int i = 0; i < enemigos5.size(); i++) {
        enemigos5[i] = new agente();
        enemigos5[i]->y = 1;
    }
    enemigos5[0]->x = ocho + 1;
    enemigos5[1]->x = nueve + 1;
    cursor(35, 20); cout << "NIVEL 1";
    _sleep(1000);
    system("cls");
    while (1) {
        dibuja_personaje(principal);
        cursor(0, 0); cout << "vidas:" << vidas;
        cursor(15, 0); cout << "compañeros:" << principal->compañeros;
        if (_kbhit())
        {
            char tecla = _getch();
            movimiento_personaje(principal, tecla);
            if(recamara.size()< 8) disparo_personaje(principal, tecla, recamara);
        }
        for (int i = 0; i < recamara.size(); i++) {
            movimiento_proyectil(recamara[i], recamara, 1);
        }
        
        mover_rastro(principal, rastro, posiciones_rastro);

        if (siguiente == 30) {
            linea_actual++;
            siguiente = 0;
        }

        dibujar_indicaciones();


        if (linea_actual > 0) {

            for (int i = 0; i < bloques1.size(); i++) {
                movimiento_bloque(bloques1[i], 1, bloques1);
                if (revisar_colision_bloque(principal, bloques1[i])) vidas--;
                
            }
            colision_proyectil_bloque(recamara, bloques1);
        }
        if (linea_actual > 1) {
            for (int i = 0; i < bloques2.size(); i++) {
                movimiento_bloque(bloques2[i], 1, bloques2);
                if (revisar_colision_bloque(principal, bloques2[i])) vidas--;
            }
        }
        if (linea_actual > 2) {
            for (int i = 0; i < bloques3.size(); i++) {
                movimiento_bloque(bloques3[i], 1, bloques3);
                if (revisar_colision_bloque(principal, bloques3[i])) vidas--;
            }
        }
        if (linea_actual > 3) {
            for (int i = 0; i < bloques4.size(); i++) {
                movimiento_bloque(bloques4[i], 1, bloques4);
                if (revisar_colision_bloque(principal, bloques4[i])) vidas--;
            }
            for (int i = 0; i < amigos4.size(); i++) {
                movimiento_aliado(amigos4[i], 1);
                if (revisar_colision_aliado(principal, amigos4[i])) principal->compañeros++;
            }
        }
        if (linea_actual > 4) {
            for (int i = 0; i < bloques5.size(); i++) {
                movimiento_bloque(bloques5[i], 1, bloques5);
                if (revisar_colision_bloque(principal, bloques5[i])) vidas--;
            }
            for (int i = 0; i < enemigos5.size(); i++) {
                movimiento_agente(enemigos5[i], 1);
                if (revisar_colision_agente(principal, enemigos5[i])) vidas -= 2;
            }
        }
    if (linea_actual > 5) {
			for (int i = 0; i < casas.size(); i++) {
				movimiento_casa(casas[i], 1);
                
				if (siguiente ==10) {
					system("cls");
					return;
				}
			}
            if (siguiente > 2) {
                for (int i = 2; i < casas2.size(); i++) {
                    movimiento_casa(casas2[i], 1);
                }
            }
		}
        if (linea_actual > 7) {
            nivel++;
            system("cls");
            return;
        }
        if (vidas <= 0) {
            system("cls");
            return;
        }
        siguiente++;
        _sleep(60);
    }

}

void segundo_nivel(personaje* principal, int& nivel) {
    if (vidas > 0) {
        color(15);
        cursor(35, 20); cout << "NIVEL 2";
        _sleep(1000);
        system("cls");
    }
    else return;
}

void tercer_nivel(personaje* principal, int& nivel) {
    if (vidas > 0) {
        color(15);
        cursor(35, 20); cout << "NIVEL 3";
        _sleep(1000);
        system("cls");
    }
    else return;
}

void game_loop() {
    int nivel = 1;
    personaje* principal;
    principal = new personaje();

    principal->x = 35+centro;
    principal->y = 32;

    int lineas = 20;

    if (nivel == 1) primer_nivel(principal, nivel);
    if (nivel == 2) segundo_nivel(principal, nivel);
    if (nivel == 3) tercer_nivel(principal, nivel);

}

void instrucciones() {
    cursor(25, 1);
    cout << "INSTRUCCIONES!!\n";
    cursor(0, 2);
    cout << "  1.No te choques con los bloques, te quitaran 1 de vida\n";
    cursor(0, 4);
    cout << "  2.No te choques con los enemigos rojos, te quitaran dos de vida\n";
    cursor(0, 6);
    cout << "  3.Recoje a tus compañeros azules en el camino. Si luego te topas con uno rojo,\n  los azules que hayas recolectado evitarán que recibas daño";
    system("pause>0");
    system("cls");
}


void presentacion() {
    cursor(25, 1);
    cout << "HISTORIA";
    cursor(0, 4);
    cout << "Un día el pueblo se quedó sin agua, entonces Arturo se propuso ayudar al pueblo con este problema, él recordó que su familia tenía una excavadora en un\nlugar lejos de ahí, por lo que decidió ir hacia allá y abrir un camino al agua hacia su pueblo. El necesita tu ayuda para conseguirlo ya que no será un camino\nfácil, donde habrán obstáculos, enemigos y aliados que encontramos en esta travesía. ¿Estás listo para ser el “héroe” del pueblo ? ";

    system("pause>0");
    system("cls");
}