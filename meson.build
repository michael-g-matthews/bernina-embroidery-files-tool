project('BerninaEmbroideryFilesTool',
    'cpp',
    default_options: [
        'cpp_std=c++17',
    ],
    license: 'LGPL-3.0-or-later',
    meson_version: '>=1.0.0',
    version: '0.0.1'

)


qt6 = import('qt6')
qt6_dep = dependency('qt6',
    modules: [
        'Core',
        'Gui',
        'Widgets'
    ]
)

inc = include_directories('include')
src = files(
    'src/mainwindow.cpp',
    'src/main.cpp'
)

executable('BerninaTool',
    src,
    include_directories: inc,
    dependencies: [
        qt6_dep,
    ]
)