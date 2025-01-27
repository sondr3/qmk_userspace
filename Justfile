set dotenv-load

default: dev

clang:
    @echo "Configuring clang for $KEYBOARD"
    qmk generate-compilation-database -kb $KEYBOARD -km mine
    qmk compile --compiledb -kb $KEYBOARD -km mine

dev:
    @echo "Building $KEYBOARD"
    qmk lint -kb $KEYBOARD -km mine --strict
    qmk compile -kb $KEYBOARD -km mine

flash:
    @echo "Flashing $KEYBOARD"
    qmk flash -kb $KEYBOARD -km mine


build:
    qmk userspace-compile

json:
    @echo "Building JSON info for $KEYBOARD"
    qmk info -kb $KEYBOARD -f json > info/$KEYBOARD_NAME.info.json
    qmk c2json -kb $KEYBOARD -km mine --no-cpp > info/$KEYBOARD_NAME.json
