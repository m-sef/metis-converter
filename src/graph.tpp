/**
 * @file graph.tpp
 * @author Seth Moore (slmoore@hamilton.edu)
 * @brief Graph implementation
 * @date 2025-04-30
 * 
 */
#include "graph.h"

template<typename T>
Graph<T>::Graph()
{
    _adjacency_list = {};
    _node_count = 0;
    _edge_count = 0;
}

template<typename T>
Graph<T>::Graph(
    const std::initializer_list<std::initializer_list<T>> init_list)
{
    _adjacency_list = std::vector<std::set<T>>(init_list.size());

    _node_count = init_list.size();
    _edge_count = 0;

    size_t u = 0;
    for (const auto& list : init_list)
    {
        for (const auto& v : list)
            add_edge(u, v);

        u++;
    }
}

template<typename T>
Graph<T>::Graph(const size_t n)
{
    _adjacency_list = std::vector<std::set<T>>(n);
    _node_count = n;
    _edge_count = 0;
}

template<typename T>
void Graph<T>::add_edge(const size_t u, const size_t v)
{
    assert(u < _node_count);
    assert(v < _node_count);

    if (has_edge(u, v) && has_edge(v, u))
        return;

    _adjacency_list[u].emplace(v);
    _adjacency_list[v].emplace(u);
    
    _edge_count++;
}

template<typename T>
bool Graph<T>::has_edge(const size_t u, const size_t v) const
{
    assert(u < _node_count);
    assert(v < _node_count);

    return (_adjacency_list[u].find(v) != _adjacency_list[u].end());
}

template<typename T>
const std::set<T>& Graph<T>::nodes_incident_to(const size_t u) const
{
    assert(u < _node_count);

    return _adjacency_list[u];
}

template<typename T>
size_t Graph<T>::degree(const size_t u) const
{
    assert(u < _node_count);
    
    return _adjacency_list[u].size();
}

template<typename T>
size_t Graph<T>::node_count() const
{
    return _node_count;
}

template<typename T>
size_t Graph<T>::edge_count() const
{
    return _edge_count;
}

template<typename T>
typename Graph<T>::iterator Graph<T>::begin()
{
    return _adjacency_list.begin();
}

template<typename T>
typename Graph<T>::iterator Graph<T>::end()
{
    return _adjacency_list.end();
}

template<typename T>
typename Graph<T>::const_iterator Graph<T>::begin() const
{
    return _adjacency_list.begin();
}

template<typename T>
typename Graph<T>::const_iterator Graph<T>::end() const
{
    return _adjacency_list.end();
}