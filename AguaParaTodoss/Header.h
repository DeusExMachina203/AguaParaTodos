#pragma once
#include "conio.h"
#include "iostream"
#include <vector>
#define FILAS 40
#define COLUMNAS 80
#define Arriba 72
#define Abajo  80
#define Derecha 77
#define Izquierda 75
#define Espaciadora 32
#define Escape 27

using namespace System;
using namespace std;

void cursor(int x, int y)
{
    Console::SetCursorPosition(x, y);
}
void color(int c)
{
    switch (c)
    {
    case 1: Console::ForegroundColor = ConsoleColor::Black; break;
    case 2: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
    case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
    case 4: Console::ForegroundColor = ConsoleColor::DarkRed; break;
    case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
    case 8: Console::ForegroundColor = ConsoleColor::DarkGray; break;
    case 9: Console::ForegroundColor = ConsoleColor::Blue; break;
    case 10: Console::ForegroundColor = ConsoleColor::Green; break;
    case 11: Console::ForegroundColor = ConsoleColor::Cyan; break;
    case 12: Console::ForegroundColor = ConsoleColor::Red; break;
    case 13: Console::ForegroundColor = ConsoleColor::Magenta; break;
    case 14: Console::ForegroundColor = ConsoleColor::Yellow; break;
    case 15: Console::ForegroundColor = ConsoleColor::White; break;
    }
}

struct personaje
{
    int x, y;
    int compañeros = 0;
    string cabeza = "  *";
    string cuerpo = " * *";
    string pies = "*   *";

};

struct bloque {
    int x, y;
    bool colisionado = false;
    bool colisionado_proyectil = false;
    bool debil = false;
    bool recoriendo = true;
    vector<string> figura = { "###", "###", "###" };
    vector<string> figura_debil = { "$$$", "$$$", "$$$" };
};

struct proyectil {
	int x, y;
	string figura = "S";
};


struct aliado {
    int x, y;
    bool colisionado = false;
    vector<string> figura = { "%","%","%" };
};

struct agente {
    int x, y;
    bool colisionado = false;
    vector<string> figura = { "$","$","$" };
};

//aliado
void dibuja_aliado(aliado* amigo) {
    color(11);
    for (int i = 0; i < amigo->figura.size(); i++) {
        cursor(amigo->x, amigo->y + i); cout << amigo->figura[i];
    }
}
void borra_aliado(aliado* amigo) {
    for (int i = 0; i < amigo->figura.size(); i++) {
        cursor(amigo->x, amigo->y + i); cout << " ";
    }
}
void movimiento_aliado(aliado*& amigo, int cantidad) {
    dibuja_aliado(amigo);
    borra_aliado(amigo);
    amigo->y += cantidad;
    dibuja_aliado(amigo);
    if (amigo->y > 35) {
        borra_aliado(amigo);
        delete amigo;
    }
}
bool revisar_colision_aliado(personaje* principal, aliado* amigo) {
    if (amigo->colisionado) return false;
    int personajex = principal->x;
    int personajey = principal->y;
    int amigox = amigo->x;
    int amigoy = amigo->y;
    if (personajex + 2 == amigox && personajey >= amigoy && personajey <= amigoy + 2
        || personajex + 1 == amigox && personajey + 1 >= amigoy && personajey + 1 <= amigoy + 2
        || personajex + 3 == amigox && personajey + 1 >= amigoy && personajey + 1 <= amigoy + 2
        || personajex == amigox && personajey + 2 >= amigoy && personajey + 2 <= amigoy + 2
        || personajex + 4 == amigox && personajey + 2 >= amigoy && personajey + 2 <= amigoy + 2) {
        amigo->colisionado = true;
        amigo->figura = { " ", " ", " " };
        return true;
    }
    else return false;
}

//agente
void dibuja_agente(agente* enemigo) {
    color(12);
    for (int i = 0; i < enemigo->figura.size(); i++) {
        cursor(enemigo->x, enemigo->y + i); cout << enemigo->figura[i];
    }
}
void borra_agente(agente* enemigo) {
    for (int i = 0; i < enemigo->figura.size(); i++) {
        cursor(enemigo->x, enemigo->y + i); cout << " ";
    }
}
void movimiento_agente(agente*& enemigo, int cantidad) {
    dibuja_agente(enemigo);
    borra_agente(enemigo);
    enemigo->y += cantidad;
    dibuja_agente(enemigo);
    if (enemigo->y > 35) {
        borra_agente(enemigo);
        delete enemigo;
    }
}
bool revisar_colision_agente(personaje*& principal, agente* enemigo) {
    if (enemigo->colisionado) return false;
    int personajex = principal->x;
    int personajey = principal->y;
    int agentex = enemigo->x;
    int agentey = enemigo->y;
    if (principal->compañeros == 0 && (personajex + 2 == agentex && personajey >= agentey && personajey <= agentey + 2
        || personajex + 1 == agentex && personajey + 1 >= agentey && personajey + 1 <= agentey + 2
        || personajex + 3 == agentex && personajey + 1 >= agentey && personajey + 1 <= agentey + 2
        || personajex == agentex && personajey + 2 >= agentey && personajey + 2 <= agentey + 2
        || personajex + 4 == agentex && personajey + 2 >= agentey && personajey + 2 <= agentey + 2)) {
        enemigo->colisionado = true;
        return true;
    }

    else if (principal->compañeros > 0 && (personajex + 2 == agentex && personajey >= agentey && personajey <= agentey + 2
        || personajex + 1 == agentex && personajey + 1 >= agentey && personajey + 1 <= agentey + 2
        || personajex + 3 == agentex && personajey + 1 >= agentey && personajey + 1 <= agentey + 2
        || personajex == agentex && personajey + 2 >= agentey && personajey + 2 <= agentey + 2
        || personajex + 4 == agentex && personajey + 2 >= agentey && personajey + 2 <= agentey + 2)) {
        enemigo->colisionado = true;
        enemigo->figura = { " ", " ", " " };
        principal->compañeros--;
        return false;
    }
    else return false;
}

//bloque
void dibuja_bloque(bloque* objeto) {
    if (objeto->debil) color(4);
    else color(14);
    if (objeto->debil) {
        for (int i = 0; i < objeto->figura.size(); i++) {
            cursor(objeto->x, objeto->y + i); cout << objeto->figura_debil[i];
        }
    }
    else {
        for (int i = 0; i < objeto->figura.size(); i++) {
            cursor(objeto->x, objeto->y + i); cout << objeto->figura[i];
        }
    }
}

void borra_bloque(bloque* objeto) {
    color(14);
    for (int i = 0; i < objeto->figura.size(); i++) {
        cursor(objeto->x, objeto->y + i); cout << "   ";
    }
}

void movimiento_bloque(bloque*& objeto, int cantidad, vector<bloque*>& bloques) {
    if (objeto->recoriendo) {
        dibuja_bloque(objeto);
        borra_bloque(objeto);
        objeto->y += cantidad;
        dibuja_bloque(objeto);
    }
    if (objeto->y > 35) {
        borra_bloque(objeto);
        objeto->recoriendo = false;
    }
}

bool revisar_colision_bloque(personaje* principal, bloque* objeto) {
    if (objeto->colisionado) return false;
    int personajex = principal->x;
    int personajey = principal->y;
    int bloquex = objeto->x;
    int bloquey = objeto->y;
    if (personajex + 2 >= bloquex && personajex + 2 <= bloquex + 2 && personajey >= bloquey && personajey <= bloquey + 2
        || personajex + 1 >= bloquex && personajex + 1 <= bloquex + 2 && personajey + 1 >= bloquey && personajey + 1 <= bloquey + 2
        || personajex + 3 >= bloquex && personajex + 3 <= bloquex + 2 && personajey + 1 >= bloquey && personajey + 1 <= bloquey + 2
        || personajex >= bloquex && personajex <= bloquex + 2 && personajey + 2 >= bloquey && personajey + 2 <= bloquey + 2
        || personajex + 4 >= bloquex && personajex + 4 <= bloquex + 2 && personajey + 2 >= bloquey && personajey + 2 <= bloquey + 2) {
        objeto->colisionado = true;
        return true;
    }
    else return false;
}

//personaje
void dibuja_personaje(personaje* personaje)
{
    color(9);
    cursor(personaje->x, personaje->y); cout << personaje->cabeza;
    color(3);
    cursor(personaje->x, personaje->y + 1); cout << personaje->cuerpo;
    cursor(personaje->x, personaje->y + 2); cout << personaje->pies;

}

void borra_personaje(personaje* personaje)
{
    cursor(personaje->x, personaje->y);     cout << "   ";
    cursor(personaje->x, personaje->y + 1); cout << "    ";
    cursor(personaje->x, personaje->y + 2); cout << "     ";
}

void camino_agua(personaje* principal, int diferencia) {
    color(9);
    cursor(principal->x, principal->y + diferencia + 2); cout << "*****";
}
void movimiento_personaje(personaje* principal, char tecla) {
    dibuja_personaje(principal);
    borra_personaje(principal);

    if (tecla == 77 && principal->x < 75) principal->x += 5; //derecha
    if (tecla == 75 && principal->x > 0) principal->x -= 5; //izq

    dibuja_personaje(principal);


}
//proyectil

void dibuja_proyectil(proyectil bala) {
	color(12);
	cursor(bala.x, bala.y); cout << bala.figura;
}
void borra_proyectil(proyectil bala) {
	cursor(bala.x, bala.y); cout << " ";
}
void movimiento_proyectil(proyectil& bala,vector<proyectil> &recamara , int cantidad) {
	
	dibuja_proyectil(bala);
	borra_proyectil(bala);
	bala.y -= cantidad;
	dibuja_proyectil(bala);
	
	if (bala.y < 2) {
		borra_proyectil(bala);
        recamara.erase(recamara.begin());
	}
}

void disparo_personaje(personaje* principal, char tecla, vector<proyectil>& recamara) {
	if (tecla == 32 && recamara.size() < 3) {
		proyectil bala;
		bala.x = principal->x + 2;
		bala.y = principal->y - 1;
		recamara.push_back(bala);
	}
}

void colision_proyectil_bloque(vector<proyectil> recamara, vector<bloque*> linea) {
    for (int i = 0; i < linea.size(); i++) {
        for (int j = 0; j < recamara.size(); j++) {
            if (linea[i]->debil && ((recamara[j].x >= linea[i]->x) && (recamara[j].x <= linea[i]->x + 2)) && (recamara[j].y >= linea[i]->y && recamara[j].y <= linea[i]->y + 2)) {
                linea[i]->debil = false;
				linea[i]->colisionado = true;
                linea[i]->figura = {"   ","   ","   "};
            }
        }

    }
}