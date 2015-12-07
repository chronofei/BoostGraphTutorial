#include "create_k2_graph.h"
#include "create_empty_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
create_k2_graph() noexcept
{
  auto g = create_empty_undirected_graph();
  const auto vertex_descriptor_a = boost::add_vertex(g);
  const auto vertex_descriptor_b = boost::add_vertex(g);
  const auto edge_insertion_result
    = boost::add_edge(vertex_descriptor_a, vertex_descriptor_b, g);
  assert(edge_insertion_result.second);
  return g;
}

