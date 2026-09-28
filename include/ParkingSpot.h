#pragma once

#include "Vehicle.h"

class ParkingSpot {
public:
    ParkingSpot(int spotId, int floor, VehicleSize size);

    int getSpotId() const;
    int getFloor() const;
    VehicleSize getSize() const;
    bool isOccupied() const;
    void setOccupied(bool occupied);

private:
    int spotId;
    int floor;
    VehicleSize size;
    bool occupied;
};
