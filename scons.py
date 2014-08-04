import os
import config

def builder_test(target, source, env):
    app = str(source[0].abspath)
    if os.spawnl(os.P_WAIT, app, app)==0:
        open(str(target[0]),'w').write("PASSED\n")
    else:
        return 1

def descend(env, path):
	sconscript = os.path.join(path, config.BUILD_FILE)
	variant_dir = os.path.join(config.BUILD_DIR, path)
	env.SConscript(sconscript, variant_dir=variant_dir, duplicate=0)

def environment(env):
    env.Append(CPPPATH=config.INCLUDE_PATH)

    # Create a builder for tests
    test_builder = env.Builder(action=builder_test)
    builders = {'Test' : test_builder}
    env.Append(BUILDERS=builders)

    # Make our construction environment available to the other build scripts
    env.Export('env')

    return env
