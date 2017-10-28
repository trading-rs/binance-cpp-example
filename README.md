## Getting Started

### Installation

```bash
git submodule update --init --recursive
cd binance-cpp
./script/pre-install.sh # it will take a relatively long time to build dependencies
./script/build.sh && ./script/test.sh # optional, just to check everything is fine
```

### Setup authorization

```bash
export BINANCE_API_KEY="<api_key>"
export BINANCE_API_SECRET="<secret_key>"
```

### Build and Run

```bash
./build.sh # to build the example project
./build/main # run the example executable
```
