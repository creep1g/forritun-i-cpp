
int get_number_helper(){
    return 12;
}

double add_two_numbers(double a, double b){
    return a + b;
}

int *get_count_list(int first, int amount){
    int *arr = new int[amount];
    for(int i = 0; i < amount; i++){
        arr[i] = first + i;
    }
    return arr;
}



#include "Python.h"

PyObject* get_number_from_cpp(PyObject *self, PyObject* args){
    return Py_BuildValue("i", get_number_helper());
}

PyObject* get_string_from_cpp(PyObject *self, PyObject* args){
    return Py_BuildValue("s", "This is the string from C++");
}

PyObject* add_two_cpp_doubles(PyObject *self, PyObject* args){
    double a, b;
    if (!PyArg_ParseTuple(args,"dd",&a, &b))
        return NULL;
    double result = add_two_numbers(a, b);

    return Py_BuildValue("d", result);
}

PyObject* get_list_from_cpp(PyObject *self, PyObject* args){
    return Py_BuildValue("[d, s, i, d, d, s]", 25.3, "strengur 1", 12, 0.4, 0.75, "Finished!");
}

PyObject* get_count_from_number(PyObject *self, PyObject* args){
    int first, amount;
    if (!PyArg_ParseTuple(args,"ii",&first, &amount))
        return NULL;
    int *result_list = get_count_list(first, amount);

    
    PyObject *python_list = PyList_New(amount);

    for(int i = 0; i < amount; i++){
        PyList_SetItem(python_list, i, Py_BuildValue("i", result_list[i]));
    }

    delete[] result_list;

    return python_list;
}



static PyMethodDef mainMethods[] = {
 {"get_number_from_cpp",get_number_from_cpp,METH_VARARGS,"Returns a number"},
 {"get_string_from_cpp",get_string_from_cpp,METH_VARARGS,"Returns a string"},
 {"add_two_cpp_doubles",add_two_cpp_doubles,METH_VARARGS,"Returns the sum of two double values"},
 {"get_list_from_cpp",get_list_from_cpp,METH_VARARGS,"Returns a list of hardcoded stuff"},
 {"get_count_from_number",get_count_from_number,METH_VARARGS,"Returns int count list from first og size amount"},
 {NULL,NULL,0,NULL}
};

static PyModuleDef my_cpp_module = {
 PyModuleDef_HEAD_INIT,
 "my_cpp_module","Extension with operations for testing",
 -1,
 mainMethods
};

PyMODINIT_FUNC PyInit_my_cpp_module(void){
    return PyModule_Create(&my_cpp_module);
}
