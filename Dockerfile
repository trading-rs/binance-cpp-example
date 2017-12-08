FROM zjhsdtc/binance-cpp:latest

RUN mkdir /main
WORKDIR /main
ADD . /main
RUN mv /app/* ./binance-cpp

RUN RUNTIME=DOCKER ./build.sh
