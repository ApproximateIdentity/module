import os
from setuptools import setup, Extension

DISTNAME = 'module'

PACKAGES = ['module']

SOURCES = [os.path.join("module", "module.c")]
EXTRA_COMPILE_ARGS = ['-g', '-std=c99']

MYMODULE = Extension(
    'module.module',
    sources=SOURCES,
    extra_compile_args=EXTRA_COMPILE_ARGS)

setup(
    name=DISTNAME,
    packages=PACKAGES,
    ext_modules = [MYMODULE])
