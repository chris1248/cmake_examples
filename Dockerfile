FROM registry.redhat.io/ubi8/dotnet-31 as TOSBuild
ARG configuration=Debug
USER root
# Add compilers so cmake will work.
RUN yum install gcc gcc-c++ make cmake -y
RUN yum install glibc-langpack-en glibc-locale-source -y
ADD . /opt/code
WORKDIR /opt/code
ENTRYPOINT [ "bash" ]