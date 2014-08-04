import os

BUILD_DIR = 'build'
INCLUDE_PATH = ['#include', 'D:/usr/include']

env = Environment()

env.Append(CPPPATH=INCLUDE_PATH)

if env['PLATFORM'] == 'win32':
    env.Append(CCFLAGS='/EHsc')

def builder_unit_test(target, source, env):
    app = str(source[0].abspath)
    if os.spawnl(os.P_WAIT, app, app)==0:
        open(str(target[0]),'w').write("PASSED\n")
    else:
        return 1

# Create a builder for tests
bld = Builder(action = builder_unit_test)
env.Append(BUILDERS = {'Test' :  bld})

# Make our construction environment available to the SConscripts
Export('env')

def descend(dir):
	sconscript = os.path.join(dir, 'SConscript')
	variant_dir = os.path.join(BUILD_DIR, dir)
	SConscript(sconscript, variant_dir=variant_dir, duplicate=0)

descend('src/dvn')
descend('src/hello')
descend('tests/dvn')
