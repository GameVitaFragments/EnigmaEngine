project('Engine', 'cpp', default_options : ['cpp_std=c++17'])

cpp = meson.get_compiler('cpp')

sdlDep = dependency('sdl2')
sdlImgDep = dependency('sdl2_image')
# glmDep = dependency('glm')
log_sp = subproject('FragLogger')
logDep = log_sp.get_variable('lib_log_dep')



sources = files('main.cpp')

# subdir('./FragLogger')
subdir('src/Entity')
subdir('src/Components/Transform')
subdir('src/Components/Sprite')
subdir('src/Utility/Timer')
subdir('src/Image/stb_image')
subdir('src/Image')
subdir('src/Window')
subdir('src/Engine')
subdir('src/Audio')
subdir('src/Renderer')

#for now I have named submodules static link as lib
#need to update it to libs and check for multiple libs support with single var
executable('main', sources, dependencies: [sdlDep, logDep])#,link_with:lib) #cpp_args: ['-pg'], link_args: ['-pg'])
