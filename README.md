# CPP Project Template with CMake

Include
* googletest
* spdlog


Download
```bash
$ git clone --recursive https://github.com/ppd0523/cpp-template.git
```

Build
```bash
$ cd cpp-templete
$ mkdir build
$ cmake -DCMAKE_BUILD_TYPE=Debug .. # debug build
# $ cmake -DCMAKE_BUILD_TYPE=Release -DGTEST=OFF .. # release build
$ make
```


