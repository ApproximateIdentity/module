import os
from setuptools import setup, Extension


MODULE_EXT = Extension(
    'module.module',
    sources=[os.path.join("module", "module.cpp")],
    libraries=['fast_print'],
    extra_compile_args=['-g', '-std=c++1y'],
    language='c++')

setup(
    name='module',
    packages=['module'],
    ext_modules = [MODULE_EXT])
