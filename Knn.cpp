//
// Created by Dekel on 02/12/2022.
//
#include "Algorithms.h"
#include "TypeVector.cpp"
#include <algorithm>
#include <map>


string knnAlgo(vector<TypeVector> vectorArray, int k, vector<string> typeNames) {
    vector<TypeVector> neighbours;
    map<string, int> names;
    for (int i = 0; i < typeNames.size(); i++) {
        names.insert(pair<string, int>(typeNames[i], 0));
    }
    sort(vectorArray.begin(), vectorArray.end());
    for (int i = 0; i < k; i++) {
        names.at(vectorArray[i].getType())++;
    }
    int max = -1;
    string maxString;
    for (map<string, int>::iterator it = names.begin(); it != names.end(); it++) {
        if (it->second > max) {
            max = it->second;
            maxString = it->first;
        }
    }
    return maxString;
}