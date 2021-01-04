/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 2 Jan 2021
/// @brief 
///
/// @see https://en.wikipedia.org/wiki/Greedy_algorithm
/// @see https://en.wikipedia.org/wiki/Travelling_salesman_problem
///
/// To compile: make
/// To clean files: make clean
/// To debug g++ -g --std=c++17 -o tsp tsp_main.cc tsp.cc

#include <iostream>
#include <string>
#include <vector>

#include "tsp.h"

const std::string kHelpText = "";

void Usage(int, char**);

/// Main function
/// @param[in] argc Number of command line parameters
/// @param[in] argv Vector containing (char*) the parameters
int main(int argc, char *argv[]) {
  Usage(argc, argv);
  int error = 0;
  const std::string infile(argv[1]);
  Tsp experiment(infile, error);
  if (error) {
    std::cout << "The file could not be opened.\n";
    return 1;
  }
  experiment.write();
  float distance = 0;
  std::cout << "Path: 1";
  for (unsigned element : experiment.Path(distance) ) {
    std::cout << "-" << element;
  }
  std::cout << "\nDistance: " << distance << "km\n";
  return 0;
}

/// @brief Funtion that show the usage of this program
/// @param[in] argc Number of command line parameters
/// @param[in] argv Vector containing (char*) the parameters
void Usage(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " [FILE]\n";
    std::cout << "Try " << argv[0] << " --help for more information.\n";
    exit(1);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help" || parameter == "-h") {
    std::cout << "Usage: " << argv[0] << " [FILE]" << "\nThis program show the "
              << "shortest path that passes through all the nodes.\n";
    exit(0);
  }
}