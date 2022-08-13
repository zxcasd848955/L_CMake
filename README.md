# L_CMake

learning of CMake; tutorial from CMake offical


## valgrind

## clang-format

C++ code formatter,(include: LLVM, Google, Chromium, Mozilla, WebKit .etc)
documentation: `https://clang.llvm.org/docs/ClangFormat.html`
install: `brew install clang-format` on Mac OS; 

### use in command console

`--style=file`; `-i override source file`
`clang-format -style=Google -dump-config > .clang-format`

### use in Vim / other editors(such as: jetbrains)

see example of official site

### use in git

format patch, cv before commit;

## clang-tidy

static check tool, using check rule(`https://clang.llvm.org/extra/clang-tidy/checks/list.html`)

code refactor, codegen

see documentation: `https://clang.llvm.org/extra/clang-tidy/`

