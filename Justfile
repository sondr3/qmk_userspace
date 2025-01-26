default: dev

clang:
    qmk generate-compilation-database -kb zsa/voyager -km mine
    qmk compile --compiledb -kb zsa/voyager -km mine

dev:
    qmk lint -kb zsa/voyager -km mine --strict
    qmk compile -kb zsa/voyager -km mine

build:
    qmk userspace-compile
