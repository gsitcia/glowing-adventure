FROM ndless/ndless-sdk:latest
USER root
# fix weird gid/uid issue
RUN chown -R root:root /ndless-sdk

FROM gitpod/workspace-full:latest
USER root
RUN mkdir /ndless-sdk
# copy compiled stuff
COPY --from=0 /ndless-sdk /ndless-sdk
# make it so we can run it normally
RUN chown -R gitpod:gitpod /ndless-sdk
# install dependencies
RUN apt-get update \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev python2.7-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
    && ln -s /usr/lib/x86_64-linux-gnu/libmpfr.so.6.0.1 /usr/lib/x86_64-linux-gnu/libmpfr.so.4
# manually install this dependency (because it's out of date)
RUN wget -q http://mirrors.kernel.org/ubuntu/pool/main/b/boost1.54/libboost-program-options1.54.0_1.54.0-4ubuntu3_amd64.deb \
    && dpkg -i libboost-program-options1.54.0_1.54.0-4ubuntu3_amd64.deb \
    && rm libboost-program-options1.54.0_1.54.0-4ubuntu3_amd64.deb
# testing includes/clangd stuff
RUN cp /ndless-sdk/include/libndls.h /usr/include