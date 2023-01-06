#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}
// следмим, чтобы назавние модуля совпадало с тем, что в import! 
PYBIND11_MODULE(summa, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");
}