#include "ParkingLot.h"

ParkingLot::ParkingLot(int numFloors, int spotsPerFloor) {
    if (numFloors <= 0 || spotsPerFloor <= 0) {
        return;
    }

    // Split each floor across sizes: ~1/3 SMALL, ~1/3 MEDIUM, rest LARGE.
    const int numSmall = spotsPerFloor / 3;
    const int numMedium = spotsPerFloor / 3;

    floors.reserve(numFloors);
    for (int floor = 0; floor < numFloors; ++floor) {
        std::vector<ParkingSpot> spots;
        spots.reserve(spotsPerFloor);
        for (int i = 0; i < spotsPerFloor; ++i) {
            VehicleSize size;
            if (i < numSmall) {
                size = VehicleSize::SMALL;
            } else if (i < numSmall + numMedium) {
                size = VehicleSize::MEDIUM;
            } else {
                size = VehicleSize::LARGE;
            }
            const int spotId = floor * spotsPerFloor + i;
            spots.emplace_back(spotId, floor, size);
        }
        floors.push_back(std::move(spots));
    }
}

ParkingSpot* ParkingLot::findAvailableSpot(VehicleSize size) {
    // Nearest = lowest floor first, then lowest index on that floor.
    for (auto& floorSpots : floors) {
        for (auto& spot : floorSpots) {
            if (!spot.isOccupied() && spot.getSize() == size) {
                return &spot;
            }
        }
    }
    return nullptr;
}

int ParkingLot::getNumFloors() const {
    return static_cast<int>(floors.size());
}

const std::vector<std::vector<ParkingSpot>>& ParkingLot::getFloors() const {
    return floors;
}
