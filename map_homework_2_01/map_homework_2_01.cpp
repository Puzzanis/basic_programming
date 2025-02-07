#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

using namespace std::chrono_literals;
int maxClients = 10;
std::atomic_int clientCounter = 0;

void clientThread() {
    while (clientCounter < maxClients)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clientCounter.fetch_add(1, std::memory_order_seq_cst);
        std::cout << "Клиет присоединился, Всего клиетов: " << clientCounter << std::endl;
    }
}

void operatorThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (clientCounter > 0)
        {
            clientCounter.fetch_sub(1, std::memory_order_seq_cst);
            std::cout << "Оператор обслужил клиета. Количество клиетов: " << clientCounter << std::endl;
        }
        else
        {
            std::cout << "Оператор закончил свою работу. Количество клиетов: " << clientCounter << std::endl;
            break;
        }
    }
}

int main() {
    setlocale(0, "");

    std::thread client(clientThread);
    std::thread operatorT(operatorThread);

    client.join();
    operatorT.join();

    return 0;
}
