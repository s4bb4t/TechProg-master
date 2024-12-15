#include "Network.h"

namespace Network {

int LocalNetwork::totalNetworks = 0;
double PeerToPeerNetwork::minimumCost = 1000.0;
double ClientServerNetwork::minimumCost = 2000.0;

LocalNetwork::LocalNetwork(std::string name, double cost, int speed)
    : networkName(name), installationCost(cost), networkSpeed(speed) {
    totalNetworks++;
}

LocalNetwork::~LocalNetwork() {
    totalNetworks--;
}

double LocalNetwork::calculateInstallationCost(double discount) const {
    return calculateInstallationCost() * (1 - discount);
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
    std::cout << "Peer-to-Peer Network: " << networkName << std::endl;
    std::cout << "Installation Cost: $" << installationCost << std::endl;
    std::cout << "Network Speed: " << networkSpeed << " Mbps" << std::endl;
    std::cout << "Number of Nodes: " << numberOfNodes << std::endl;
    std::cout << "Encrypted: " << (isEncrypted ? "Yes" : "No") << std::endl;
}

double PeerToPeerNetwork::calculateInstallationCost() const {
    return installationCost + (numberOfNodes * 50) + (isEncrypted ? 500 : 0);
}

double PeerToPeerNetwork::calculateInstallationCost(double discount) const {
    return LocalNetwork::calculateInstallationCost(discount);
}

double PeerToPeerNetwork::getMinimumCost() {
    return minimumCost;
}

bool operator<(const PeerToPeerNetwork& lhs, const PeerToPeerNetwork& rhs) {
    return lhs.calculateInstallationCost() < rhs.calculateInstallationCost();
}

ClientServerNetwork::ClientServerNetwork(std::string name, double cost, int speed, int clients, bool firewall)
    : LocalNetwork(name, cost, speed), numberOfClients(clients), hasFirewall(firewall) {}

void ClientServerNetwork::showDetails() const {
    std::cout << "Client-Server Network: " << networkName << std::endl;
    std::cout << "Installation Cost: $" << installationCost << std::endl;
    std::cout << "Network Speed: " << networkSpeed << " Mbps" << std::endl;
    std::cout << "Number of Clients: " << numberOfClients << std::endl;
    std::cout << "Firewall: " << (hasFirewall ? "Yes" : "No") << std::endl;
}

double ClientServerNetwork::calculateInstallationCost() const {
    return installationCost + (numberOfClients * 100) + (hasFirewall ? 1000 : 0);
}

double ClientServerNetwork::calculateInstallationCost(double discount) const {
    return LocalNetwork::calculateInstallationCost(discount);
}

double ClientServerNetwork::getMinimumCost() {
    return minimumCost;
}

bool operator<(const ClientServerNetwork& lhs, const ClientServerNetwork& rhs) {
    return lhs.calculateInstallationCost() < rhs.calculateInstallationCost();
}

} // namespace Network