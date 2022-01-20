#include <pybind11/pybind11.h>

#include "StringStuff.h"
#include <iostream>

int add(int i, int j) {
    std::string s;
    s = stringstuff::regexReplace("[[:space:]]+", "_", s);
    std::cout << "test" << std::endl;
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
}
