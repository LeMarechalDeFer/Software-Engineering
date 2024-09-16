#include <iostream>
#include <thread>
#include <string>
#include <mutex> // Pour utiliser un mutex
#include <chrono> // Pour std::this_thread::sleep_for

std::mutex coutMutex; // Mutex global pour synchroniser l'accès à std::cout

void doTask(std::string task) {
    for (int i = 0; i < 10; i++) {
        {
            // Utiliser lock_guard pour protéger l'accès à std::cout
            std::lock_guard<std::mutex> guard(coutMutex);
            std::cout << "Tache numéro : " << i << " - " << task << std::endl;
        }
        // Petite pause pour permettre aux threads de s'alterner
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    std::cout << "Debut programme" << std::endl;

    // Lancer deux threads
    std::thread thread1(doTask, "Travailler");
    std::thread thread2(doTask, "Dormir");

    // Attendre que les threads se terminent
    thread1.join();
    thread2.join();

    std::cout << "Fin programme" << std::endl;

    return 0;
}
