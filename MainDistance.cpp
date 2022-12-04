/**
 Receives two vectors from the user and calculates various types of distances between them.
**/

#include "Algorithms.h"
#include <algorithm>

/**
 * Checks for name duplications.
 * @param name string to compare duplication with
 * @param tv comparing with TypeVector's types attribute
 * @return status if duplicate. 0 if is duplicate, 1 otherwise.
**/
using namespace std;
int isDuplicate(string name, vector<TypeVector> tv) {
    for (int i=0; i < tv.size(); i++) {
        if (tv[i].getType().compare(name) == 0) {
            return 0;
        }
    }
    return 1;
}
/**
 * Getting all the names, disregarding duplicates.
 * @param tv TypeVector array to fetch names from.
 * @return a names vector.
**/
vector<string> getAllNames(vector<TypeVector> tv) {
    vector<string> names;
    int flag = 0;
    for (int i = 0; i < tv.size(); i++) {               //Gets all the types of the TypeVector into a vector of strings.
        string name = tv[i].getType();
        if (!isDuplicate(name, tv)) {
            names.push_back(name);
        }
    }
    return names;
}
/**
 * Checks if the alg of choosing is valid.
 * return 0 if not, otherwise 1.
 * @param alg algorithm of choosing
 * @return T/F if the input of algorithm of choosing is correct
**/
int validateAlg(string alg) {
    if (alg.compare("AUC") == 0) {
        return 1;
    }
    if (alg.compare("MAN") == 0) {
        return 1;
    }
    if (alg.compare("CHB") == 0) {
        return 1;
    }
    if (alg.compare("CAN") == 0) {
        return 1;
    }
    if (alg.compare("MIN") == 0) {
        return 1;
    }
    return 0;
}
/**
 * Reads a vector from the user in accordance to the ex1 instructions.
 * Prints an error if the input is not as expected.
**/
vector<double> readVector() {
    string lin;
    getline(cin, lin);
    lin = ' ' + lin + " ";
    // If there is more than one space in a row, then exit the program.
    if (lin.find("  ") != string::npos) {
        cout << "Error: too many white spaces" << endl;
        exit(-3);
    }
    vector<double> v;
    int pos = 0;
    double x;
    char *e;
    // Loop until the end of the string each time separating the spaces.
    while ((pos = lin.find(" ")) != string::npos) {
        string sub = lin.substr(0, pos);
        x = std::strtod(sub.c_str(), &e);
        if (*e != '\0')
        {
            cout << "Error:" << sub.c_str() << " is not a number" << endl; ;
            exit(-1);
        }
        v.push_back(x);
        lin.erase(0, pos + 1);
    }
    v.erase(v.begin());
    return v;
}
/**
 * Data aggregation. Fetches the data of the vector according to placements. Everything ex. the last item in the vector
 * will be converted to double; the last parameter will be of type string, as it's the name of the item.
 * We also calculate the difference between the new item and a given vector, the return the new TypeVector.
 * @param vectorsString Raw data, as fetched from CSV file
 * @param v User-inputted vector.
 * @param alg Our algorithm of calculation
 * @return a new TypeVector item, inserted into an array of this type.
**/
TypeVector aggregate(vector<string> vectorsString, vector<double> v, string alg) {
    vector<double> vectors;
    for(int i = 0; i < vectorsString.size() - 2; i++) {       //Inserts all the numbers into a new vector of type double
        vectors.push_back(stod(vectorsString[i]));
    }                                                         //Item in last position in vectorsString will be the name!
    string name = vectorsString[vectorsString.size() - 1];
    TypeVector tv = TypeVector(vectors, name);                      //Create the new TypeVector and calc.
    tv.calculateDistance(v, alg);                            // difference according to algorithm.
    return tv;
}
/**
 * Open a CSV file here. We will build an instance of a named vector, contains: name, the actual vector and diff
 * between it and the vector the user chose. We check for compliance in sizes and if the file was successfully opened.
 * @param alg Distance algorithms to use
 * @param k Amount of items to compare.
 * @param v Vector to compare with the CSV file.
**/
vector<TypeVector> readData(string alg, vector<double> v, string filename) {
    fstream fin;
    string line, word, tmp;
    //we need to select the algorithm according to string.
    vector<TypeVector> typeVectors;
    vector<string> row;                                        //Name of type
    vector<double> vectors;                                              //Vector of type
    fin.open(filename, ios::in);
    if (fin.is_open()) {
        while (getline(fin, line)) {                                             //Read from file and process.
            row.clear();                                             //Cleaning the row data before data is inserted
            stringstream str(line);
            while (getline(str, word, ',')) {              //Read single line from CSV file into string arr
                row.push_back(word);
            }
            if (row.size() - 1 != v.size()) {
                perror("Vectors are not of same size.");
            }                                                            //Inserts the new TypeVector into an array.
            TypeVector tVector = aggregate(row, v, alg);
            typeVectors.push_back(tVector);
        }
    } else {
        perror("No such file or directory");
        exit(1);
    }
    fin.close();
    return typeVectors;
}
/**
 * Main function. We receive several command line arguments: 4 in total
 * First: some int K: number of neighbors. K is positive integer
 * Second: some file with suffix .csv , with data of the vectors.
 * We will read the data from each line, which will be a single flower.
 * Third: Our method of calculation. AUC, MAN, CHB, CAN, MIN for each of the algorithms.
 * @return code 0 if works as expected.
**/
int main(int argc, char *argv[]) {
    if (argc != 4) {                                                //If we don't have enough cmd line args
        perror("Not enough command line arguments.");
        return -1;
    }
    if (validateAlg(argv[3]) != 1) {                            //Validation of correct user input for algorithm
        perror("Invalid algorithm name input.");
        return -1;
    }
    for (int i = 0; i < strlen(argv[1]); i++) {                     //Validation that K is an int
        if (isdigit(argv[1][i]) == false) {
            perror("Second parameter must be an integer.");
            return -1;
        }
    }
    int k = stoi(argv[1]);
    vector<double> v = readVector();
    vector<TypeVector> tv = readData(argv[3], v, argv[2]);
    vector<string> names = getAllNames(tv);
    cout << knnAlgo(tv, k, names) << endl;
    return 0;
}
