#pragma once

#include <memory>
#include <unordered_map>

#include "InvalidTicketException.h"
#include "LotFullException.h"
#include "ParkingLot.h"
#include "Receipt.h"
#include "Ticket.h"
#include "Vehicle.h"

class ParkingService {
public:
    explicit ParkingService(ParkingLot& lot);

    Ticket parkVehicle(std::shared_ptr<Vehicle> vehicle);
    Receipt unparkVehicle(int ticketId);

    std::size_t ticketCount() const;

private:
    ParkingLot& lot;
    std::unordered_map<int, Ticket> tickets;
    int nextTicketId;
};
