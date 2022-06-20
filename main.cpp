#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "BST.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 1;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
    }

    bool isInt = false;
    BST<int>* intBST = NULL;
    BST<string>* stringBST = NULL;
    BST<int>* intBSTCopy = NULL;
    BST<string>* stringBSTCopy = NULL;

    for (string line; getline(in, line);) {
        try {
            string commandLine, itemValue;
            if (line.size() == 0) continue;

            istringstream iss(line);
            iss >> commandLine;

            if (commandLine == "INT") {
                if (intBST == NULL){
                    delete intBST;
                    intBST = new BST<int>;
                    out << commandLine << " OK" << endl;
                }
                else {
                    delete intBST;
                    intBST = new BST<int>;
                    out << commandLine << " OK" << endl;
                }

                isInt = true;
            }
            else if (commandLine == "STRING") {
                if (stringBST == NULL){
                    delete stringBST;
                    stringBST = new BST<string>;
                    out << commandLine << " OK" << endl;
                }
                else {
                    delete stringBST;
                    stringBST = new BST<string>;
                    out << commandLine << " OK" << endl;
                }
                isInt = false;
            }
            else if (commandLine == "add") {
                iss >> itemValue;
                out << commandLine << " " << itemValue << " ";

                if (isInt) {
                    intBST->addNode(stoi(itemValue));
                    out << "OK" << endl;
                }
                else{
                    stringBST->addNode(itemValue);
                    out << "OK" << endl;

                }

            }
            else if (commandLine == "remove") {
                iss >> itemValue;
                out << commandLine << " " << itemValue << " ";

                if (isInt){
                    intBST->removeNode(stoi(itemValue));
                }
                else {
                    stringBST->removeNode(itemValue);
                }
                out << "OK" << endl;

            }
            else if (commandLine == "clear") {
                out << commandLine << " ";
                if (isInt){
                    intBST->clearTree();
                }
                else {
                    stringBST->clearTree();
                }
                out << "OK" << endl;
            }
            else if (commandLine == "print") {
                out << commandLine << " ";
                if (isInt){
                    if (intBST == NULL) out << "Error";
                    else out << intBST->toString();
                }
                else {
                    if (stringBST == NULL) out << "Error";
                    else out << stringBST->toString();
                }
                out << endl;
            }
            else if (commandLine == "size") {
                out << commandLine << " ";
                if (isInt){
                    out << intBST->size() << endl;
                }
                else {
                    out << stringBST->size() << endl;
                }
            }
            else if (commandLine == "find") {
                iss >> itemValue;
                out << commandLine << " " << itemValue << " ";
                if (isInt){
                    intBST->find(stoi(itemValue));
                }
                else {
                    stringBST->find(itemValue);
                }
                out << "found" << endl;

            }
            else if (commandLine == "copy") {
                out << commandLine << " ";
                if (isInt) {
                    if (intBST == NULL) out << "Error" << endl;
                    else {
                        if (intBSTCopy != NULL ) intBSTCopy->clearTree();
                        delete intBSTCopy;

                        intBSTCopy = new BST<int>(*intBST);
                        out << "OK" << endl;
                    }
                }

                else {
                    if (stringBST == NULL) {
                        out << "Error" << endl;
                    }
                    else {
                        if (stringBSTCopy != NULL) stringBSTCopy->clearTree();
                        delete stringBSTCopy;
                        stringBSTCopy = new BST<string>(*stringBST);
                        out << "OK" << endl;
                    }
                }
            }
            else if (commandLine == "printcopy") {
                out << commandLine << " ";
                if (isInt){
                    if (intBSTCopy == NULL) out << "Error" << endl;
                    else out << intBSTCopy->toString();
                }
                else {
                    if (stringBSTCopy == NULL) out << "Error" << endl;
                    else out << stringBSTCopy->toString();
                }
                out << endl;

            }
            else if (commandLine == "tree") {
                out << line;
            }
        }
        catch (string error) {
            out << error << endl;
        }


    }
    delete intBST;
    delete stringBST;
    delete intBSTCopy;
    delete stringBSTCopy;

    in.close();
    out.close();

    in.open(argv[2]);

    string line;
    if (in.is_open()) {
        while (getline(in, line)) {
            try {
                //if (line.empty()) continue;
                cout << line << endl;
            } catch (exception &e) { cout << e.what(); }
        }
    } else cout << "Unable to read from output file." << endl;
    in.close();
    return 0;
}
