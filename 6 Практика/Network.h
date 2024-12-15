#pragma once
#include <iostream>
#include <iomanip>
#include <string>

namespace Network {

class LocalNetwork {
protected:
    std::string networkName;
    double installationCost;
    int networkSpeed;
    static int totalNetworks;

public:
    LocalNetwork(std::string name = "Default Network", double cost = 0.0, int speed = 0)
        : networkName(name), installationCost(cost), networkSpeed(speed) {
        ++totalNetworks;
    }

    virtual ~LocalNetwork() { --totalNetworks; }

    virtual void showDetails() const = 0;

    virtual double calculateInstallationCost() const = 0;

    virtual double calculateInstallationCost(double discount) const {
        return installationCost * (1 - discount);
    }

    static int getTotalNetworks() { return totalNetworks; }

    std::string getNetworkName() const { return networkName; }
};

int LocalNetwork::totalNetworks = 0;

class PeerToPeerNetwork : public LocalNetwork {
private:
    int numberOfNodes;
    bool isEncrypted;
    static std::string networkType;

public:
    PeerToPeerNetwork(std::string name = "P2P Network", double cost = 0.0, int speed = 0, int nodes = 0, bool encrypted = false)
        : LocalNetwork(name, cost, speed), numberOfNodes(nodes), isEncrypted(encrypted) {}

    void showDetails() const override {
        std::cout << std::setw(20) << networkName << std::setw(15) << installationCost
                  << std::setw(15) << networkSpeed << std::setw(10) << numberOfNodes
                  << std::setw(10) << (isEncrypted ? "Yes" : "No") << std::endl;
    }

    double calculateInstallationCost() const override {
        return installationCost + numberOfNodes * 10;
    }

    double calculateInstallationCost(double discount) const override {
        return LocalNetwork::calculateInstallationCost(discount) + numberOfNodes * 10;
    }

    static std::string getNetworkType() { return networkType; }

    friend bool operator<(const PeerToPeerNetwork& lhs, const PeerToPeerNetwork& rhs) {
        return lhs.calculateInstallationCost() < rhs.calculateInstallationCost();
    }
};

std::string PeerToPeerNetwork::networkType = "Peer-to-Peer";

class ClientServerNetwork : private LocalNetwork {
private:
    int numberOfClients;
    bool hasFirewall;
    static std::string networkType;

public:
    ClientServerNetwork(std::string name = "CS Network", double cost = 0.0, int speed = 0, int clients = 0, bool firewall = false)
        : LocalNetwork(name, cost, speed), numberOfClients(clients), hasFirewall(firewall) {}

    void showDetails() const override {
        std::cout << std::setw(20) << networkName << std::setw(15) << installationCost
                  << std::setw(15) << networkSpeed << std::setw(10) << numberOfClients
                  << std::setw(10) << (hasFirewall ? "Yes" : "No") << std::endl;
    }

    double calculateInstallationCost() const override {
        return installationCost + numberOfClients * 20 + (hasFirewall ? 50 : 0);
    }

    double calculateInstallationCost(double discount) const override {
        return LocalNetwork::calculateInstallationCost(discount) + numberOfClients * 20 + (hasFirewall ? 50 : 0);
    }

    static std::string getNetworkType() { return networkType; }

    friend bool operator<(const ClientServerNetwork& lhs, const ClientServerNetwork& rhs) {
        return lhs.calculateInstallationCost() < rhs.calculateInstallationCost();
    }
};

std::string ClientServerNetwork::networkType = "Client-Server";

} // namespace Network
