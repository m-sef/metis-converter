/**
 * @file utility.h
 * @author Seth Moore (slmoore@hamilton.edu)
 * @date 2025-04-30
 * 
 */
#include "utility.h"

std::string get_file_path_without_extension(
    const std::string& file_path)
{
    std::regex pattern("(.+?)(\\.[^.]*$|$)");
    std::smatch match;

    if (std::regex_search(file_path, match, pattern))
        return match.str(1);

    return "";
}

Graph<uint64_t> read_graph_from_file(
    const std::string& file_path)
{
    std::ifstream file(file_path);
    std::string line = "";

    getline(file, line);

    std::istringstream sstream(line);
    std::string node_count_as_str = "";
    std::string edge_count_as_str = "";

    sstream >> node_count_as_str;
    sstream >> edge_count_as_str;

    size_t node_count = std::stoi(node_count_as_str);
    size_t edge_count = std::stoi(edge_count_as_str);

    Graph<uint64_t> graph(node_count);

    std::unordered_map<size_t, size_t> remapped_vertices;
    size_t current_remapped_vertex = 0;

    std::cout << node_count << std::endl;
    std::cout << edge_count << std::endl;

    while (getline(file, line))
    {
        std::string node_u_as_str = "";
        std::string node_v_as_str = "";

        sstream.str(line);

        sstream >> node_u_as_str;
        sstream >> node_v_as_str;

        uint64_t u = std::stoi(node_u_as_str);
        uint64_t v = std::stoi(node_v_as_str);

        // Ignore self-loops
        if (u == v)
            continue;

        if (remapped_vertices.find(u) == remapped_vertices.end())
        {
            remapped_vertices[u] = current_remapped_vertex;
            current_remapped_vertex++;
        }

        if (remapped_vertices.find(v) == remapped_vertices.end())
        {
            remapped_vertices[v] = current_remapped_vertex;
            current_remapped_vertex++;
        }

        graph.add_edge(remapped_vertices[u], remapped_vertices[v]);
    }

    return graph;
}

void write_metis_file_from_graph(
    const Graph<uint64_t>& graph,
    const std::string& file_path)
{
    std::ofstream file(file_path);
    
    file << graph.node_count() << " " << graph.edge_count() << std::endl;

    for (size_t u = 0; u < graph.node_count(); u++)
    {
        for (const auto& v : graph.nodes_incident_to(u))
            file << (v + 1) << " ";
        file << std::endl;
    }
}