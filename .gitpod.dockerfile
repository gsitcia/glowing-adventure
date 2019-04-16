FROM ndless/ndless-sdk:latest
USER root
RUN chown -R root:root /ndless-sdk

FROM gitpod/workspace-full:latest
USER root
RUN mkdir /ndless-sdk
COPY --from=0 /ndless-sdk /ndless-sdk
RUN chown -R gitpod:gitpod /ndless-sdk
RUN apt-get update \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev python2.7-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
    && ln -s /usr/lib/x86_64-linux-gnu/libmpfr.so.6.0.1 /usr/lib/x86_64-linux-gnu/libmpfr.so.4
RUN wget http://mirrors.kernel.org/ubuntu/pool/main/b/boost1.54/libboost-program-options1.54.0_1.54.0-4ubuntu3_amd64.deb \
    && dpkg -i libboost-program-options1.54.0_1.54.0-4ubuntu3_amd64.deb \
    && rm libboost-program-options1.54.0_1.54.0-4ubuntu3_amd64.deb
