If on Adroit, load the appropriate module first
```
source setup_adroit
```

To build with cmake:
```
mkdir build
cd build
cmake ..
make
```

Every example can be built without cmake, for instance:
```
g++ -std=c++11 patriot.cpp -o patriot
```
