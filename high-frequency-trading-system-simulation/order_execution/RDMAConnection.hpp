#pragma once

#ifndef RDMA_CONNECTION_HPP
#define RDMA_CONNECTION_HPP

#include <iostream>

/// The RDMAConnection class simulates a Remote Direct Memory Access (RDMA) connection
/// for communication between the order execution engine and the exchange.
class RDMAConnection {
public:
    RDMAConnection() : connected(false) {}

    // Connect to the remote exchange server
    bool connect() {
        std::cout << "Establishing RDMA connection..." << std::endl;
        connected = true;  // Simulate a successful connection
        return connected;
    }

    // Disconnect from the remote exchange server
    void disconnect() {
        if (connected) {
            std::cout << "Closing RDMA connection..." << std::endl;
            connected = false;
        }
    }

    // Check if the RDMA connection is established
    bool isConnected() const {
        return connected;
    }

private:
    bool connected; // Connection status
};

#endif // RDMA_CONNECTION_HPP
