/// @class NextNode
///
/// @brief 
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 31 Dic 2020
struct NextNode {
	unsigned node; // nodo
	float distance; // atributo para expresar su peso, longitud, coste...
  
};

typedef std::vector<NextNode> Candidates;

/// @class Tsp
///
/// @brief 
///
class Tsp {
 private:
  unsigned number_nodes_;
	unsigned number_edges_;
	unsigned directed_;  // almacena 0 si el grafo es no dirigido, 1 eoc
  std::vector<Candidates> graph_;
 public:
  Tsp(const std::string& text, int& flag);
  ~Tsp();

  unsigned get_number_nodes(void) const;
  unsigned get_number_edges(void) const;
  unsigned get_directed(void) const;

  void set_number_nodes(const unsigned);
  void set_number_edges(const unsigned);
  void set_directed(const unsigned);

  std::vector<unsigned> Path(float&);
  //GreedyFuntion

  void write(void) const;
};


/*
función voraz(C: conjunto): conjunto { // C es el conjunto de candidatos
  S <- Ø // conjunto de la solución
  mientras C ≠ Ø y no solución(S) hacer {
    x <- seleccionar(C)
    C <- C - {x} // quitamos x de C
    si factible(S ∪ {x}) entonces
    S <- S ∪ {x}
  }
  si solución(S) entonces devolver S
  en otro caso devolver NO_HAY_SOLUCIÓN
}
*/

