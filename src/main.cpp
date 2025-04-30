/**
 * @file main.cpp
 * @author Seth Moore (slmoore@hamilton.edu)
 * @brief Program for converting graph files to METIS format
 * @date 2025-04-30
 * 
 */
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include <cstdint>
#include <iostream>
#include <string>

#include "graph.h"
#include "utility.h"

const char* short_options = "f:h";

const static struct option long_options[] = {
    {"file", required_argument, nullptr, 'f'},
    {"help", no_argument, nullptr, 'h'},
    {0, 0, 0, 0}
};

static inline void print_usage() {
    puts("usage: ./metis -f FILE");
}

int main(int argc, char** argv) {
    std::string file_path = "";
    int option_index = 0;
    char opt;

    while ((opt = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (opt) {
        case 'f':
            file_path = optarg;
            break;
        case 'h':
            print_usage();
            return EXIT_SUCCESS;
        default:
            return EXIT_FAILURE;
        }
    }

    if (file_path.empty()) {
        print_usage();
        return EXIT_FAILURE;
    }

    Graph<uint64_t> graph = read_graph_from_file(file_path);
    write_metis_file_from_graph(
        graph,
        get_file_path_without_extension(file_path) + ".metis");
}