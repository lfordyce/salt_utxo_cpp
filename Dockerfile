FROM centos:latest as cpp_build_base

# Update the image with the latest packages (recommended)
RUN yum -y update && yum clean all

# Update image
RUN yum install -y gcc gcc-c++ make git cmake autoconf libtool libatomic pkg-config unzip curl wget which

# CMake update:
RUN mkdir -p /tmp/cmake && \
    pushd /tmp/cmake && \
    wget 'https://cmake.org/files/v3.16/cmake-3.16.6-Linux-x86_64.sh' && \
    bash cmake-3.16.6-Linux-x86_64.sh --prefix=/usr/local --exclude-subdir && \
    popd && \
    rm -rf /tmp/cmake

## Intermediate Stage
FROM cpp_build_base AS service_build

ADD . /service

WORKDIR /service/utility

RUN chmod +x /service/utility/install-oatpp-modules.sh
RUN ./install-oatpp-modules.sh

WORKDIR /service/build

RUN cmake ..
RUN make

### Final Stage
FROM centos:latest

WORKDIR /opt/ott_keylib
RUN yum -y update && yum clean all
RUN yum install -y libatomic

COPY --from=service_build /service/build/ott_keylib ./
EXPOSE 7000 7000
ENTRYPOINT ["./ott_keylib"]
