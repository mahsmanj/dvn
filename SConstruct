import scons

# Create and initialize the construction environment
env = scons.environment(Environment())

# Prevent warning when compiling with MSVC
if env['PLATFORM'] == 'win32':
    env.Append(CCFLAGS='/EHsc')

# Generate build targets
scons.descend(env, 'src/dvn')
scons.descend(env, 'src/hello')
scons.descend(env, 'test/dvn')
