project('Engine', 'cpp', default_options : ['cpp_std=c++17'])

cpp = meson.get_compiler('cpp')

sdlDep = dependency('sdl2')
sdlImgDep = dependency('sdl2_image')
glmDep = dependency('glm')


sources = files('main.cpp')


subdir('src/Utility/Timer')
subdir('src/Image/stb_image')
subdir('src/Image')
subdir('src/Window')
subdir('src/Engine')
subdir('src/Audio')
subdir('src/Renderer')

executable('main', sources, dependencies: [sdlDep, glmDep]) #cpp_args: ['-pg'], link_args: ['-pg'])
