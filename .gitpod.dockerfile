FROM ndless/ndless-sdk:latest
USER root
RUN chown -R root:root /ndless-sdk

FROM gitpod/workspace-full:latest
USER root
RUN mkdir /ndless-sdk
COPY --from=0 /ndless-sdk /ndless-sdk
RUN chown -R gitpod:gitpod /ndless-sdk
RUN apt-get update \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev python2.7-dev libboost-program-options1.55.0 \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
    && ln -s /usr/lib/x86_64-linux-gnu/libmpfr.so.6.0.1 /usr/lib/x86_64-linux-gnu/libmpfr.so.4 \
    && ln -s /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.55.0 /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.54.0
