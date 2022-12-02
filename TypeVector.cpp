/**
 TypeVector holds 3 members.
 Double vector.
 a name/type as string.
 and a distance.
*/
#include "Algorithms.h"

using namespace std;

class TypeVector {
    vector<double> v;
    string type;
    double distance;

public:
    /**
    calculates distance between this vector and another vector.
     does distance calculations in accordance to received string
    */
    void calculateDistance(vector<double> v1, string distanceType) {
        if (distanceType.compare("AUC") == 0) {
            distance = euclidean(v, v1);
        } else if (distanceType.compare("MAN") == 0) {
            distance = manhattan(v, v1);
        } else if (distanceType.compare("CHB") == 0) {
            distance = chebyshev(v, v1);
        } else if (distanceType.compare("CAN") == 0) {
            distance = canberra(v, v1);
        } else if (distanceType.compare("MIN") == 0) {
            distance = minkowski(v, v1);
        }

    }

    TypeVector(vector<double> v, string type) {
        this->type = type;
        this->v = v;
    }

    double getDistance() {
        return distance;
    }

    string getType() {
        return type;
    }

    bool operator<(TypeVector v) {
        return distance < v.getDistance();
    }
};