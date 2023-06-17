project('Engine', 'cpp')

cpp = meson.get_compiler('cpp')

sdlDep = dependency('SDL2')

sources = files('main.cpp')

subdir('src/frameWork/sdl/render/ui')
subdir('src/frameWork/sdl/sound/music')
subdir('src/frameWork/sdl/render')
subdir('src/frameWork')
subdir('src/frameWork/sdl')
subdir('src/frameWork/sdl/window')
subdir('src/frameWork/sdl/log')

# subdir('lib/linux/vec')
# # vecDep = cpp.find_library('vec', dirs : join_paths(meson.source_root(), 'lib', 'linux', 'vec'))
# 
# links = [
#   vecLib
#   ]

executable('main', sources, dependencies: sdlDep)
