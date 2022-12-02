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
void kNearestNeighbors(double (*alg)(vector<double>, vector<double>), int k, vector<double> v, char *filename) {
    fstream fin;
    //vector<DiffandType> neighbor;
    fin.open(filename, ios::in);
    vector<string> row;
    string line, word, tmp;
    if (fin.is_open()) {
        while (fin >> tmp) {                                             //Read from file
            row.clear();                                                 //Cleaning the row data before data is inserted
            getline(fin, line);
            stringstream s(line);
            while (getline(fin, line, ',')) {               //Read single line from CSV file
                row.push_back(word);
            }                                                            //After reading a single line, process the data

        }
    } else {
        perror("No such file or directory");
        exit(1);
    }
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
    if (argc != 4) {
        perror("Not enough command line arguments.");
        return -1;
    }
    int k = stoi(argv[1]);
    vector<double> v = readVector();
    //Need to add an IF statement. Send alg as argument to kNearestNeighbors
    if (strcmp(argv[3], "AUC") == 0) {                                                        //User chose Euclidean Alg
        kNearestNeighbors(euclidean, k, v, argv[2]);
    }
    if (strcmp(argv[3], "MAN") == 0) {                                                        //User chose Manhattan Alg

    }
    if (strcmp(argv[3], "CHB") == 0) {                                                        //User chose Chebyshev Alg

    }
    if (strcmp(argv[3], "CAN") == 0) {                                                        //User chose Canberra Alg

    }
    if (strcmp(argv[3], "MIN") == 0) {                                                        //User chose Minkowski Alg

    }
    perror("No valid algorithm inserted");
    return 1;
}