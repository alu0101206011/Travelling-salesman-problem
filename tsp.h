/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 2 Jan 2021
/// @brief This file declares the Tsp class and a struct that is used by an attribute.

/// @struct NextNode
/// @brief This struct stores successor node info.
struct NextNode;

typedef std::vector<NextNode> Candidates;

/// @class Tsp (Travelling salesman problem)
/// @brief This class makes a graph to build the shortest path 
/// that passes through all the nodes.
class Tsp {
 private:
  unsigned number_nodes_;  // Total number of nodes
  std::vector<Candidates> graph_;  // Vectors vector of successor nodes
  std::vector<unsigned> solution_;  // Solution path
 public:
  /// Constructor
  /// @param file
  /// @param flag sends a nonzero number if the constructor ends with
  /// an error.
  Tsp(const std::string& file, int& error, int directed);

  /// Default destructor
  ~Tsp();

  unsigned get_number_nodes(void) const;
  std::vector<Candidates> get_graph(void) const;

  void set_number_nodes(const unsigned);
  void set_graph(const std::vector<Candidates>);

  /// @brief Method to find the shortest path that passes through all 
  /// the nodes.
  /// @param distance This parameter return the minimal distance (The value 
  /// of this variable will be totally modified).
  /// @return The minimal path. If minimal path contains some zero, the path could
  /// not be found.
  std::vector<unsigned> GreedyAlgorithm(float& distance, int initial_node);

  /// @brief Method with improved algorithm to find the optimal solution
  /// @param distance This is the final result
  /// @param initial_node 
  std::vector<unsigned> ImprovedAlgorithm(float& distance, int initial_node);
  

  /// @brief Write the graph
  void write(void) const;

 private:
  /// @brief Recursive algorithim uses backtracking to get the optimal solution
  /// @param visited Vector with visited nodes
  /// @param currPos Current node
  /// @param count This is the value of nodes that have been visited
  /// @param cost distance to reach the next node
  /// @param new_distance final distance
  /// @param initial_node 
  /// @param path current path
  void RecursiveAlgorithm(std::vector<bool> &visited, int currPos, int count, float cost, 
                          float &new_distance, int initial_node, std::vector<unsigned> path);
};

struct NextNode {
	unsigned node; // node of next node
	float distance; // edge distance between parent node and child node
};