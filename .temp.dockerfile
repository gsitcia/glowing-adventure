FROM gitpod/workspace-full:latest
COPY --from=gsitcia/my-first-repo /ndless-sdk /ndless-sdk
USER root
RUN apt-get update \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
