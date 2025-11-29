/**
 * @file utility.h
 * @author m_sef (https://github.com/m-sef)
 * @date 2025-04-30
 * 
 */
#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <unordered_map>

#include "graph.h"

std::string get_file_path_without_extension(
    const std::string& file_path);

Graph<uint64_t> read_graph_from_file(
    const std::string& file_path);

void write_metis_file_from_graph(
    const Graph<uint64_t>& graph,
    const std::string& file_path);

#endif