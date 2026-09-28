#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "Bike.h"
#include "Car.h"
#include "ParkingLot.h"
#include "ParkingService.h"
#include "Truck.h"

namespace {

void printMenu() {
    std::cout << "\n=== Parking Lot Menu ===\n"
              << "1. Park a vehicle\n"
              << "2. Unpark a vehicle\n"
              << "3. View available spots\n"
              << "4. Exit\n"
              << "Enter choice: ";
}

bool readInt(int& out) {
    if (std::cin >> out) {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

void handlePark(ParkingService& service) {
    std::cout << "Vehicle type (1=Bike, 2=Car, 3=Truck): ";
    int type = 0;
    if (!readInt(type)) {
        std::cout << "Invalid vehicle type.\n";
        return;
    }
    std::cout << "License plate: ";
    std::string plate;
    std::cin >> plate;

    std::shared_ptr<Vehicle> vehicle;
    switch (type) {
        case 1:
            vehicle = std::make_shared<Bike>(plate);
            break;
        case 2:
            vehicle = std::make_shared<Car>(plate);
            break;
        case 3:
            vehicle = std::make_shared<Truck>(plate);
            break;
        default:
            std::cout << "Unknown vehicle type.\n";
            return;
    }

    try {
        Ticket ticket = service.parkVehicle(std::move(vehicle));
        auto spot = ticket.getSpot();
        std::cout << "Parked. Ticket ID: " << ticket.getTicketId()
                  << ", Spot: " << spot->getSpotId()
                  << " (Floor " << spot->getFloor() << ")\n";
    } catch (const LotFullException& e) {
        std::cout << "Lot is full: " << e.what() << "\n";
    }
}

void handleUnpark(ParkingService& service) {
    std::cout << "Ticket ID: ";
    int ticketId = 0;
    if (!readInt(ticketId)) {
        std::cout << "Invalid ticket ID.\n";
        return;
    }
    try {
        Receipt receipt = service.unparkVehicle(ticketId);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Unparked. Ticket " << receipt.ticketId
                  << ", Duration: " << receipt.durationHours << " hrs"
                  << ", Amount: Rs." << receipt.amount << "\n";
    } catch (const InvalidTicketException& e) {
        std::cout << "Invalid ticket: " << e.what() << "\n";
    }
}

void handleView(const ParkingLot& lot) {
    const auto& floors = lot.getFloors();
    std::cout << "Available spots:\n";
    for (std::size_t f = 0; f < floors.size(); ++f) {
        int small = 0, medium = 0, large = 0;
        for (const auto& spot : floors[f]) {
            if (spot.isOccupied()) {
                continue;
            }
            switch (spot.getSize()) {
                case VehicleSize::SMALL:
                    ++small;
                    break;
                case VehicleSize::MEDIUM:
                    ++medium;
                    break;
                case VehicleSize::LARGE:
                    ++large;
                    break;
            }
        }
        std::cout << "  Floor " << f << ": " << small << " SMALL, "
                  << medium << " MEDIUM, " << large << " LARGE free ("
                  << (small + medium + large) << " total)\n";
    }
}

}  // namespace

int main() {
    ParkingLot lot(2, 9);
    ParkingService service(lot);

    while (true) {
        printMenu();
        int choice = 0;
        if (!readInt(choice)) {
            std::cout << "Invalid choice. Enter 1-4.\n";
            continue;
        }
        switch (choice) {
            case 1:
                handlePark(service);
                break;
            case 2:
                handleUnpark(service);
                break;
            case 3:
                handleView(lot);
                break;
            case 4:
                std::cout << "Goodbye.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Enter 1-4.\n";
                break;
        }
    }
}
