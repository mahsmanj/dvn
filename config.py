warning = '''
WARNING: user.py does not exist. This is used to define machine-specific
configuration and is probably necessary for you to create. Copy user.py.example
to user.py and populate it with your configuration.
'''

try:
    with open('user.py') as config_file:
        pass
    import user
except IOError:
    print(warning)
    user = object()

def get_default(name, default):
    if hasattr(user, name):
        return getattr(user, name)
    else:
        return default

def get_extend(name, default_list):
    if hasattr(user, name):
        result = getattr(user, name)
        result.extend(default_list)
        return result
    else:
        return default_list

BUILD_DIR = get_default('BUILD_DIR', 'build')

BUILD_FILE = get_default('BUILD_FILE', 'build.py')

INCLUDE_PATH = get_extend('INCLUDE_PATH', ['#include'])
