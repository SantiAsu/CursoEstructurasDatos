cmake_minimum_required(VERSION 3.30)
project(CursoEstructurasDatos)

set(CMAKE_CXX_STANDARD 26)

add_executable(CursoEstructurasDatos main.cpp
        Punteros.cpp
        ArreglosYListas.cpp
        Pilas.cpp
        Queues.cpp
        ProblemaPilas_01.cpp
        ProblemaColas_01.cpp
        arbolBinario.cpp
        GrafosSinDireccion.cpp
        CiclosGrafos.cpp
        BFS.cpp
        Dijikstra.cpp
        "Bellman-Ford .cpp"
        Fijuras.cpp
        Krustal.cpp
        CursoParte2/Heaps01.cpp)
