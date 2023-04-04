#include <iostream>
#include <string>
#include <sstream>
using namespace std;

    std::string longAdd(std::string a, std::string b);
    std::string longSubtract(std::string a, std::string b);
    std::string longMultiply(std::string a, std::string b);
    //std::string longDivide(std::string a, std::string b);

int main() {
	string strOne, strTwo, out, opp, inputR;
    while (true) {
        std::cout << "this program can add subtract multiply and divide numbers " <<
            "both smaller and larger than an integer can store" << endl << "using strings and arrays" << endl << endl;
        system("PAUSE");
        system("CLS");

        std::cout << "enter string 1" << endl;
        cin >> strOne;
        std::cout << "enter opperator (+ - * /)" << endl;
        cin >> opp;
        std::cout << "enter string 2" << endl;
        cin >> strTwo;

        if (opp == "+") {
            out = longAdd(strOne, strTwo);
        }
        else if (opp == "-") {
            out = longSubtract(strOne, strTwo);
        }
        else if (opp == "*") {
            out = longMultiply(strOne, strTwo);
        }
        /*
        else if (opp == "/") {
            out = longDivide(strOne, strTwo);
        }
        */
        else {
            std::cout << "opperator " << opp << " is not a valid opperator" << endl;
        }

        std::cout << strOne << " " << opp << " " << strTwo << " = " << out << endl;
        bool breakTest = false;

        while (true) {
            std::cout << "would you like to restart yes/no" << endl;
            std::cin >> inputR;
            if (inputR == "no") {
                breakTest = true;
                break;
            }
            else if (inputR != "yes" && inputR != "no") {
                std::cout << "try again";
            }
        }
        system("CLS");
        if (breakTest) {
            break;
        }
    }
}





std::string longAdd(std::string a, std::string b) {
    int arrA[100]{}, arrB[100]{}, arrF[100]{}, rollover, start{}, aLength = 0, bLength = 0, maxL;
    bool testforzero = false;
    std::string F, err, tStr;

    maxL = 100;// << this number should be the same as declared space of arr's above

    for (int i = 0; i < maxL; i++) {//initialize arrays
        arrA[i] = 0;
        arrB[i] = 0;
        arrF[i] = 0;
    }
    
    for (int i = 0; a[i] != NULL; i++) {//test length of a
        aLength = i + 1;
    }

    for (int i = 0; b[i] != NULL; i++) {//test length of b
        bLength = i + 1;
    }

    if (aLength > maxL) {//return error if a is of greater length than the length of the array
        err = "string 1 is greater than ";
        std::stringstream ss;
        ss << maxL;
        ss >> tStr;
        err += tStr;
        return err;
    }
    if (bLength > maxL) {//return error if b is of greater length than the length of the array
        err = "string 2 is greater than ";
        std::stringstream ss;
        ss << maxL;
        ss >> tStr;
        err += tStr;
        return err;
    }

    for (int i = aLength; i > 0; i--) {//input a into arr
        std::stringstream ss;
        ss << a[i - 1];
        ss >> arrA[((maxL - 1) - aLength) + i];
    }

    for (int i = bLength; i > 0; i--) {//input b into arr
        std::stringstream ss;
        ss << b[i - 1];
        ss >> arrB[((maxL - 1) - bLength) + i];
    }

    for (int i = (maxL - 1); i >= 0; i--) {//math functionality
        arrF[i] = arrA[i] + arrB[i] + arrF[i];

        if (arrF[i] > 9) {
            rollover = arrF[i] / 10;
            arrF[i - 1] = arrF[i - 1] + rollover;
            arrF[i] = arrF[i] - (rollover * 10);
        }
    }

    for (int i = 0; i < maxL && testforzero == false; i++) {//find the index of the start of the output
        if (arrF[i] != 0) {
            testforzero = true;
            start = i;
        }
    }

    for (int i = start; i < maxL; i++) {//transfer output from arr to str
        std::stringstream ss;
        std::string n;
        ss << arrF[i];
        ss >> n;
        F += n;
    }

    if (testforzero == true) {//return
        return F;
    }
}




std::string longSubtract(std::string a, std::string b) {
    int arrA[100]{}, arrB[100]{}, arrF[100]{}, rollover, start{}, aLength = 0, bLength = 0, maxL;
    bool testforzero = false;
    std::string F, err, tStr;

    maxL = 100;// << this number should be the same as declared space of arr's above

    for (int i = 0; i < maxL; i++) {//initialize arrays
        arrA[i] = 0;
        arrB[i] = 0;
        arrF[i] = 0;
    }

    for (int i = 0; a[i] != NULL; i++) {//test length of a
        aLength = i + 1;
    }

    for (int i = 0; b[i] != NULL; i++) {//test length of b
        bLength = i + 1;
    }

    if (aLength > maxL) {//return error if a is of greater length than the length of the array
        err = "string 1 is greater than ";
        std::stringstream ss;
        ss << maxL;
        ss >> tStr;
        err += tStr;
        return err;
    }
    if (bLength > maxL) {//return error if b is of greater length than the length of the array
        err = "string 2 is greater than ";
        std::stringstream ss;
        ss << maxL;
        ss >> tStr;
        err += tStr;
        return err;
    }

    for (int i = aLength; i > 0; i--) {//input a into arr
        std::stringstream ss;
        ss << a[i - 1];
        ss >> arrA[((maxL - 1) - aLength) + i];
    }

    for (int i = bLength; i > 0; i--) {//input b into arr
        std::stringstream ss;
        ss << b[i - 1];
        ss >> arrB[((maxL - 1) - bLength) + i];
    }

    for (int i = (maxL - 1); i >= 0; i--) {//math functionality
        bool breaktest = true;
        if (arrA[i] < arrB[i]) {//borrow function
            for (int n = 1; n <= (i - aLength) && breaktest; n++) {
                if (arrA[i - n] != 0) {
                    arrA[i - n] = arrA[i - n] - 1;
                    for (int l = 1; l <= n; l++) {
                        breaktest = false;
                        if (n = l) {
                            arrA[i] = arrA[i] + 10;
                        }
                        else {
                            arrA[(i - n) + l] = arrA[(i - n) + l] + 9;
                        }
                    }
                }
            }
        }
        arrF[i] = arrA[i] - arrB[i];
    }

    for (int i = 0; i < maxL && testforzero == false; i++) {//find the index of the start of the output
        if (arrF[i] != 0) {
            testforzero = true;
            start = i;
        }
    }

    for (int i = start; i < maxL; i++) {//transfer output from arr to str
        std::stringstream ss;
        std::string n;
        ss << arrF[i];
        ss >> n;
        F += n;
    }

    if (testforzero == true) {//return
        return F;
    }
}




std::string longMultiply(std::string a, std::string b) {
    int arrA[100]{}, arrB[100]{}, arrF[2 * 100]{}, rollover, start{}, aLength = 0, bLength = 0, maxL;
    bool testforzero = false;
    std::string F, err, tStr;

    maxL = 100;// << this number should be the same as declared space of arr's above

    for (int i = 0; i < maxL; i++) {//initialize arrays
        arrA[i] = 0;
        arrB[i] = 0;
        arrF[i] = 0;
    }

    for (int i = 0; a[i] != NULL; i++) {//test length of a
        aLength = i + 1;
    }

    for (int i = 0; b[i] != NULL; i++) {//test length of b
        bLength = i + 1;
    }

    if (aLength > maxL) {//return error if a is of greater length than the length of the array
        err = "string 1 is greater than ";
        std::stringstream ss;
        ss << maxL;
        ss >> tStr;
        err += tStr;
        return err;
    }
    if (bLength > maxL) {//return error if b is of greater length than the length of the array
        err = "string 2 is greater than ";
        std::stringstream ss;
        ss << maxL;
        ss >> tStr;
        err += tStr;
        return err;
    }

    for (int i = aLength; i > 0; i--) {//input a into arr
        std::stringstream ss;
        ss << a[i - 1];
        ss >> arrA[((maxL - 1) - aLength) + i];
    }

    for (int i = bLength; i > 0; i--) {//input b into arr
        std::stringstream ss;
        ss << b[i - 1];
        ss >> arrB[((maxL - 1) - bLength) + i];
    }
    for (int i = (maxL - 1); i >= 0; i--) {//math functionality
            if (aLength >= bLength) {
                for (int n = maxL - 1; n >= (maxL - 1) - aLength; n--) {
                    arrF[n] = (arrB[i] * arrA[n]) + arrF[n];
                }
            }
            else if (bLength > aLength) {
                for (int n = maxL - 1; n >= (maxL - 1) - bLength; i--) {
                    arrF[n] = (arrA[i] * arrB[n]) + arrF[n];
                }
            }
    }
    for (int i = ((maxL * 2) - 1); i >= 0; i--) {//math functionality
        if (arrF[i] > 9) {
            rollover = arrF[i] / 10;
            arrF[i - 1] = arrF[i - 1] + rollover;
            arrF[i] = arrF[i] - (rollover * 10);
        }
    }

    for (int i = 0; i < maxL && testforzero == false; i++) {//find the index of the start of the output
        if (arrF[i] != 0) {
            testforzero = true;
            start = i;
        }
    }

    for (int i = start; i < maxL; i++) {//transfer output from arr to str
        std::stringstream ss;
        std::string n;
        ss << arrF[i];
        ss >> n;
        F += n;
    }

    if (testforzero == true) {//return
        return F;
    }
}



/*
std::string longDivide(std::string a, std::string b) {

}
*/