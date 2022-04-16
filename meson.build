project('sleepyc', 'c', default_options: ['c_std=c11'])

include_paths = [
	'include/',
]

source_paths = [
	'src/memory/alloc/allocate.c',
	'src/memory/alloc/free.c',
	'src/memory/alloc/region.c',
	'src/memory/misc.c',
	'src/number/misc.c',
	'src/number/string.c',
	'src/string/buffer.c',
	'src/string/format.c',
	'src/string/number.c',
	'src/string/misc.c',
]

platform = get_option('platform')
if platform == 'linux'
	include_paths += [
		'platform/linux/include/',
	]

	source_paths += [
		'platform/linux/src/memory/alloc/allocate.c',
		'platform/linux/src/memory/alloc/free.c',
	]
endif

sleepyc_include = include_directories(include_paths)
sleepyc_lib = static_library(
	meson.project_name(),
	source_paths,
	include_directories: sleepyc_include,
	c_args: [
		'-nostdlib',
		'-ffreestanding',
		'-U_FORTIFY_SOURCE',
		'-D_DEFAULT_SOURCE',
	],
)

sleepyc_dep = declare_dependency(link_with: sleepyc_lib, include_directories: sleepyc_include)

### test stuff ###

if get_option('test')
	unity_dep = subproject('unity').get_variable('unity_dep')

	test('StringFormat', executable(
		'test_StringFormat',
		'test/string/format.c',
		dependencies: [ unity_dep, sleepyc_dep ],
	))
endif
