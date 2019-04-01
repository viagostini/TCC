#include <hayai/hayai.hpp>
#include "../code/include/Tree.hpp"
#include "../code/include/TableAlgorithm.hpp"

using namespace hayai;

int size = 7;
vector<Edge> edges = {
    make_edge(0, 1),
    make_edge(0, 2),
    make_edge(0, 3),
    make_edge(2, 4),
    make_edge(2, 5),
    make_edge(3, 6)
};

// BENCHMARK(Tree, Creation, 10, 1) {
//     vector<Edge> lotsOfEdges{};
//     for (int i = 1; i < 100000; i++)
//         lotsOfEdges.push_back(make_pair(0, i));
//     Tree tree(lotsOfEdges.size()+1, edges);
// }

BENCHMARK(TableAlgorithm, Creation, 1, 1) {
    vector<Edge> lotsOfEdges{};
    for (int i = 1; i < 20000; i++)
        lotsOfEdges.push_back(make_pair(0, i));
    Tree tree(lotsOfEdges.size()+1, edges);
    TableAlgorithm table(tree);
}

int main () {
    ConsoleOutputter consoleOutputter;
    Benchmarker::AddOutputter(consoleOutputter);
    Benchmarker::RunAllTests();
}