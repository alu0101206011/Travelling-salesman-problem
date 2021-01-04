/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 3 Jan 2021
/// @brief Tsp methods implementation

#include <iostream>
#include <fstream>
#include <vector>
#include <cfloat>

#include "tsp.h"

// Constructor
Tsp::Tsp(const std::string& file, int& flag) {
  std::ifstream reader(file, std::ios::in);
  if (!reader) {
    flag = 1;  // No works
    return;
  }
  NextNode aux;
  unsigned index;
  reader >> number_nodes_;
  reader >> number_edges_;
  reader >> directed_;

  graph_.resize(number_nodes_);

  int first_place, second_place;

  for (unsigned i = 0; i < number_edges_; i++) {
    if (directed_) {
      reader >> index;
      reader >> aux.node;
      reader >> aux.distance;
      graph_[index - 1].push_back(aux);
    } else {
      reader >> first_place;
      reader >> second_place;
      reader >> aux.distance;
      aux.node = second_place;
      graph_[first_place - 1].push_back(aux);
      aux.node = first_place;
      graph_[second_place - 1].push_back(aux);
    }
  }
  reader.close();
}

// Default destructor
Tsp::~Tsp() {}

unsigned Tsp::get_number_nodes(void) const { return number_nodes_; }
unsigned Tsp::get_number_edges(void) const { return number_edges_; }
unsigned Tsp::get_directed(void) const { return directed_; }

void Tsp::set_number_nodes(const unsigned kNewNumberNode) { 
  number_nodes_ = kNewNumberNode; 
}
void Tsp::set_number_edges(const unsigned kNewNumberEdges) { 
  number_edges_ = kNewNumberEdges; 
}
void Tsp::set_directed(const unsigned kNewDirected) { 
  directed_ = kNewDirected; 
}

// Method to find the shortest path that passes through all the nodes.
std::vector<unsigned> Tsp::Path(float& distance) const {
  distance = 0;
  float min_distance = FLT_MAX;
  std::vector<unsigned> solution(number_nodes_);
  std::vector<bool> visited(number_nodes_,false);
  unsigned current_node = 0, next_node = 0, counter = 0;
  visited[0] = true;

  while (current_node < graph_.size() && 
         next_node < graph_[current_node].size() && 
         solution.size() != counter) {

    if (solution.size() - 1 == counter) visited[0] = false;  // Unblock the start node
    if (graph_[current_node][next_node].node != current_node + 1 && 
        !visited[graph_[current_node][next_node].node - 1])
      if (graph_[current_node][next_node].distance < min_distance) {
        min_distance = graph_[current_node][next_node].distance;
        solution[counter] = graph_[current_node][next_node].node;
      }
    next_node++;
    if (next_node == graph_[current_node].size()) {
      distance += min_distance;
      min_distance = FLT_MAX;
      visited[solution[counter] - 1] = true;
      next_node = 0;
      current_node = solution[counter] - 1;
      counter++;
    }
  }
  return solution;
}

// Write the graph
void Tsp::write(void) const {
  std::cout << "List:\n";
  for (int i = 0; i < graph_.size(); i++) {
    std::cout << "Node [" << i + 1 << "] : ";
    if (graph_[i].size() == 0) std::cout << "NULL  ";
    for (int j = 0; j < graph_[i].size(); j++)
      std::cout << graph_[i][j].node << " ";
    std::cout << "\n";
  }
}