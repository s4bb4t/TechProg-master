#ifndef LOCALNETWORK_H
#define LOCALNETWORK_H

#include <iostream>
#include <string>
using namespace std;

class LocalNetwork {
protected:
    string networkName;
    double installationCost;

public:
    LocalNetwork(string name = "Unnamed", double cost = 0.0);
    virtual ~LocalNetwork();
    virtual void showDetails() const = 0;
    virtual double calculateInstallationCost() const = 0;
};

class PeerToPeerNetwork : private LocalNetwork {
private:
    int numberOfNodes;

public:
    PeerToPeerNetwork(string name, double cost, int nodes);
    void showDetails() const override;
    double calculateInstallationCost() const override;
    friend double computeIndicator(const PeerToPeerNetwork& network);
};

class ClientServerNetwork : private LocalNetwork {
private:
    int numberOfClients;

public:
    ClientServerNetwork(string name, double cost, int clients);
    void showDetails() const override;
    double calculateInstallationCost() const override;
    friend double computeIndicator(const ClientServerNetwork& network);
};

#endif // LOCALNETWORK_H
