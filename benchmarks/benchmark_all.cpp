#include <benchmark/benchmark.h>
#include <algorithm>
#include "dsa/Array.hpp"
#include "dsa/LinkedList.hpp"
#include "dsa/Stack.hpp"
#include "dsa/Queue.hpp"
#include "dsa/Tree.hpp"
#include "dsa/Graph.hpp"
#include "dsa/HashMap.hpp"

// Array Benchmarks
static void BM_ArrayPushBack(benchmark::State& state) {
    dsa::DynamicArray<int> arr;
    for (auto _ : state) {
        arr.push_back(1);
        benchmark::DoNotOptimize(arr);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ArrayPushBack)->Range(1<<10, 1<<18)->Complexity();

static void BM_ArrayPopBack(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::DynamicArray<int> arr;
        for (int i = 0; i < state.range(0); ++i) {
            arr.push_back(i);
        }
        state.ResumeTiming();
        
        for (int i = 0; i < state.range(0) && !arr.empty(); ++i) {
            arr.pop_back();
            benchmark::DoNotOptimize(arr);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ArrayPopBack)->Range(1<<10, 1<<18)->Complexity();

// LinkedList Benchmarks
static void BM_LinkedListPushBack(benchmark::State& state) {
    dsa::LinkedList<int> list;
    for (auto _ : state) {
        list.push_back(1);
        benchmark::DoNotOptimize(list);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinkedListPushBack)->Range(1<<10, 1<<18)->Complexity();

static void BM_LinkedListPopBack(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::LinkedList<int> list;
        for (int i = 0; i < state.range(0); ++i) {
            list.push_back(i);
        }
        state.ResumeTiming();
        
        for (int i = 0; i < state.range(0) && !list.empty(); ++i) {
            list.pop_back();
            benchmark::DoNotOptimize(list);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinkedListPopBack)->Range(1<<10, 1<<18)->Complexity();

// Stack Benchmarks
static void BM_StackPush(benchmark::State& state) {
    dsa::Stack<int> stack;
    for (auto _ : state) {
        stack.push(1);
        benchmark::DoNotOptimize(stack);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_StackPush)->Range(1<<10, 1<<18)->Complexity();

static void BM_StackPop(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::Stack<int> stack;
        for (int i = 0; i < state.range(0); ++i) {
            stack.push(i);
        }
        state.ResumeTiming();
        
        for (int i = 0; i < state.range(0) && !stack.empty(); ++i) {
            stack.pop();
            benchmark::DoNotOptimize(stack);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_StackPop)->Range(1<<10, 1<<18)->Complexity();

// Queue Benchmarks
static void BM_QueueEnqueue(benchmark::State& state) {
    dsa::Queue<int> queue;
    for (auto _ : state) {
        queue.enqueue(1);
        benchmark::DoNotOptimize(queue);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_QueueEnqueue)->Range(1<<10, 1<<18)->Complexity();

static void BM_QueueDequeue(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::Queue<int> queue;
        for (int i = 0; i < state.range(0); ++i) {
            queue.enqueue(i);
        }
        state.ResumeTiming();
        
        for (int i = 0; i < state.range(0) && !queue.empty(); ++i) {
            queue.dequeue();
            benchmark::DoNotOptimize(queue);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_QueueDequeue)->Range(1<<10, 1<<18)->Complexity();

// Tree Benchmarks
static void BM_TreeInsert(benchmark::State& state) {
    dsa::Tree<int> tree;
    for (auto _ : state) {
        tree.insert(1);
        benchmark::DoNotOptimize(tree);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_TreeInsert)->Range(1<<10, 1<<18)->Complexity();

static void BM_TreeRemove(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::Tree<int> tree;
        for (int i = 0; i < state.range(0); ++i) {
            tree.insert(i);
        }
        state.ResumeTiming();
        
        for (int i = 0; i < state.range(0); ++i) {
            tree.remove(i);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_TreeRemove)->Range(1<<10, 1<<18)->Complexity();

// Graph Benchmarks
static void BM_GraphAddVertex(benchmark::State& state) {
    dsa::Graph<int> graph;
    for (auto _ : state) {
        graph.addVertex(1);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_GraphAddVertex)->Range(1<<10, 1<<18)->Complexity();

static void BM_GraphAddEdge(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::Graph<int> graph;
        int vertex_count = std::min(static_cast<int>(state.range(0)), 1000);
        for (int i = 0; i < vertex_count; ++i) {
            graph.addVertex(i);
        }
        state.ResumeTiming();
        
        for (int i = 0; i < vertex_count - 1; ++i) {
            graph.addEdge(i, i + 1);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_GraphAddEdge)->Range(1<<10, 1<<18)->Complexity();

// HashMap Benchmarks
static void BM_HashMapInsert(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::HashMap<int, int> map;
        state.ResumeTiming();
        
        map.insert(1, 1);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_HashMapInsert)->Range(1<<10, 1<<18)->Complexity();

static void BM_HashMapRemove(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        dsa::HashMap<int, int> map;
        for (int i = 0; i < state.range(0); ++i) {
            map.insert(i, i);
        }
        state.ResumeTiming();
        
        for (int i = 0; i < state.range(0); ++i) {
            map.remove(i);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_HashMapRemove)->Range(1<<10, 1<<18)->Complexity();

BENCHMARK_MAIN(); 