FROM gsitcia/ndless-sdk
USER root
RUN chown -R root:root /ndless-sdk

FROM gitpod/workspace-full:latest
COPY --from=0 /ndless-sdk/ndless-sdk /ndless-sdk
USER root
RUN chown -R gitpod:gitpod /ndless-sdk
RUN apt-get update \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
