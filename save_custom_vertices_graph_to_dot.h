#ifndef SAVE_CUSTOM_VERTICES_GRAPH_TO_DOT_H
#define SAVE_CUSTOM_VERTICES_GRAPH_TO_DOT_H

#if __cplusplus >= 201402L //C++17
#include "save_custom_vertices_graph_to_dot_cpp17.impl"
#else
#include "save_custom_vertices_graph_to_dot_cpp14.impl"
#endif

void save_custom_vertices_graph_to_dot_test() noexcept;

#endif // SAVE_CUSTOM_VERTICES_GRAPH_TO_DOT_H
