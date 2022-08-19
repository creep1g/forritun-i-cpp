#include <iostream>
#include "Python.h"

PyObject* get_digit_count_for_integers(PyObject *self, PyObject* args){
  std::cout << args << std::endl;  
  //TODO: Do something else :)
    return args;
}

static PyMethodDef mainMethods[] = {
 {"get_digit_count_for_integers",get_digit_count_for_integers,METH_VARARGS,"Return list with digit counts of integers in parameter list"},
 {NULL,NULL,0,NULL}
};

static PyModuleDef digit_count_module = {
 PyModuleDef_HEAD_INIT,
 "digit_count_module","Extension with operations for list lengths",
 -1,
 mainMethods
};

PyMODINIT_FUNC PyInit_digit_count_module(void){
    return PyModule_Create(&digit_count_module);
}
