#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

//#include <pybind11/stl.h>
namespace py = pybind11;

double vecsum3(py::array_t<double> v) {
    auto r = v.unchecked<1>();
    return r(0)+r(1)+r(2);
}

double vecsum(py::array_t<double> v) {
    auto r = v.unchecked<1>(); // 1 размерность
    py::ssize_t n = r.shape(0);
    double s=0;
    for (py::ssize_t i=0; i<n; i++) {
       s += r(i)*r(i); // r(i,j) если 2D
    }
    return s;
}

double vecsump(py::array_t<double> v) {
    py::buffer_info buf = v.request();
    if (buf.ndim != 1)
        throw std::runtime_error("Number of dimensions must be one");

    double *p = static_cast<double *>(buf.ptr); // массив
    auto n = buf.size;

    double s=0;
    for (auto i=0; i<n; i++) {
       s += p[i]*p[i];
    }
    return s;
}


// следмим, чтобы назавние модуля совпадало с тем, что в import! 
PYBIND11_MODULE(sumnp, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("vecsum3", &vecsum3, "A function that adds 3 numbers from array");
    m.def("vecsum", &vecsum, "A function that gets the sum of all numbers");
    m.def("vecsump", &vecsump, "A function that gets the sum of all numbers using pointers");
}