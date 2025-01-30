#include <chrono>
#include <iostream>
#include <thread>



int maxClients = 10;
int clientCounter = 0;

void clientThread() {
    while (clientCounter < maxClients)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clientCounter++;
        std::cout << "Клиет присоединился, Всего клиетов: " << clientCounter << std::endl;
    }
}

void operatorThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (clientCounter > 0)
        {
            clientCounter--;
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
