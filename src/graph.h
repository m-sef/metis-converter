/**
 * @file graph.h
 * @author m_sef (https://github.com/m-sef)
 * @brief Graph implementation
 * @date 2025-04-30
 * 
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cassert>
#include <algorithm>
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

template<typename T>
class Graph {
    typedef typename std::vector<std::set<T>>::iterator iterator;
    typedef typename std::vector<std::set<T>>::const_iterator const_iterator;
public:
    Graph();
    Graph(const std::initializer_list<std::initializer_list<T>> init_list);
    Graph(const size_t n);

    void add_edge(const size_t u, const size_t v);
    bool has_edge(const size_t u, const size_t v) const;
    const std::set<T>& nodes_incident_to(const size_t u) const;

    size_t degree(const size_t u) const;
    size_t node_count() const;
    size_t edge_count() const;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
protected:
    std::vector<std::set<T>> _adjacency_list;
    size_t _node_count;
    size_t _edge_count;
};

#include "graph.tpp"

#endif