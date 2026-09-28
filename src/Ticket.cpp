#include "Ticket.h"

#include <utility>

Ticket::Ticket(std::string ticketId,
               std::shared_ptr<Vehicle> vehicle,
               std::shared_ptr<ParkingSpot> spot,
               std::chrono::system_clock::time_point entryTime)
    : ticketId(std::move(ticketId)),
      vehicle(std::move(vehicle)),
      spot(std::move(spot)),
      entryTime(entryTime) {}

const std::string& Ticket::getTicketId() const {
    return ticketId;
}

std::shared_ptr<Vehicle> Ticket::getVehicle() const {
    return vehicle;
}

std::shared_ptr<ParkingSpot> Ticket::getSpot() const {
    return spot;
}

std::chrono::system_clock::time_point Ticket::getEntryTime() const {
    return entryTime;
}
