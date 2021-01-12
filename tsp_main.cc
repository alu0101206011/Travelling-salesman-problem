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

void Usage(int, char **);

/// Main function
/// @param[in] argc Number of command line parameters
/// @param[in] argv Vector containing (char*) the parameters
int main(int argc, char *argv[]) {
  Usage(argc, argv);
  int error = 0;
  const std::string infile(argv[1]);
  Tsp experiment(infile, error, atoi(argv[2]));
  if (error) {
    std::cout << "The file could not be opened.\n";
    return 1;
  }
  experiment.write();
  int initial_node = 1; // If you change this value, the program will searches paths that begin at this number
  float distance = 0;
  std::cout << "Greedy solution = {" << initial_node;
  for (unsigned element : experiment.GreedyAlgorithm(distance, initial_node)) {
    std::cout << ", " << element;
  }
  std::cout << "}";
  std::cout << "\nDistance: " << distance << "km\n";

  std::cout << "Improved solution = {" << initial_node;
  for (unsigned element : experiment.ImprovedAlgorithm(distance, initial_node)) {
    std::cout << ", " << element;
  }
  std::cout << "}";
  std::cout << "\nDistance: " << distance << "km\n";
  return 0;
}

/// @brief Funtion that show the usage of this program
/// @param[in] argc Number of command line parameters
/// @param[in] argv Vector containing (char*) the parameters
void Usage(int argc, char *argv[])
{
  if (argc != 3 && argc != 2) {
    std::cout << "Usage: " << argv[0] << " [FILE] [ISDIRECTED]\n";
    std::cout << "Try " << argv[0] << " --help for more information.\n";
    exit(1);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help" || parameter == "-h") {
    std::cout << "Usage: " << argv[0] << " [FILE] [ISDIRECTED]"
              << "\n\n\t[FILE] This file should content this graph sintax:"
              << "\n\t\t3 // Cities number\n\t\t1 2 3.4  // Start_city "
              << "Goal_city Weight\n\t\t1 3 4.5  // Start_city Goal_city"
              << " Weight\n\t\t2 3 5.6  // Start_city Goal_city Weight\n\n\t"
              << "[ISDIRECTED]\n\t\tPut 1 if it is a directed graph\n\t\tPut 0 "
              << "if it isn't a directed graph\n\nThis program show the "
              << "shortest path that passes through all the nodes.\n";
    exit(0);
  } else if (argc == 3 && atoi(argv[2]) != 1 && atoi(argv[2]) != 0) {
    std::cout << "Usage: " << argv[0] << " [FILE] [ISDIRECTED]\n";
    std::cout << "Try " << argv[0] << " --help for more information.\n";
    exit(1);  
  } 
}