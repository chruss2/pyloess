#!/usr/bin/env python
__author__ = "Pierre GF Gerard-Marchant ($Author$)"
__version__ = '1.0'
__revision__ = "$Revision$"
__date__     = '$Date$'

import os
import sys
from os.path import join
from distutils.util import get_platform

def configuration(parent_package='',top_path=None):
    from numpy.distutils.misc_util import Configuration
    from numpy.distutils.system_info import get_info, dict_append
    confgr = Configuration('pyloess',parent_package,top_path)
    # Configuration of LOWESS
    confgr.add_extension('_lowess',
                         sources=[join('src', 'f_lowess.pyf'),
                                  join('src', 'lowess.f'),]
                         )
    # Configuration of STL
    confgr.add_extension('_stl',
                         sources=[join('src', 'f_stl.pyf'),
                                  join('src', 'stl.f')],
                         )
    # Configuration of LOESS
    build_info = {
        'f2py_options': ['--verbose', '-L/usr/lib', '-lblas']
    }
    f_sources = ('loessf.f', 'linpack_lite.f')
    confgr.add_library('floess',
                       sources = [join('src',x) for x in f_sources],
                       **build_info)

    blas_info = get_info('blas_opt')
    build_info = {}
    dict_append(build_info, **blas_info)
    dict_append(build_info, libraries=['floess'])

    # Shared library doesn't link properly when -lfloess refers to a
    # static library (.a file).  No errors at link time, but ldd shows
    # that it loads only core libraries.  Maybe a bug in gfortran???
    # Or a bug in distutils that chooses gfortran as the linker???
    # It works when I specify the .a file directly without using -l.
    temp_dir = "temp.%s-%s" % (get_platform(), sys.version[0:3])
    floess_archive = join('build', temp_dir, 'libfloess.a')
    dict_append(build_info, extra_objects=[floess_archive])

    c_sources = ['loess.c', 'loessc.c', 'misc.c', 'predict.c',]
    confgr.add_extension('_loess',
                         sources=[join('src','_loess.c')] + \
                                 [join('src', x) for x in c_sources],
                         depends = [join('src','*.h'),
                                    join('src','*.pyx'),
                                    join('src','*.pxd')
                                    ],
                         **build_info
                        )
    confgr.add_extension('_mloess',
                         sources=[join('src','_mloess.c')] + \
                                 [join('src', x) for x in c_sources],
                         depends = [join('src','*.h'),
                                    join('src','*.pyx'),
                                    join('src','*.pxd')
                                    ],
                         **build_info
                        )
    confgr.add_data_dir('tests')
    return confgr

if __name__ == "__main__":
    from numpy.distutils.core import setup
    config = configuration(top_path='').todict()
    setup(**config)
