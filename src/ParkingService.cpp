#include "ParkingService.h"

#include <chrono>
#include <string>

#include "PricingFactory.h"

ParkingService::ParkingService(ParkingLot& lot)
    : lot(lot), nextTicketId(1) {}

Ticket ParkingService::parkVehicle(std::shared_ptr<Vehicle> vehicle) {
    ParkingSpot* spot = lot.findAvailableSpot(vehicle->getSize());
    if (spot == nullptr) {
        throw LotFullException("No available spot for vehicle size");
    }

    spot->setOccupied(true);

    // Ticket expects shared_ptr<ParkingSpot> but spots are owned by ParkingLot.
    // Use a non-owning shared_ptr so Ticket can reference the spot safely
    // while lifetime stays with the lot.
    std::shared_ptr<ParkingSpot> spotPtr(spot, [](ParkingSpot*) {});

    Ticket ticket(std::to_string(nextTicketId),
                  std::move(vehicle),
                  std::move(spotPtr),
                  std::chrono::system_clock::now());
    tickets.emplace(nextTicketId, ticket);
    ++nextTicketId;
    return ticket;
}

std::size_t ParkingService::ticketCount() const {
    return tickets.size();
}

Receipt ParkingService::unparkVehicle(int ticketId) {
    auto it = tickets.find(ticketId);
    if (it == tickets.end()) {
        throw InvalidTicketException("Invalid or already-used ticket: " + std::to_string(ticketId));
    }

    Ticket ticket = it->second;
    const auto now = std::chrono::system_clock::now();
    const std::chrono::duration<double> elapsed = now - ticket.getEntryTime();
    const double durationHours = elapsed.count() / 3600.0;

    auto strategy = PricingFactory::create(ticket.getVehicle()->getSize());
    const double amount = strategy->calculateFee(durationHours);

    ticket.getSpot()->setOccupied(false);
    tickets.erase(it);

    return Receipt{ticketId, durationHours, amount};
}
