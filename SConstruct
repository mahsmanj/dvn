import os

BUILD_DIR = 'build'
INCLUDE_PATH = ['#include', 'D:/usr/include']

env = Environment()

env.Append(CPPPATH=INCLUDE_PATH)
env.Append(CCFLAGS='/EHsc')

Export('env')

SConscript('src/dvn/SConscript', variant_dir=os.path.join(BUILD_DIR, 'src/dvn'), duplicate=0)
SConscript('src/hello/SConscript', variant_dir=os.path.join(BUILD_DIR, 'src/hello'), duplicate=0)
SConscript('tests/dvn/SConscript', variant_dir=os.path.join(BUILD_DIR, 'tests/dvn'), duplicate=0)
