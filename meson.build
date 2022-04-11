project('sleepyc', 'c', default_options: ['c_std=c11'])
add_global_arguments('-U_FORTIFY_SOURCE', language: 'c')

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
	],
)
