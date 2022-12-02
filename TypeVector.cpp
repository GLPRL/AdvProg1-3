/**
 TypeVector holds 3 members.
 Double vector.
 a name/type as string.
 and a distance.
*/
#include "Algorithms.h"
#include "TypeVector.h"
using namespace std;
    /**
    calculates distance between this vector and another vector.
     does distance calculations in accordance to received string
    */
    void TypeVector::calculateDistance(vector<double> v1, string distanceType) {
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

TypeVector::TypeVector(vector<double> v, string type) {
        this->type = type;
        this->v = v;
    }

    double TypeVector::getDistance() {
        return distance;
    }

    string TypeVector::getType() {
        return type;
    }

    vector<double> TypeVector::getVector() {
        return v;
    }

    bool  TypeVector::operator<(TypeVector v) const {
        return distance < v.getDistance();
    }
