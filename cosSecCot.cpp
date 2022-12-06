// Copyright (c) 2022 Peter Sobowale All rights reserved.
// Created by: Peter Sobowale
// Created on: Dec 1, 2022
// This program asks the user if they want to calculate for an angle or decimal
// It then asks if they want to use sin, cos, tan, csc, sec or cot
#include <cmath>
#include <iomanip>
#include <iostream>


double DegreeToAngSin(float x) {
    // angle = arcsin(x) in radians
    double sinAngle = asin(x) * (180 / M_PI);

    // returns sin_angle in degrees
    return sinAngle;
}


double DegreeToAngCos(float x) {
    // angle = arccos(x) in radians
    double cosAngle = acos(x) * (180 / M_PI);

    // returns cosAngle in degrees
    return cosAngle;
}


double DegreeToAngTan(float x) {
    // angle = arctan(x) in radians
    double tanAngle = atan(x) * (180 / M_PI);

    // returns tanAngle in degrees
    return tanAngle;
}


double DegreeToAngCsc(float x) {
    x = 1 / x;
    // angle = arccsc(x) in radians
    double cscAngle = asin(x) * (180 / M_PI);

    // returns cscAngle in degrees
    return cscAngle;
}


double DegreeToAngSec(float x) {
    x = 1 / x;
    // angle = arcsec(x) in radians
    double secAngle = acos(x) * (180 / M_PI);

    // returns cscAngle in degrees
    return secAngle;
}


double DegreeToAngCot(float x) {
    // arccot(x) = arctan(1 / x)
    x = 1 / x;
    // angle = arccot(x) in radians
    double cotAngle = atan(x) * (180 / M_PI);

    // returns cscAngle in degrees
    return cotAngle;
}


// function to calculate sin(x)
double CalSin(float x) {
    // declare variables
    int i;

    // convert from degrees to radians
    x = x * (M_PI / 180);

    // set t and sum to equal x
    double t = x;
    double sin = x;

    // for loop to calculate the value of sin using the sine series
    for (i = 1; i <= 10; i++) {
        t = (t * (-1) * x * x) / (2 * i * (2 * i + 1));
        sin = sin + t;
    }

    // return sum aka.what sin(x) is equal to
    return sin;
}


// function to calculate cos(x)
double CalCosine(float x) {
    // declare variables
    double cosine = 0;
    double t = 1;
    int i;

    // if statement for values 270 or 90 because the program won't calculate 0
    if (x == 270) {
        return cosine;
    } else if (x == 90) {
        return cosine;
    } else {
        // declare variables
        cosine = 1;

        // change from degrees to radians
        x = x * M_PI / 180;

        // for loop to calculate the value of Cosine using cosine series
        for (i = 1; i <= 10; i++) {
            t = t * (-1) * x * x / (2 * i * (2 * i - 1));
            cosine = cosine + t;
        }
        return cosine;
    }
}


// function that calculates for tan(x)
double CalTangent(float x) {
    // define variables
    double tangent;

    // calculate tangent using return values of sin(x) and cos(x)
    // tan(x) = sin(x) / cos(x)
    tangent = CalSin(x) / CalCosine(x);

    // return the value of tangent
    return tangent;
}


// function that calculates for csc(x)
double CalCosecant(float x) {
    double cosecant;
    // calculates cosecant using return value of sin(x)
    // csc(x) = 1 / sin(x)
    cosecant = 1 / CalSin(x);

    // return the value of cosecant
    return cosecant;
}


// function that calculates sec(x)
double CalSecant(float x) {
    // declare variables
    double secant;

    // calculates secant using return value of cos(x)
    // sec(x) = 1 / cos(x)
    secant = 1 / CalCosine(x);

    // return the value of secant
    return secant;
}


// function that calculates cot(x)
double CalCotangent(float x) {
    // declare variables
    double cotangent;

    // calculates cotangent using the return vales of sin(x) and cos(x)
    // cot(x) = cos(x) / sin(x)
    cotangent = CalCosine(x) / CalSin(x);

    // return the value of cotangent
    return cotangent;
}


// main function does input and output and checks erroneous data
int main() {
    // set replay to equal 'y'
    char replay = 'y', angOrDec;
    std::string operation, xString;
    int check;
    float xFloat;
    double sine, cosine, tangent, cosecant, secant, cotangent, sin;

    // while loop to loop until user says to stop
    while (replay == 'y') {
        // set operation check to false
        bool operationCheck = false;
        // while loop that runs as long as operation check is false
        while (operationCheck == false) {
            // display choices to the user
            std::cout << "\nChoose from one of the following options:";
            std::cout << "\n \t [1]"
                      << " Solve for Sine \n \t "
                      << "[2] Solve for Cosine"
                      << " \n \t"
                      << " [3] Solve for Tangent \n \t "
                      << "[4] Solve for Cosecant"
                      << " \n \t"
                      << " [5] Solve for Secant \n \t "
                      << "[6] Solve for Cotangent";

            // get operation from user
            std::cout << "\nEnter your selection: ";
            std::cin >> operation;

            // try to make sure no value or operation other than 1-6 is accepted
            try {
                check = std::stoi(operation);
                if (check >= 1 && check <= 6) {
                    operationCheck = true;
                } else {
                    operationCheck = false;
                }
            } catch (std::bad_exception) {
                operationCheck = false;
            }
        }
        // get ang_or_dec to determine what user is solving for
        std::cout << "Do you want to find an angle or decimal place (A/D): ";
        std::cin >> angOrDec;
        std::cout << "\n";

        if (angOrDec == 'a' || angOrDec == 'A') {
            // get input for x_string
            std::cout << "Enter what you want to calculate: ";
            std::cin >> xString;

            try {
                xFloat = std::stof(xString);
                if (xFloat != 0) {
                    // solve sine for angle
                    if (check == 1) {
                        // make sure input is from 1 to - 1
                        if (xFloat < 1 && xFloat > -1) {
                            // assign sine to the function return
                            sine = DegreeToAngSin(xFloat);
                            std::cout << "The value of sin(" << sine
                            << ") = " << xFloat << std::
                            endl;
                        } else {
                            std::cout << "What you enter must be"
                            << "less than 1 and greater than -1." << std::endl;
                        }
                    } else if (check == 2) {
                        // make sure input is from 1 to - 1
                        if (xFloat < 1 && xFloat > -1) {
                            // assign sine to the function return
                            cosine = DegreeToAngSin(xFloat);

                            // display output
                            std::cout << "The value of cos(" << std::fixed
                            << std::setprecision(2) << std::setfill('0')
                            << cosine << ") = " << xFloat << std::endl;

                        } else {
                            std::cout << "What you enter must be"
                            << "less than 1 and greater than -1." << std::endl;
                        }
                    } else if (check == 3) {
                        // assign tangent to the function return
                        tangent = DegreeToAngTan(xFloat);

                        // display the equation
                        std::cout << "The value of tan(" << std::fixed
                        << std::setprecision(2) << std::setfill('0')
                        << tangent << ") = " << xFloat << " "
                        << std::endl;

                    } else if (check == 4) {
                        // assign cosecant to the function return
                        cosecant = DegreeToAngCsc(xFloat);

                        // display the equation
                        std::cout << "The value of csc(" << std::fixed
                        << std::setprecision(2) << std::setfill('0')
                        << cosecant << ") = " << xFloat << " "
                        << std::endl;

                    } else if (check == 5) {
                        // assign secant to the function return
                        secant = DegreeToAngSec(xFloat);

                        // display the equation
                        std::cout << "The value of sec(" << std::fixed
                        << std::setprecision(2) << std::setfill('0')
                        << secant << ") = " << xFloat << " "
                        << std::endl;

                    } else if (check == 6) {
                        // assign cosecant to the function return
                        cotangent = DegreeToAngCot(xFloat);

                        // display the equation
                        std::cout << "The value of cot(" << std::fixed
                        << std::setprecision(2) << std::setfill('0')
                        << cotangent << ") = " << xFloat << " "
                        << std::endl;
                    }
                } else {
                    std::cout << "Your number cannot be zero." << std::endl;
                }
            } catch (std::invalid_argument) {
                std::cout << xString << " isn't a real number." << std::endl;
            }
        } else if (angOrDec == 'd' || angOrDec == 'D') {
            // get xString from the user
            std::cout << "Enter the value of x (in degrees): ";
            std::cin >> xString;

            // try catch to check x is float
            try {
                xFloat = std::stof(xString);
                // solve sine for decimal
                if (check == 1) {
                    // make sure x_float is less than 360
                    if (xFloat < 360) {
                        // assign sin to the function return
                        sin = CalSin(xFloat);
                        std::cout << "The value of sin(" << xFloat
                        << ") = " << std::fixed << std::setprecision(4)
                        << std::setfill('0') << sin << std::endl;

                    } else {
                        // erroneous data
                        std::cout << "The angle you enter must "
                        << "be less than 360. " << std::endl;
                    }

                } else if (check == 2) {
                    // make sure x_float is less than 360
                    if (xFloat < 360) {
                        // assign cosine to the function return
                        cosine = CalCosine(xFloat);
                        std::cout << "The value of cos(" << xFloat
                        << ") = " << std::fixed << std::setprecision(4)
                        << std::setfill('0') << cosine << std::endl;

                    } else {
                        // erroneous data
                        std::cout << "The angle you enter must "
                        << "be less than 360. " << std::endl;
                    }
                } else if (check == 3) {
                    // make sure x_float is less than 360
                    if (xFloat < 360) {
                        // assign tangent to the function return
                        tangent = CalTangent(xFloat);
                        std::cout << "The value of tan(" << xFloat
                        << ") = " << std::fixed << std::setprecision(4)
                        << std::setfill('0') << tangent << std::endl;

                    } else {
                        // erroneous data
                        std::cout << "The angle you enter must "
                        << "be less than 360. " << std::endl;
                    }

                } else if (check == 4) {
                    // make sure x_float is less than 360
                    if (xFloat < 360) {
                        // assign cosecant to the function return
                        cosecant = CalCosecant(xFloat);
                        std::cout << "The value of csc(" << xFloat
                        << ") = " << std::fixed << std::setprecision(4)
                        << std::setfill('0') << cosecant << std::endl;

                    } else {
                        // erroneous data
                        std::cout << "The angle you enter must "
                        << "be less than 360. " << std::endl;
                    }

                } else if (check == 5) {
                    // make sure x_float is less than 360
                    if (xFloat < 360) {
                        // assign secant to the function return
                        secant = CalSecant(xFloat);
                        std::cout << "The value of sec(" << xFloat
                        << ") = " << std::fixed << std::setprecision(4)
                        << std::setfill('0') << secant << std::endl;

                    } else {
                        // erroneous data
                        std::cout << "The angle you enter must "
                        << "be less than 360. " << std::endl;
                    }

                } else if (check == 6) {
                    // make sure x_float is less than 360
                    if (xFloat < 360) {
                        // assign cotangent to the function return
                        cotangent = CalCotangent(xFloat);
                        std::cout << "The value of cot(" << xFloat
                        << ") = " << std::fixed << std::setprecision(4)
                        << std::setfill('0') << cotangent << std::endl;

                    } else {
                        // erroneous data
                        std::cout << "The angle you enter must "
                        << "be less than 360. " << std::endl;
                    }
                }
            } catch (std::invalid_argument) {
                // erroneous data
                std::cout << "Enter in a real number." << std::endl;
            }
        } else {
            // erroneous data
            continue;
        }

        std::cout << " " << std::endl;

        // get replay to see if user still wants to use again
        std::cout << "Do you want to play again (y/n) ? ";
        std::cin >> replay;

        // if replay still = y
        if (replay == 'y') {
            continue;
        } else {
            break;
        }
    }
}
