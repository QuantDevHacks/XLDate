FROM gcc:latest
RUN wget https://github.com/Kitware/CMake/releases/download/v3.20.1/cmake-3.20.1-linux-x86_64.tar.gz && \
    tar -xf cmake-3.20.1-linux-x86_64.tar.gz
COPY ./Dates /src/Dates/
COPY ./DateTests /src/DateTests/
COPY Main01.cpp /src/
COPY CMakeLists.txt /src/
RUN /cmake-3.20.1-linux-x86_64/bin/cmake -S /src -B /build && cd /build && make
CMD /build/XLDateMain