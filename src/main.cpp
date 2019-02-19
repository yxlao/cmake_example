#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

int add(int i, int j)
{
    return i + j;
}

void dummy_caller(const std::function<bool(int *)> &func, int *val)
{
    std::cout << "inside dummy_caller" << std::endl;
    std::cout << "val " << *val << std::endl;
    func(val);
}

namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m)
{
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: cmake_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.def("dummy_callback", &dummy_caller);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
