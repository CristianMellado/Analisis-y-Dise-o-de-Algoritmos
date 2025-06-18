//Cristian Mellado Baca
//04-06-2025
//Planificacion de Tareas
#include <iostream>
#include <vector>
using namespace std;
struct tarea {
	int beneficio, tiempo, pos_ini;
};
bool comparar(const tarea& a, const tarea& b) { //ordena las tareas de mayor a menor
	return a.beneficio > b.beneficio;
}

//

vector <int> padre;

int encontrar(int x) { //devuelve el tiempo libre mas cercano
	if (padre[x] != x)
		padre[x] = encontrar(padre[x]);
	return padre[x];
}

void unir(int x, int y) { //x ocupado y y es el siguiente en buscar
	padre[x] = y;
}

/*
4
50 2
10 1
15 2
30 1
0
*/

int main()
{
	int n;

	while (cin >> n && n != 0) {
		vector<tarea> tareas(n);
		int tiempo_max = 0;
		for (int i = 0; i < n; i++) {
			cin >> tareas[i].beneficio >> tareas[i].tiempo;
			tareas[i].pos_ini = i + 1;
			if (tareas[i].tiempo > tiempo_max) {
				tiempo_max = tareas[i].tiempo;
			}
		}
		//
		for (int i = 0; i < n; i++) {
			int max_idx = i;
			for (int j = i + 1; j < n; j++) {
				if (tareas[j].beneficio > tareas[max_idx].beneficio) {
					max_idx = j;
				}
			}
			if (max_idx != i) {
				//swapp
				tarea temp;
				temp.beneficio = tareas[i].beneficio;
				temp.tiempo = tareas[i].tiempo;
				temp.pos_ini = tareas[i].pos_ini;

				tareas[i].beneficio = tareas[max_idx].beneficio;
				tareas[i].tiempo = tareas[max_idx].tiempo;
				tareas[i].pos_ini = tareas[max_idx].pos_ini;

				tareas[max_idx].beneficio = temp.beneficio;
				tareas[max_idx].tiempo = temp.tiempo;
				tareas[max_idx].pos_ini = temp.pos_ini;

			}
		}

		padre.resize(tiempo_max + 1);

		for (int i = 0; i <= tiempo_max; ++i) { //inicia los tiempos disponibles hasta el tiempo maximo
			padre[i] = i;
		}

		int beneficio_total = 0;
		vector <int> seleccionadas;
		for (const auto& tarea : tareas) {
			int disponible = encontrar(tarea.tiempo);
			if (disponible > 0) {
				beneficio_total = beneficio_total + tarea.beneficio;
				seleccionadas.push_back(tarea.pos_ini);
				unir(disponible, disponible - 1); //actual y anterior tarea
			}
		}
		cout << beneficio_total << "\n";
		for (int idx : seleccionadas) {
			cout << idx << " ";
		}
		cout << "\n";

	}
	return 0;
}
