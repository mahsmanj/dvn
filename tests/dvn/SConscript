Import('env')

tests_dvn = env.Program(
    target='tests_dvn',
    source=Glob('*.cpp'),
    LIBS=['dvn', 'gtest'],
    LIBPATH=['#lib', 'D:/usr/lib'])

tests_alias = env.Test('tests_passed', tests_dvn)
