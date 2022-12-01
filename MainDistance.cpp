/**
 Receives two vectors from the user and calculates various types of distances between them.
*/
#include "Algorithms.h"

using namespace std;

/**
 Reads a vector from the user in accordance to the ex1 instructions.
 Prints an error if the input is not as expected.
*/
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
    return v;
}
/**
 * Open a CSV file here. afterwards, we read each line for a new, temp vector,
 * compare the diff using our provided algorithm. If the diff is less than our largest
 * difference, then we replace the old one with the new one. We compare the diff with K differences
 * as requested.
 * After passing over all the items in the CSV, we count each type, and choose the type we had the most
 * occurrences of.
 * @param alg Distance algorithms to use
 * @param k Amount of items to compare.
 * @param v Vector to compare with the CSV file.
 */
void kNearestNeighbors(void *alg, int k, vector<double> v, char *filename) {
    ifstream fin;
    fin.open(filename, ios::in);
}
/**
 * Main function. We receive several command line arguments: 4 in total
 * First: some int K: number of neighbors. K is positive integer
 * Second: some file with suffix .csv , with data of the vectors.
 * We will read the data from each line, which will be a single flower.
 * Third: Our method of calculation. AUC, MAN, CHB, CAN, MIN for each of the algorithms.
 * @return code 0 if works as expected.
 */
int main(int argc, char *argv[]) {
    int k = stoi(argv[1]);
    vector<double> v = readVector();
    //Need to add an IF statement. Send alg as argument to kNearestNeighbors
    if (strcmp(argv[3], "AUC") == 0) {                                                        //User chose Euclidean Alg

    }
    if (strcmp(argv[3], "MAN") == 0) {                                                        //User chose Manhattan Alg

    }
    if (strcmp(argv[3], "CHB") == 0) {                                                        //User chose Chebyshev Alg

    }
    if (strcmp(argv[3], "CAN") == 0) {                                                        //User chose Canberra Alg

    }
    if (strcmp(argv[3], "MIN") == 0) {                                                        //User chose Minkowski Alg

    }
    //I will use the next line to invoke kNearestNeighbors, with respective algorithm/function
    //kNearestNeighbors(, k, v, argv[2]);
    /**
    if (v1.size() != v2.size()) {
        cout << "Error: Vectors are not the same size" << endl;
        exit(-2);
    }
     **/

    //Calculation according to selected algorithm.
    /**
    if (strcmp(argv[3],"AUC")) {
        cout.precision(5);
        cout << euclidean(v1, v2) << endl;
        return 0;
    }
    if (strcmp(argv[3],"MAN")) {
        cout.precision(1);
        cout << fixed << manhattan(v1, v2) << endl;
        return 0;
    }
    if (strcmp(argv[3],"CHB")) {
        cout.precision(1);
        cout << fixed << chebyshev(v1, v2) << endl;
        return 0;
    }
    if (strcmp(argv[3],"CAN")) {
        cout.precision(1);
        cout << fixed << canberra(v1, v2) << endl;
        return 0;

    }
    if (strcmp(argv[3],"MIN")) {
        cout.precision(5);
        cout.unsetf(std::ios_base::floatfield);
        cout << minkowski(v1, v2) << endl;
        return 0;
    }
    cout << "No valid algorithm inserted" << endl;
    return 1;
     **/
}