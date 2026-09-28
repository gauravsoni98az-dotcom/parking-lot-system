#pragma once

#include <vector>

#include "ParkingSpot.h"
#include "Vehicle.h"

class ParkingLot {
public:
    ParkingLot(int numFloors, int spotsPerFloor);

    ParkingSpot* findAvailableSpot(VehicleSize size);

    int getNumFloors() const;
    const std::vector<std::vector<ParkingSpot>>& getFloors() const;

private:
    std::vector<std::vector<ParkingSpot>> floors;
};
