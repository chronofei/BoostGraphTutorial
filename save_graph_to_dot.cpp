#include "save_graph_to_dot.h"

#include <iostream>
#include <sstream>

#include "fileio.h"
#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_router_network_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "is_valid_dot_file.h"

void save_graph_to_dot_test() noexcept
{
  ribi::FileIo f;
  //create_empty_directed_graph
  {
    const auto g = create_empty_directed_graph();
    const std::string base_filename{"create_empty_directed_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      f.FileToVector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "digraph G {",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    f.CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    f.CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
  }
  //create_empty_undirected_graph
  {
    const auto g = create_empty_undirected_graph();
    const std::string base_filename{"create_empty_undirected_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      f.FileToVector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    f.CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    f.CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
  }
  //create_k2_graph
  {
    const auto g = create_k2_graph();
    const std::string base_filename{"create_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      f.FileToVector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "0;",
      "1;",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    f.CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    f.CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    //show_dot(filename);
  }
  //Show it does not store the vertex names
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string base_filename{"save_graph_to_dot_test_named_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      f.FileToVector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "0;",
      "1;",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    f.CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    f.CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
  }
  std::cout << __func__ << ": OK" << '\n';
}
