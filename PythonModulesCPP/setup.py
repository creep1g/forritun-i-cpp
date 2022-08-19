from distutils.core import setup, Extension

my_cpp_module = Extension('my_cpp_module',sources = ['my_python_module.cpp'])
setup(name = 'MyCPPModule',version='1.0',description = 'This is a dumb module',ext_modules = [my_cpp_module])