#include "BikePricing.h"

#include <algorithm>
#include <cmath>

double BikePricing::calculateFee(double durationHours) {
    if (durationHours <= 0.0) {
        return 0.0;
    }
    const double days = std::ceil(durationHours / 24.0);
    const double raw = kRatePerHour * durationHours;
    return std::min(raw, kDailyCap * days);
}
