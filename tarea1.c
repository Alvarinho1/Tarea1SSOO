#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <random>

std::mutex race_mutex;  // Para sincronizar el acceso a recursos compartidos

void carrera(int id_auto, int distancia_total, int &posicion, std::vector<int> &ranking) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10); // Metros aleatorios
    std::uniform_int_distribution<> velocidad(100, 500); // Tiempo aleatorio en milisegundos

    int distancia_recorrida = 0;

    while (distancia_recorrida < distancia_total) {
        int avance = dist(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(velocidad(gen)));

        distancia_recorrida += avance;
        if (distancia_recorrida > distancia_total) distancia_recorrida = distancia_total;  // Limitar a la distancia total

        // Bloquear el mutex para sincronizar la salida por consola
        std::lock_guard<std::mutex> lock(race_mutex);
        std::cout << "Auto " << id_auto << " avanza " << avance << " metros (total: " 
                  << distancia_recorrida << " metros)" << std::endl;
    }

    // Bloquear el mutex para actualizar el ranking
    {
        std::lock_guard<std::mutex> lock(race_mutex);
        posicion++;
        ranking[id_auto] = posicion;
        std::cout << "Auto " << id_auto << " termina en la posición " << posicion << "!" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <distancia_total> <numero_autos>" << std::endl;
        return 1;
    }

    int distancia = std::stoi(argv[1]);
    int num_autos = std::stoi(argv[2]);

    std::vector<std::thread> autos;
    std::vector<int> ranking(num_autos, 0);
    int posicion = 0;

    for (int i = 0; i < num_autos; ++i) {
        autos.emplace_back(carrera, i, distancia, std::ref(posicion), std::ref(ranking));
    }

    for (auto &auto_thread : autos) {
        auto_thread.join();
    }

    std::cout << "\nRanking final:\n";
    for (int i = 0; i < num_autos; ++i) {
        std::cout << "Posición " << ranking[i] << ": Auto " << i << std::endl;
    }

    return 0;
}
