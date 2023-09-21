#requires]
#sfml/2.6.0
#[generators]
#cmake
#[options]
#sfml:graphics=True
#sfml:window=True
#sfml:audio=True
#sfml:network=True

from conans import ConanFile,CMake

class Example(ConanFile):
    name = "Example"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"
    requires = [("brotli/1.1.0"),("sfml/2.6.0")]
