#include "Network.h"

namespace Network {

int LocalNetwork::totalNetworks = 0;  // Инициализация статического члена

LocalNetwork::LocalNetwork(std::string name, double cost, int speed)
    : networkName(name), installationCost(cost), networkSpeed(speed) {
    totalNetworks++;
}

LocalNetwork::~LocalNetwork() {
    totalNetworks--;
}

int LocalNetwork::getTotalNetworks() {
    return totalNetworks;
}

std::string LocalNetwork::getNetworkName() const {
    return networkName;
}

PeerToPeerNetwork::PeerToPeerNetwork(std::string name, double cost, int speed, int nodes, bool encrypted)
    : LocalNetwork(name, cost, speed), numberOfNodes(nodes), isEncrypted(encrypted) {}

void PeerToPeerNetwork::showDetails() const {
    std::cout << "Сетевое подключение: " << networkName << "\n";
    std::cout << "Тип сети: Одноранговая (Peer-to-Peer)\n";
    std::cout << "Скорость сети: " << networkSpeed << " Мбит/с\n";
    std::cout << "Количество узлов: " << numberOfNodes << "\n";
    std::cout << "Шифрование данных: " << (isEncrypted ? "Да" : "Нет") << "\n";
    std::cout << "Стоимость установки: " << installationCost << " руб.\n\n";
}

double PeerToPeerNetwork::calculateInstallationCost(double discount) const {
    double cost = installationCost * numberOfNodes;
    return cost - (cost * discount);  // Применение скидки
}

bool PeerToPeerNetwork::operator<(const LocalNetwork& other) const {
    const PeerToPeerNetwork* otherNetwork = dynamic_cast<const PeerToPeerNetwork*>(&other);
    if (otherNetwork) {
        return installationCost < otherNetwork->installationCost;
    }
    return false;
}

ClientServerNetwork::ClientServerNetwork(std::string name, double cost, int speed, int clients, bool firewall)
    : LocalNetwork(name, cost, speed), numberOfClients(clients), hasFirewall(firewall) {}

void ClientServerNetwork::showDetails() const {
    std::cout << "Сетевое подключение: " << networkName << "\n";
    std::cout << "Тип сети: Клиент-серверная\n";
    std::cout << "Скорость сети: " << networkSpeed << " Мбит/с\n";
    std::cout << "Количество клиентов: " << numberOfClients << "\n";
    std::cout << "Наличие фаервола: " << (hasFirewall ? "Да" : "Нет") << "\n";
    std::cout << "Стоимость установки: " << installationCost << " руб.\n\n";
}

double ClientServerNetwork::calculateInstallationCost(double discount) const {
    double cost = installationCost * numberOfClients;
    return cost - (cost * discount);  // Применение скидки
}

bool ClientServerNetwork::operator<(const LocalNetwork& other) const {
    const ClientServerNetwork* otherNetwork = dynamic_cast<const ClientServerNetwork*>(&other);
    if (otherNetwork) {
        return installationCost < otherNetwork->installationCost;
    }
    return false;
}

}
