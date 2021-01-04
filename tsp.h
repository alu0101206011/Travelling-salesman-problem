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

/// @class Tsp (Travelling seller problem)
/// @brief This class makes a graph to build the shortest path 
/// that passes through all the nodes.
class Tsp {
 private:
  unsigned number_nodes_;  // Total number of nodes
	unsigned number_edges_;  // Total number of edges
	bool directed_;  // It is true if is a directed graph
  std::vector<Candidates> graph_;  // Vectors vector of successor nodes
 public:
  /// Constructor
  /// @param file
  /// @param flag sends a nonzero number if the constructor ends with
  /// an error.
  Tsp(const std::string& file, int& flag);

  /// Default destructor
  ~Tsp();

  unsigned get_number_nodes(void) const;
  unsigned get_number_edges(void) const;
  unsigned get_directed(void) const;

  void set_number_nodes(const unsigned);
  void set_number_edges(const unsigned);
  void set_directed(const unsigned);

  /// @brief Method to find the shortest path that passes through all 
  /// the nodes.
  /// @param distance This parameter return the minimal distance (The value 
  /// of this variable will be totally modified).
  /// @return The minimal path. If minimal path contains some zero, the path could
  /// not be found.
  std::vector<unsigned> Path(float& distance) const;

  /// @brief Write the graph
  void write(void) const;
};

struct NextNode {
	unsigned node; // node of next node
	float distance; // edge distance between parent node and child node
};