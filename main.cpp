#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "functions.h"
using namespace std;

// Avance 1: Bingo Americano!!!
// Lectura, Ordenamiento, Búsequeda de Datos
// Es un juego donde un usuario adivina 5 puntajes finales
// de los partidos de la semana y si la mayoría de sus
// puntajes fueron puntajes finales real, el usuario gana!

int main() {
  vector<int> scores;

  // abrir y leer archivo de puntajes, cargar los puntajes en un vector
  string line;
  ifstream file_open_scores("scores.txt");
  if (file_open_scores.is_open()) {
    while (getline(file_open_scores, line)) {
      string num = "";
      for (int i = 0; i <= line.length(); i++) {
        if (line[i] == ' ' || i == line.length()) {
          scores.push_back(getScore(num)); 
          num = "";
        } else num += line[i];
      }
    }
    file_open_scores.close();
  } else cout << "Unable to open file\n";

  mergeSort(scores); // llamar el sort para sortear los puntajes del vector scores

  // printVector(scores, "scores");

  vector<int> guesses;

  // abrir y leer archivo de los guesses del usuario, cargarlos en un vector
  ifstream file_open_guesses("guesses.txt");
  if (file_open_guesses.is_open()) {
    while(getline(file_open_guesses, line)) {
      string num = "";
      for (int i = 0; i <= line.length(); i++) {
        if (line[i] == ' ' || i == line.length()) {
          guesses.push_back(getScore(num));
          num = "";
        } else num += line[i];
      }
    }
    file_open_guesses.close();
  } else cout << "Unable to open file\n";

  // printVector(guesses, "guesses");

  // donde pasa la magia
  // para cada valor del vector de los guesses del usuario, 
  // se busca en el vector de scores, y si está ahí, el score
  // del usuario aumenta en uno. sin reemplazar, una vez que 
  // se encuentre la adivinanza del usuario, se quita del 
  // vector
  int score_user = 0;
  for (int i = 0; i < guesses.size(); i++) {
    if (busqueda_binaria(scores, scores.size(), guesses[i])) score_user++;
  }

  // printVector(scores, "scores");

  if (score_user >= 3) {
    cout << "Winner Winner Chicken Dinner!! Tuviste un score de " << score_user << " de 5!" << endl;
  } else {
    cout << "Perdón mi lastimado jugador, solo " << score_user << " de tus adivinanzas fueron correctas." << endl;
  }

  return 0;
}