Import('env')

lib = env.Library(
	target='dvn',
	source=Glob('*.cpp'),
	CPPDEFINES=['_DVN_EXPORTING'])

Install('#lib', lib)
