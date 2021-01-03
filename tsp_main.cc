/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 4 Jan 2021
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

const std::string kHelpText = "hola";

void Usage(int, char**);

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  int error = 0;
  const std::string hola(argv[1]);
  Tsp experiment(hola, error);
  if (error) {
    std::cout << "The file could not be opened.\n";
  }
  float distance = 0;
  std::cout << "Path: 1";
  for (unsigned element : experiment.Path(distance) ) {
    std::cout << "-" << element;
  }
  std::cout << "\nDistance: " << distance << "km\n";
  return 0;
}

void Usage(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " *.txt\n";
    std::cout << "Try " << argv[0] << " --help for more information.\n";
    exit(1);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help" || parameter == "-h") {
    std::cout << kHelpText << std::endl;
    exit(1);
  } 
}