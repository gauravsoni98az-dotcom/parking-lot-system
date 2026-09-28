#pragma once

#include <chrono>
#include <memory>
#include <string>

#include "ParkingSpot.h"
#include "Vehicle.h"

class Ticket {
public:
    Ticket(std::string ticketId,
           std::shared_ptr<Vehicle> vehicle,
           std::shared_ptr<ParkingSpot> spot,
           std::chrono::system_clock::time_point entryTime);

    const std::string& getTicketId() const;
    std::shared_ptr<Vehicle> getVehicle() const;
    std::shared_ptr<ParkingSpot> getSpot() const;
    std::chrono::system_clock::time_point getEntryTime() const;

private:
    std::string ticketId;
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<ParkingSpot> spot;
    std::chrono::system_clock::time_point entryTime;
};
