from distutils.core import setup, Extension

digit_count_module = Extension('digit_count_module',sources = ['digit_count_module.cpp'])
setup(name = 'DigitCountModule',version='1.0',description = 'This is a dumb module',ext_modules = [digit_count_module])
