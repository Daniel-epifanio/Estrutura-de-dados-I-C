#include "combate.h"

int calcular_ataque_total(int atk_base, int bonus){
    return atk_base + bonus;
}

int aplicar_dano(int vida_atual, int dano_sofrido){
    return vida_atual - dano_sofrido;
}